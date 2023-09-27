// TryLockDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<thread>
#include<mutex>
#include<chrono>

using namespace std;

unsigned int items_on_notepad{ 0 };
mutex pencil;

void shopper(const char* name)
{
	int items_to_add{ 0 };
	while (items_on_notepad <= 20)
	{
		if (items_to_add && pencil.try_lock()) // add item(s) to shared items_on_notepad
		{
			items_on_notepad += items_to_add;
			printf("%s added %u item(s) to notepad.\n", name, items_to_add);
			items_to_add = 0;
			std::this_thread::sleep_for(std::chrono::milliseconds(300)); // time spent writing
			pencil.unlock();
		}
		else  // look for other things to buy
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100)); // time spent searching
			items_to_add++;
			printf("%s found something else to buy.\n", name);
		}
	}
}
int main()
{
	auto start_time = chrono::steady_clock::now();
	thread shanky(shopper, "Shanky");
	thread archana(shopper, "Archana");
	shanky.join();
	archana.join();
	auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time).count();
	printf("Elapsed Time: %.2f seconds\n", elapsed_time / 1000.0);

	return 0;
}
