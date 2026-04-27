NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = main.c	\
	   helper_functions.c \
	   set_up/initializing_data.c \
	   set_up/initializing_philo.c \
	   simulation/eating.c \
	   simulation/end_simulation.c \
	   simulation/one_philo.c \
	   simulation/sleeping.c \
	   simulation/start_simulation.c \
	   simulation/thinking.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
