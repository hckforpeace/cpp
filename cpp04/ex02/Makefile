NAME= ANIMAL

SRC= main.cpp Cat.cpp Dog.cpp Animal.cpp Brain.cpp

OBJ= $(SRC:.cpp=.o)

CC=c++

# CFLAGS= -Wall -Werror -Wextra

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
