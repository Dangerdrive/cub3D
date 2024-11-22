# Name of the library
NAME		=   libft.a

# Directories for source and header files
SRCDIR	  =   .
INCDIR	  =   .
OBJDIR	  =   obj

# Compiler and flags
CC		  =   cc
CFLAGS	  =   -Wall -Wextra -Werror -fPIE -g

# Source files and object files
SRCS		=   $(addprefix $(SRCDIR)/, ft_atoi.c \
				ft_atol.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isblank.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_numlen.c \
				ft_numlen_base.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strarr_cat.c \
				ft_strarr_dup.c \
				ft_strarr_free.c \
				ft_strarr_len.c \
				ft_strarr_ndup.c \
				ft_strarr_sort.c \
				ft_strarr_str_replace.c \
				ft_strarr_str.c \
				ft_strarr_stradd.c \
				ft_strarr_strrm.c \
				ft_strchr.c \
				ft_strchr_i.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strcmp.c \
				ft_strndup.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_uitoa_base.c \
				ft_unumlen_base.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_print_ptr.c \
				ft_print_char.c \
				ft_print_str.c \
				ft_print_hex.c \
				ft_print_unsig.c \
				ft_print_nbr.c \
				ft_printf.c \
				ft_printfd.c )

OBJS		=   $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

B_SRCS	  =   $(addprefix $(SRCDIR)/, ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c)

B_OBJS	  =   $(B_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Formatting
BOLD		=   \033[1m

# Rules
.PHONY:	 all clean fclean re bonus

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)
#			@echo "$(BOLD)✅ Libft created$(NO_FORMAT)"

bonus:	  $(OBJS) $(B_OBJS)
			@ar rc $(NAME) $(B_OBJS)
#			@echo "$(BOLD)✅ Bonus added$(NO_FORMAT)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@mkdir -p $(OBJDIR)
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)
#			@echo "$(BOLD)✔️ Compiling $<$(NO_FORMAT)"

clean:
			@rm -rf $(OBJDIR)
#			@echo "$(BOLD)🗑️  Object files removed$(NO_FORMAT)"

fclean:	 clean
			@rm -f $(NAME)
#			@echo "$(BOLD)🗑️  Libft removed$(NO_FORMAT)"

re:		 fclean all
