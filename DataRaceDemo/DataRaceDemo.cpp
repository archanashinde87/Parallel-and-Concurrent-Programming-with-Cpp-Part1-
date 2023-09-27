// DataRaceDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <thread>

using namespace std;

unsigned int garlic_count = 0;

void shopper(const char * name)
{
    for (int i = 0; i < 10000000; i++)
    {
        garlic_count++;
    }
}
int main()
{
    thread shanky(shopper, "Shanky");
    thread archana(shopper, "Archana");

    shanky.join();
    archana.join();

    printf("We should buy % u garlic.\n", garlic_count);
    return 0;
}
