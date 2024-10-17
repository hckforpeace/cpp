NAME = bank

SRC = Account.cpp tests.cpp

OBJ = $(addprefix src/,$(SRC:.cpp=.o))

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -Iinclude $^ -o $@

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c -Iinclude $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
