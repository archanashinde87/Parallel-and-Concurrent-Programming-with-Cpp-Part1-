// LiveLockDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex& first_chopstick, std::mutex& second_chopstick) {
    while (sushi_count > 0) 
    {
        first_chopstick.lock();
        if (!second_chopstick.try_lock()) 
        {
            first_chopstick.unlock();
            std::this_thread::yield();
        }
        else
        {
            if (sushi_count) 
            {
                sushi_count--;
            }
            second_chopstick.unlock();
            first_chopstick.unlock();
        }
    }
}

int main() {
    std::mutex chopstick_a, chopstick_b;
    std::thread shanky(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread archana(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    std::thread yugan(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread aadya(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    shanky.join();
    archana.join();
    yugan.join();
    aadya.join();
    printf("The philosophers are done eating.\n");
}