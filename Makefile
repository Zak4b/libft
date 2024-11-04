NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SOURCES = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strncmp.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strdup.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_substr.c

OBJS = $(SOURCES:.c=.o)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all