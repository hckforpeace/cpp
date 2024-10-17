#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	value;
		int const static fbits = 8;
	public:
		Fixed( void );
		Fixed( const int value );		
		Fixed( const float value );
		Fixed( Fixed const &fixed );
		~Fixed();
		int		getRawBits( void ) const;
		float	toFloat( void ) const;
		int		toInt( void ) const;
		void	setRawBits( int const raw );
		void	operator=(Fixed const& obj);
};

#endif