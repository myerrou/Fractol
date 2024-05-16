NAME = fractol

SRCS = Fractol.c Utils.c Drawing.c Events.c Mondatory_sets.c Burning_ship.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

$(NAME): $(OBJS)
	cc $(CFLAGS) -os -lmlx -framework Appkit -framework OpenGl $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

build: re
		make clean
		clear

.SECONDARY: $(OBJS)
