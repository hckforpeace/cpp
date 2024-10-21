_name=ScavTrap

SRC= main.cpp ClapTrap.cpp ScavTrap.cpp

OBJ = $(SRC:.cpp=.o)

CC=c++

CFLAGS= -Wall -Werror -Wextra

all: $(_name)

$(_name): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(_name)

re:	fclean all