#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	private:
		T	*_values;
		unsigned int	_size;
	public:
		Array()
		{
			_values = NULL;
		}

		Array(unsigned int n):_size(n), _values(new T[n])
		{
		}

		Array(Array<T> &copy)
		{
			this->_values = new T[copy.getLen()];
			for (int i =0; i < copy.getLen(); i++)
				this->_values[i] = copy.getValue(i);
		}
		
		Array<T> &operator=(const Array<T> copy)
		{
			if (*this == copy)
				return (*this);
			for (int i =0; i < copy.getLen(); i++)
				this->_values[i] = copy.getValue(i);
			return (*this);
		}

		T	operator[](unsigned int i)
		{
			if (i > this->_size)
				throw (ArrayOutOfBoundException());
			return (this->_values[i]);
		}

		unsigned int getLen()
		{
			return (this->_size);
		}

		T	size(unsigned int i) const
		{
			return (this->_size);
		}


	class ArrayOutOfBoundException: std::exception
	{
		virtual const char * what() throw
		{
			return ("index out of bound");
		}
	}
};

#endif