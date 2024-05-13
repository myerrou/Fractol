NAME = Fractol

SRCS = Fractol.c Utils.c Drawing.c Events.c Mondatory_sets.c Burning_ship.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -os -lmlx -framework Appkit -framework OpenGl $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJS)
