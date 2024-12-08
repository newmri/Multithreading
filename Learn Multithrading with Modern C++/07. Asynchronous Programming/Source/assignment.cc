#include <iostream>
#include <thread>
#include <future>
#include <mutex>

void task1(int32_t num1, int32_t num2, std::promise<int32_t>&& promise)
{
	promise.set_value(num1 + num2);
}

void task2(std::future<int32_t>&& future)
{
	std::cout << "Result: " << future.get() << std::endl;
}

int main()
{
	std::promise<int32_t> promise;
	std::future<int32_t> future = promise.get_future();

	std::thread t1(task1, 1, 1, std::move(promise));
	std::thread t2(task2, std::move(future));

	t1.join();
	t2.join();
}