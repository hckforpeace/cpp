NAME= humans

SRC= HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

OBJ= $(SRC:.cpp=.o)

CC= c++

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
