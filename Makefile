NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c	\
	   helper_functions.c \
	   set_up/intializing_data.c \
	   set_up/intializing_philo.c \
	   simulation/eating.c \
	   simulation/end_simulation.c \
	   simulation/one_philo.c \
	   simulation/sleeping.c \
	   simulation/start_simulation.c \
	   simulation/thinking.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all
