NAME=Span

SRC= main.cpp Span.cpp

OBJ= $(SRC:.cpp=.o)

CXX= c++

CXXFLAGS= -Wall -Werror -Wextra

all:$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
