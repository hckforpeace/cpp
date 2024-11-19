#include "iter.hpp"
#include <iostream>

template <typename S>
void	decrement(S &i)
{
	i--;
};

void	add_s(std::string &s)
{
	s = s + "s";
}

void	increment(int &i)
{
	i++;
}

void	display(std::string const &str)
{
	std::cout << str << std::endl;
}

int	main(void)
{
	// adds the "s" to the end of all strings in the array
	std::string s[3] = {"hello", "wolrd", "Pierre"};
	iter(s, 3, add_s);
	for (int i = 0; i < 3; i++)
		std::cout << s[i] << std::endl;

	std::cout << std::endl << std::string(40, '*') << std::endl;

	// increment the value of each integer by one

	int tab[5] = {1, 2, 3, 4, 5};

	iter(tab, 5, increment);
	for (int i = 0; i < 5; i++)
		std::cout << tab[i] << std::endl;

	std::cout << std::endl << std::string(40, '*') << std::endl;

	// decrement the value of each integer by one the function decrement is definied in Another template 
	iter(tab, 5, decrement);
	for (int i = 0; i < 5; i++)
		std::cout << tab[i] << std::endl;
	return (0);

}


/* #include <iostream>
#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

#include <vector>

int main()
{
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print<const int> );
	iter( tab2, 5, print<Awesome> );

	return 0;
} */