#include <iostream>
#include <thread>
#include <vector>
#include <string>

static const int32_t MAX_PLAY = 20;

class Player
{
public:
	Player(const char* name) : name(name) {}

public:
	void Play(const int32_t number)
	{
		std::cout << this->name << " says ";

		bool fizz = 0 == number % 3;
		bool buzz = 0 == number % 5;

		if (fizz && buzz)
			std::cout << "fizzbuzz!";
		else if (fizz)
			std::cout << "fizz!";
		else if (buzz)
			std::cout << "buzz!";
		else
			std::cout << number;

		std::cout << std::endl;
	}

private:
	std::string name;
};

std::vector<Player> Players{ "Abdul", "Bart", "Claudia", "Divya" };


void Play(void)
{
	for (int32_t i = 0; i < MAX_PLAY; ++i)
		Players[(i - 1) % Players.size()].Play(i);
}

int main(void)
{
	int k = 0;
	std::thread game{ Play };
	game.join();

	return 0;
}