/* #ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array{
	private:
		T	*_tab;
		int	_size;
	public:
		~Array<T>()
		{
			delete[] _tab;
		}
		Array<T>():_tab(0), _size(new T[0]){}
		Array<T>(int n):_tab(new T[n]), _size(n){}
		Array<T>(const Array<T>& copy)
		{
			this->_size = copy.size();
			this->_tab = new T[this->_size];

			for (int i = 0; i < this->_size; i++)
				this->_tab[i] = copy[i];
		}

		T&	operator[](int i)
		{
			if (i > this->size() - 1 || i < 0)
				throw std::out_of_range("out of range");
			else
				return (this->_tab[i]);
		}


		const Array<T>& operator=(const Array<T>& copy)
		{
			if (this == &copy)
				return (*this);
			if (copy.size() == 0)
			{
				this->_size = 0;
				this->_tab = 0;
			}
			else
			{
				this->_size = copy.size();
				this->_tab = new T[this->_size];
				for (int i = 0; i < this->_size; i++)
					this->_tab[i] = copy._tab[i];
			}
			return (*this);
		}

		int	size(void) const
		{
			return (this->_size);
		}
};

#endif */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T	*tab;
	public:
		~Array(){delete[] this->tab;}
		Array<T>():_size(0), tab(new T[0]){}
		Array<T>(unsigned int n):_size(n), tab(new T[n]){}
		Array<T>(const Array<T>& copy)
		{
			this->_size = copy.size();
			this->tab = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->tab[i] = copy.tab[i];
		}

		Array<T>& operator=(const Array<T>& copy)
		{
			if (this == &copy)
				return (*this);
			delete[] tab;
			this->_size = copy.size();
			this->tab = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->tab[i] = copy.tab[i];
			return (*this);
		}


		T& operator[](int i)
		{
			unsigned int index = static_cast<unsigned int>(i);
			if (i < 0 || index >= this->_size)
				throw std::out_of_range("index is out of bound");
			return (this->tab[i]);
		}

		T const & operator[](int i) const
		{
			unsigned int index = static_cast<unsigned int>(i);
			if (i < 0 || index >= this->_size)
				throw std::out_of_range("index is out of bound");
			return (this->tab[i]);
		}

		unsigned int	size(void) const {return (this->_size);}
};

#endif
