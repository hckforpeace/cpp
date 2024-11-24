NAME=btc
# BitcoinExchange.cpp
SRC= main.cpp BitcoinExchange.cpp

OBJ= $(SRC:.cpp=.o)

CXX= c++

CXXFLAFGS= -Wall -Werror -Wextra

STD= -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAFGS) $(STD) $^ -o $@

%.o:%.cpp
	$(CXX) $(CXXFLAFGS) $(STD) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all