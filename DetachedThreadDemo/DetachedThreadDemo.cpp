// DetachedThreadDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<thread>
#include<chrono>

using namespace std;
void kitchen_cleaner()
{
    while (true)
    {
        printf("Archana cleaned the kitchen\n");
        this_thread::sleep_for(chrono::seconds(1));
    }
}
int main()
{
    thread archana(kitchen_cleaner);
    archana.detach();   // permits the thread to execute independently from the thread handle(main thread in this case)
    for (int i = 0; i < 3; i++)
    {
        printf("Shanky is cooking...\n");
        this_thread::sleep_for(chrono::milliseconds(600));
    }

    printf("Shanky is done!\n");
    return 0;

}

