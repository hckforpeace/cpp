_name=DiamondTrap

SRC= main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp

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
