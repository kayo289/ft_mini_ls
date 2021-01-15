NAME = ft_mini_ls

SRCS = \
	srcs/ft_mini_ls.c \
	srcs/sort.c \

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	${CC} ${FLAGS} -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
