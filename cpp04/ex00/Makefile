NAME= ANIMAL

SRC= main.cpp Cat.cpp Dog.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp

copy= $(SRC:.cpp=.o)

CXX=c++

CXXFLAGS= -Wall -Werror -Wextra -std=c++98

STD= -std=c++98

all:$(NAME)

$(NAME): $(copy)
	$(CXX) $(CXXFLAGS) $(STD) $^ -o $@

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(STD) -c $< -o $@

clean:
	rm -f $(copy)

fclean: clean
	rm -f $(NAME)

re: fclean all
