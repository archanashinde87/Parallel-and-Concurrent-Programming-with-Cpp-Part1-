// AbandonedLockDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <thread>
#include<mutex>

int sushi_count{ 5000 };

void philosopher(std::mutex & chopsticks)
{
	while (sushi_count > 0)
	{
		std::scoped_lock lock(chopsticks); // It will release lock automatically once it goes out of scope.
		if (sushi_count)
			sushi_count--;
		if (sushi_count == 10)
		{
			printf("This philosopher has had enough!\n");
			break;
		}
	}
}
int main()
{
	std::mutex chopsticks;
	std::thread shanky(philosopher, std::ref(chopsticks));
	std::thread archana(philosopher, std::ref(chopsticks));

	shanky.join();
	archana.join();
	printf("The philosophers are done eating.\n");
	return 0;
}
