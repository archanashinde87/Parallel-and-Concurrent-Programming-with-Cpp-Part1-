// ThreadStarvationDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <thread>
#include <mutex>
#include <array>

unsigned int sushi_count{ 5000 };

void philosopher(std::mutex& chopsticks)
{
	int sushi_eaten = 0;
	while (sushi_count > 0)
	{
		std::scoped_lock lock(chopsticks);
		if (sushi_count)
		{
			sushi_count--;
			sushi_eaten++;
		}
	}
	printf("Philosopher %d ate %d.\n", std::this_thread::get_id(), sushi_eaten);
}

int main()
{
	std::mutex chopsticks;
	std::array<std::thread, 200> philosophers;
	for (int i{ 0 }; i < philosophers.size(); i++)
	{
		philosophers[i] = std::thread(philosopher, std::ref(chopsticks));
	}
	for (int i{ 0 }; i < philosophers.size(); i++)
	{
		philosophers[i].join();
	}
	printf("The philosophers are done eating.\n");
	return 0;

}

