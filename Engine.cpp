#include <iostream>
#include <thread>

#include <concurrency/concurrency.h>

int main()
{
	Concurrency::Thams thams;
	
	std::thread t1(&Concurrency::Thams::Increment, &thams);
	std::thread t2(&Concurrency::Thams::Increment, &thams);

	t1.join();
	t2.join();

	thams.Foo();
	
	return 0;
}
