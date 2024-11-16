#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
/* int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
     {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
   try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */


// Simple tests
/* int	main()
{
	Array<int> empty;
	// throws excpetion out of bound
	try
	{
		// empty[-1];
		empty[9];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Array fo strings
	Array<std::string> names(3);
	names[0] = "hello";
	names[1] = "Wolrd";
	names[2] = "Pablo";
	for (int i = 0;  i < 3; i++)
	{
		std::cout << names[i] << std::endl;
	}

	std::cout << std::endl << std::string(40, '*') << std::endl;
	// Operators/copy
	Array<std::string> copy = names;
	for (int i = 0;  i < 3; i++)
	{
		std::cout << copy[i] << std::endl;
	}

	std::cout << std::endl << std::string(40, '*') << std::endl;
	Array<std::string> assignement;

	assignement = copy;
	for (int i = 0;  i < 3; i++)
	{
		std::cout << assignement[i] << std::endl;
	}
	return (0);
} */

int	main()
{
	Array<int> tab(40);
	try
	{
		for (int i = 0; i < 40; i++)
		{
			std::cout << i << ": " << tab[i] << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::string(50, '*') << std::endl;

	tab[5] = 8;
	std::cout << "tab[5]: " << tab[5] << std::endl;

	std::cout << std::string(50, '*') << std::endl;

	Array<int> tab1(tab);


	try
	{
		for (int i = 0; i < 40; i++)
			tab1[i] = 34;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		for (int i = 0; i < 40; i++)
			std::cout << i << ": " << tab1[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


/*	try
	{
		for (int i = 0; i < 40; i++)
			std::cout << i << ": " << temp[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	} */

	return(0);
}

/* int 	main()
{
	Array<std::string> shd(4);
	shd[0] = "Hello";
	std::cout << shd[0] << std::endl;
	return (0);
} */