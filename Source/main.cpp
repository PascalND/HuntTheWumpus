#include "HuntTheWumpus.h"
#include "RandomGeneratorImpl.h"
#include <locale>

int main()
{
    std::locale::global(std::locale("de_DE"));

    HtW::RandomGeneratorImpl random;
	
	//TODO instantiate your random number generator here and replace nullptr
	HtW::HuntTheWumpus app(&random);
	app.Run();
	return 0;
}
