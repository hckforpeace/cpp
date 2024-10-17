#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int	value;
		int const static fbits = 8;
	public:
		Fixed( void );
		Fixed( Fixed &fixed );
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		void	operator=(Fixed const& obj);
};

#endif