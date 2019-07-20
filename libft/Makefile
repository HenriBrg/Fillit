# Très bonne explication des Makefile :

# 	https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean
# 	https://stackoverflow.com/questions/54854128/use-of-o-c-in-makefile

NAME = libft.a

SRCS =	ft_atoi.c              ft_putnbr.c            ft_strncmp.c   \
				ft_bzero.c             ft_putnbr_fd.c         ft_strncpy.c   \
				ft_isalnum.c           ft_putstr.c            ft_strnequ.c   \
				ft_isalpha.c           ft_putstr_fd.c         ft_strnew.c    \
				ft_isascii.c           ft_strcat.c            ft_strnstr.c   \
				ft_isdigit.c           ft_strchr.c            ft_strrchr.c   \
				ft_isprint.c           ft_strclr.c            ft_strsplit.c  \
				ft_itoa.c              ft_strcmp.c            ft_strstr.c    \
				ft_memalloc.c          ft_strcpy.c            ft_strsub.c    \
				ft_memccpy.c           ft_strdel.c            ft_strtrim.c   \
				ft_memchr.c            ft_strdup.c            ft_tolower.c   \
				ft_memcmp.c            ft_strequ.c            ft_toupper.c   \
				ft_memcpy.c            ft_striter.c						ft_putchar.c	 \
				ft_memdel.c            ft_striteri.c					ft_lstadd.c		 \
				ft_memmove.c           ft_strjoin.c						ft_lstdel.c	   \
				ft_memset.c            ft_strlcat.c						ft_lstdelone.c \
				ft_putchar_fd.c        ft_strmap.c						ft_lstiter.c	 \
				ft_putendl.c           ft_strmapi.c						ft_lstmap.c		 \
				ft_putendl_fd.c        ft_strncat.c           ft_lstnew.c		 \
				ft_strlen.c						 ft_strndup.c           							 \
				ft_get_next_line.c		 ft_split_by_size.c



OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	gcc $(CFLAGS) -c $< -o $@

# On passe dans .c.o pour chaque fichier de OBJS
# $< prend la première dépendances, par exemple :
# $@ prend la cible

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
