// A shared variable is modified by multiple threads
// Use a mutex to prevent a data race
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

std::mutex mut;
int counter = 0;

void task()
{
    for (int i = 0; i < 100'000; ++i) {
		std::lock_guard<std::mutex> lck_guard(mut);
        ++counter;
	}
}

int main()
{
    std::vector<std::thread> tasks;

    for (int i = 0; i < 10; ++i)
        tasks.push_back(std::thread(task));

    for (auto& thr: tasks)
        thr.join();

    std::cout << counter << '\n';
}
