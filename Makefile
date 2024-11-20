MAKEFLAGS	+=	--no-print-directory

NAME	:=	cub3d
CC		:=	cc
LIBMLX	:=	./MLX42
LIBFT	:=	./libft/libft.a
CFLAGS	:=	-Wextra -Wall -Wunreachable-code -g -Ofast -I./include -I$(LIBMLX)/include/MLX42 -I./libft

UNAME_S :=	$(shell uname -s)


ifeq ($(UNAME_S),Linux)
	LDFLAGS :=	-ldl -lglfw -pthread -lm -L$(LIBMLX)/build
endif

ifeq ($(UNAME_S),Darwin)
	ifeq ($(shell uname -m),arm64)
		LDFLAGS = -L/opt/homebrew/lib -lglfw -framework IOKit -framework Cocoa -L$(LIBMLX)/build
	else ifeq ($(shell uname -m),x86_64)
		LDFLAGS = -lglfw3 -framework IOKit -framework Cocoa -L$(LIBMLX)/build
	endif
endif

LEAKS	:=	valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./$(NAME) maps/map_sample.cub

SRCS	:=	src/main.c \
			src/raycasting/data.c \
			src/raycasting/vec_basic.c \
			src/raycasting/vec_advanced.c \
			src/raycasting/render.c \
			src/raycasting/render_helper.c \
			src/raycasting/hooks.c \
			src/validations/check_rgb.c \
			src/validations/copy_texture_path.c \
			src/validations/load_map_file.c \
			src/validations/load_map.c \
			src/validations/load_textures_utils.c \
			src/validations/load_textures.c \
			src/validations/replace_map_tabs.c \
			src/validations/validate_args.c \
			src/validations/validate_map_extern_walls.c \
			src/validations/validate_map.c

OBJDIR	:=	obj
OBJS	:=	$(SRCS:src/%.c=$(OBJDIR)/%.o)
DIRS	:=	$(shell dirname $(OBJS))

.PHONY:	all clean fclean re valgrind run prebuild

bonus:	all

valgrind:	all
	@$(LEAKS)

all:	prebuild $(NAME)

prebuild:
	@git submodule update --init --recursive;
	@if [ ! -d "$(LIBMLX)" ]; then \
		echo "Adding MLX42 submodule..."; \
		@git submodule add git@github.com:codam-coding-college/MLX42.git MLX42; \
		@git submodule update --init --recursive; \
	else \
		echo "MLX42 submodule already exists."; \
	fi
	@sed -i "s/(VERSION 3.18.0)/(VERSION 3.16.0)/" ./MLX42/CMakeLists.txt
	@echo "Building MLX42..."
	@cd $(LIBMLX) && cmake -B build && cmake --build build -j4

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) -o $(NAME) -L./libft -lft -L$(LIBMLX)/build -lmlx42 $(LDFLAGS)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@mkdir $(shell dirname $@) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(DIRS) 2> /dev/null

$(LIBFT):
	@make -C ./libft/

clean:
	@rm -rf $(OBJDIR) $(NAME)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

run:	all
	@./$(NAME) maps/map_sample.cub
