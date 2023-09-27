// SharedMutexDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <thread>
#include<mutex>
#include<chrono>
#include<array>
#include<shared_mutex>

using namespace std;

char WEEKDAYS[7][10]{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
int today{ 0 };
shared_mutex marker;

void calender_reader(const int id)
{
	for (int i{ 0 }; i < 7; i++)
	{
		marker.lock_shared();
		printf("Reader-%d sees today is %s\n", id, WEEKDAYS[today]);
		this_thread::sleep_for(chrono::milliseconds(100));
		marker.unlock_shared();
	}
}
void calender_writer(const int id)
{
	for (int i{ 0 }; i < 7; i++)
	{
		marker.lock();
		today = (today+1) % 7;
		printf("Writer-%d updated date to %s\n", id, WEEKDAYS[today]);
		this_thread::sleep_for(chrono::milliseconds(100));
		marker.unlock();

	}
}
int main()
{
	//cretae ten reader threads
	array<thread, 10> readers;
	for (unsigned int i{ 0 }; i < readers.size(); i++)
	{
		readers[i] = thread(calender_reader, i);
	}

	//create 2 writers threads
	array<thread, 2> writers;
	for (unsigned int i{ 0 }; i < writers.size(); i++)
	{
		writers[i] = thread(calender_writer, i);
	}

	// wait for readers and writers to finish
	for (unsigned int i = 0; i < readers.size(); i++) {
		readers[i].join();
	}
	for (unsigned int i = 0; i < writers.size(); i++) {
		writers[i].join();
	}

	return 0;
}

