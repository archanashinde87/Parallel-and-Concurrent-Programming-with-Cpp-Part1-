// MutualExclusionDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<thread>
#include<chrono>
#include<mutex>

unsigned int garlic_count{ 0 };
std::mutex pencil;

void shopper()
{
	for (int i = 0; i < 5; i++)
	{
		printf("Shopper %d is thinking...\n", std::this_thread::get_id());
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		pencil.lock();
		garlic_count++;
		pencil.unlock();

	}
}
int main()
{
	std::thread shanky(shopper);
	std::thread archana(shopper);

	shanky.join();
	archana.join();
	printf("We should buy %u garlic.\n", garlic_count);

	return 0;
}

