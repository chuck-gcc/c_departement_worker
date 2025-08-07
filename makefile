CC= cc
NAME= woker
GFLAGS= -Werror -Wall -Wextra -pthread 
SRC_MAIN= $(wildcard *.c)
OBJS_MAIN = $(SRC_MAIN: %.c=%.o) 

%.o:%.c
	$(CC) $(GFLAGS)  -g -c $< -o $@


$(NAME): $(OBJS_MAIN)
	$(CC) $(GFLAGS) $(OBJS_MAIN) -o $(NAME)

run: 
	./$(NAME)

clean:
	rm -f *.o

fclean: clean
	rm $(NAME)
