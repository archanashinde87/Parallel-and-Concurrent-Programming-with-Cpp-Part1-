// ThreadLifeCycleDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <thread>
#include <chrono>

void chef_archana()
{
	printf("Archana started & waiting for sausage to thaw...\n");
	std::this_thread::sleep_for(std::chrono::seconds(3));
	printf("Archana is done cutting sausage.\n");
}
int main()
{
	printf("Shanky requests Archana's help.\n");
	std::thread archana(chef_archana);
	printf("  Archana is joinable? %s\n", archana.joinable() ? "true" : "false");


	printf("Shanky continues cooking soup.\n");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	printf("  Archana is joinable? %s\n", archana.joinable() ? "true" : "false");


	printf("Shanky patiently waits for Archana to finish and join...\n");
	archana.join();
	printf("  Archana is joinable? %s\n", archana.joinable() ? "true" : "false");

	printf("Shanky and Archana are both done!\n");

	return 0;

}

