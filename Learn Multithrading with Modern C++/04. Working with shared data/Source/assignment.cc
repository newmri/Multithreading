#include <thread>
#include <mutex>

int x{ 0 };
std::mutex mutex;

void func() {
	std::lock_guard<std::mutex> lck_guard(mutex);

	while (x == 0) {
		x = 1 - x;
	}
}

int main()
{
	std::thread thr1{ func };
	std::thread thr2{ func };

	thr1.join();
	thr2.join();
}

