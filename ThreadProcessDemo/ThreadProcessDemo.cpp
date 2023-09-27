// ThreadProcessDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void cpu_waster()
{
	cout << "CPU WASTER Process ID : " << _getpid() << '\n';
	cout << "CPU WASTER Thread ID : " << std::this_thread::get_id() << '\n';
	while (true)
		continue;
}
int main()
{
	cout << "Main Process ID : " << _getpid() << '\n';
	cout << "Main Thread ID : " << std::this_thread::get_id() << '\n';

	thread thread1(cpu_waster);
	thread thread2(cpu_waster);

	// Keep the main thread alive forever
	while (true)
		std::this_thread::sleep_for(std::chrono::seconds(1));

	return 0;
}
