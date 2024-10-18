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
		static Fixed& min(Fixed &obj1, Fixed &obj2);
		const static  Fixed& min(const Fixed &obj1, const Fixed &obj2);
		static Fixed& max(Fixed &obj1, Fixed &obj2);
		const static  Fixed& max(const Fixed &obj1, const Fixed &obj2);
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
		bool	operator<(Fixed const& obj);
		bool	operator>(Fixed const& obj);
		bool	operator<=(Fixed const& obj);
		bool	operator>=(Fixed const& obj);
		bool	operator==(Fixed const& obj);
		bool	operator!=(Fixed const& obj);
		bool	operator+(Fixed const& obj);
		bool	operator-(Fixed const& obj);
		bool	operator*(Fixed const& obj);
		bool	operator/(Fixed const& obj);
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);
};

#endif