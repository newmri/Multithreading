#include <iostream>
#include <thread>
#include <vector>

static const int32_t MAX_NUMBER = 100'000;

int32_t NUMBER = 0;
int32_t THREAD_COUNT = 3;

void Increment(void)
{
	for (int32_t i = 0; i < MAX_NUMBER; ++i)
		++NUMBER;
}

int main(void)
{
	std::vector<std::thread> threads;

	for (int32_t i = 0; i < THREAD_COUNT; ++i)
	{
		threads.emplace_back(Increment);
	}

	for (auto& d : threads)
		d.join();

	std::cout << "Expect: " << THREAD_COUNT * MAX_NUMBER << std::endl;
	std::cout << "Result: " << NUMBER << std::endl;

	return 0;
}