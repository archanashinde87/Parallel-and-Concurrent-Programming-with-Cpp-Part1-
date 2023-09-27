// DeadlockDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<thread>
#include<mutex>

int sushi_count{ 5000 };

void philosopher(std::mutex & first_chopstick, std::mutex & second_chopstick)
{
    while (sushi_count > 0)
    {
        /*first_chopstick.lock();
        second_chopstick.lock();*/
        std::scoped_lock lock(first_chopstick, second_chopstick);   //2.one more way to fix deadlock issue
        sushi_count--;
        /*second_chopstick.unlock();
        first_chopstick.unlock();*/
    }
}
int main()
{
    std::mutex chopstick_a, chopstick_b;
    std::thread shanky(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread archana(philosopher, std::ref(chopstick_b), std::ref(chopstick_a)); // Deadlock situation

    // 1.fix order of locks on mutex resolves deadlock 
   // std::thread archana(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));

    shanky.join();
    archana.join();
    printf("The philosophers are done eating.\n");
    return 0;

}
