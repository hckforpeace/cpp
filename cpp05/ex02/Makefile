NAME= BUREAUCRAT

SRC= main.cpp Bureaucrat.cpp 

OBJ= $(SRC:.cpp=.o)

CXX=c++

CXXFLAGS= -Wall -Werror -Wextra

STD= -std=c++98

all:$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(STD) $^ -o $@

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(STD) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
