#include <iostream>
#include <thread>
#include <fmt/core.h>

#include <concurrency/concurrency.h>

int main()
{
	// Concurrency::Thams thams;
	
	// std::thread t1(&Concurrency::Thams::Increment, &thams);
	// std::thread t2(&Concurrency::Thams::Increment, &thams);

	// t1.join();
	// t2.join();

	// thams.Foo();

	fmt::print("Hello, {}\n", "Thamirys");
	
	return 0;
}
