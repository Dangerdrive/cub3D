MAKEFLAGS	+=	--no-print-directory

NAME	:=	cub3d
CC		:=	cc
LIBMLX	:=	./MLX42
CFLAGS	:=	-Wextra -Wall -Wunreachable-code -g -Ofast -I./include -I$(LIBMLX)/include/MLX42
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

#flags para Windows 11 (precisa testar)
ifeq ($(OS),Windows_NT)
    LDFLAGS :=	-lglfw3 -lopengl32 -lgdi32 -L$(LIBMLX)/build
endif

LEAKS	:=	valgrind --leak-check=full --show-leak-kinds=all --suppressions=./MLX42/suppress.sup ./fractol mandelbrot

SRCS	:=	src/main.c src/vectors.c

OBJDIR	:=	obj
OBJS	:=	$(SRCS:src/%.c=$(OBJDIR)/%.o)

.PHONY:	all clean fclean re valgrind run prebuild

bonus:	all

valgrind:	all
	@$(LEAKS)

all:	prebuild $(NAME)

prebuild:
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

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) -L$(LIBMLX) -lmlx42 $(LDFLAGS)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR) $(NAME)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

run:	all
	@./$(NAME)
