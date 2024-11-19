#ifndef ITER_HPP
#define ITER_HPP


template <typename T>
void iter(T *arr, int len, void f(T&))
{
	if (!arr || !f)
		return ;
	for (int i = 0; i < len; i++)
			f(arr[i]);	
};

template <typename T>
void iter(T const *arr, int len, void f(T const &))
{
	if (!arr || !f)
		return ;
	for (int i = 0; i < len; i++)
		f(arr[i]);	
};

#endif