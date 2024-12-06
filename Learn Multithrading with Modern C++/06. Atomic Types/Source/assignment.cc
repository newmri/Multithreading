#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

class some_type {
	// ...
public:
	void do_it();
};

std::atomic<some_type*> ptr = nullptr;
some_type* ptr1 = nullptr;


void some_type::do_it()
{

}



void process() {

	if (!ptr)
	{
		if (!ptr)    // Second check of ptr
			ptr = new some_type;   // Initialize ptr
	}
	ptr1 = ptr;
	ptr1->do_it();
}

int main()
{

	std::vector<std::thread> vec;

	for (int32_t i = 0; i < 16; ++i)
		vec.emplace_back(std::thread(process));

	for (auto& d : vec)
		d.join();

	return 0;
}