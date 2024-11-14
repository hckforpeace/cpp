#include "Base.hpp"

Base*	generate(void);
void identify(Base* p);
void identify(Base& p);

int	main()
{
	Base *c = generate();

	identify(*c);
	identify(c);
	return (0);
}