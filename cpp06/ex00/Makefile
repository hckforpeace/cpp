NAME= Convert

SRC= main.cpp ScalarConverter.cpp parse_string.cpp convert.cpp

OBJ= $(SRC:.cpp=.o)

CXX= c++

CXFLAGS= -Wall -Werror -Wextra

STD= -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXFLAGS) $(STD) $^ -o $@

%.o:%.cpp
	$(CXX) -c $(CXFLAGS) $(STD) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all