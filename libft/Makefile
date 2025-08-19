SRC = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isspace.c \
		ft_replace_c.c \
		ft_remove_c.c \
		ft_startswith.c \
		ft_endswith.c \
		ft_insert.c \
		ft_strreplace.c \
		ft_substr_ptr.c \
		ft_freenull.c \
		ft_free_array.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
COMP = cc
AR = ar

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f *.o

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:
	all clean fclean re
