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
		Fixed&	operator=(Fixed const& obj);

		// static member fucntions
		static			Fixed& min(Fixed& obj1, Fixed& obj2);
		static const	Fixed& min(const Fixed& obj1, const Fixed& obj2);
		static			Fixed& max(Fixed& obj1, Fixed& obj2);
		static const	Fixed& max(const Fixed& obj1, const Fixed& obj2);

		// comparison opertors
		bool	operator<(Fixed const& obj) const;
		bool	operator>(Fixed const& obj) const;
		bool	operator<=(Fixed const& obj) const;
		bool	operator>=(Fixed const& obj) const;
		bool	operator==(Fixed const& obj) const;
		bool	operator!=(Fixed const& obj) const;
		
		// Arithmetic operators
		Fixed	operator+(Fixed const& obj) const;
		Fixed	operator-(Fixed const& obj) const;
		Fixed	operator*(Fixed const& obj) const;
		Fixed	operator/(Fixed const& obj) const;
		
		// Pre increment ++ operator
		Fixed	operator++();
		
		// Post increment ++ operator
		Fixed	operator++ (int);
		
		// Pre increment -- operator
		Fixed	operator--();
		
		// Post increment -- operator
		Fixed	operator-- (int);
};

#endif