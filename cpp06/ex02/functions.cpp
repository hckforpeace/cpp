#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base*		createA()
{
	return (new A());
}
Base*		createB()
{
	return (new B());

}
Base*		createC()
{
	return (new C());
}

Base*	generate(void)
{
	Base* (*f[3])(void) =
	{
		&createA,
		&createB,
		&createC
	};
	srand(time(0));
	int i = rand() % 3;
	return (f[i]());
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a)
		std::cout << "A" << std::endl;
	B* b = dynamic_cast<B*>(p);
	if (b)
		std::cout << "B" << std::endl;
	C* c = dynamic_cast<C*>(p);
	if (c)
		std::cout << "C" << std::endl;
}

void identify(Base& r)
{
	try
	{
		A& a = dynamic_cast<A&>(r);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		B& b = dynamic_cast<B&>(r);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	
	try
	{
		C& c = dynamic_cast<C&>(r);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
}