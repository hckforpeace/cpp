NAME=PhoneBook

MAIN=main.cpp

SRC=Contact.cpp PhoneBook.cpp

OBJ= $(SRC:.cpp=.o)

CC=c++

CFLAGS= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(MAIN:.cpp=.o)
	$(CC) $(CFLAGS)  $^ -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(MAIN:.cpp=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
