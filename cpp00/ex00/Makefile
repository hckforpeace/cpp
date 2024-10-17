SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

COMP= c++

COMP_FLAGS= -Wall -Wextra -Werror

NAME=megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(COMP_FLAGS) $^ -o $@

%.o:%.c
	$(COMP) -c $(COMP_FLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all