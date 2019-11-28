#include <chrono>
#include <thread>
#include <iostream>
//...
using namespace std::chrono_literals;


//std::chrono::duration<int, std::milli> timespan(1000);
//std::this_thread::sleep_for(timespan);

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 20; ++i)
	{
		std::cout << i << " ";
		std::this_thread::sleep_for(2s);
	}
	return 0;
}
