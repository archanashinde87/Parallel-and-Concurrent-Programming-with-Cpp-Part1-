// RecursiveMutexDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include<mutex>

using namespace std;

unsigned int garlic_count;
unsigned int potato_count;

mutex pencil;

void add_garlic()
{
	pencil.lock();
	garlic_count++;
	pencil.unlock();
}

void add_potato()
{
	pencil.lock();
	potato_count++;
	add_garlic();
	pencil.unlock();
}

void shopper()
{
	for (int i{ 0 }; i < 10000; i++)
	{
		add_potato();
		add_garlic();
	}
}
int main()
{
	thread shanky(shopper);
	thread archana(shopper);

	shanky.join();
	archana.join();

	printf("We should buy %u garlic.\n",garlic_count);
	printf("We should buy %u potato.\n", potato_count);

	return 0;
}
