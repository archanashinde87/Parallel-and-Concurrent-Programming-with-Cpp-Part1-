// AtomicObjectDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <atomic>
#include<thread>

using namespace std;

atomic<unsigned int> garlic_count{ 0 };
void shopper()
{
	for (int i = 0; i < 10000000; i++)
		garlic_count++;
}
int main()
{
	thread archana(shopper);
	thread shanky(shopper);

	archana.join();
	shanky.join();
	printf("We should buy %u garlic.\n", garlic_count.load());
	return 0;
}
