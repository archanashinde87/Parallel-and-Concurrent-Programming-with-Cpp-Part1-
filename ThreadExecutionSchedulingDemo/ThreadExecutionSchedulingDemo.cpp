// ThreadExecutionSchedulingDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

using namespace std;

bool chopping = true;

void vegetable_chopper(const char* name)
{
    unsigned int vegetable_count = 0;
    while (chopping)
    {
        vegetable_count++;
    }
    cout << name << " chopped " << vegetable_count << " vegetables.\n";
}
int main()
{
    thread archana(vegetable_chopper, "Archana");
    thread shanky(vegetable_chopper, "Shanky");

    cout << "Archana and Shanky are chopping vegetables....\n";
    this_thread::sleep_for(chrono::seconds(1));
    chopping = false;

    archana.join();
    shanky.join();

    return 0;
}

