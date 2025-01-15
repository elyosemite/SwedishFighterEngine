#include <iostream>
#include <thread>
#include <mutex>

#include "../../include/concurrency/concurrency.h"

namespace Concurrency
{
    Thams::Thams() : counter(0) {}

    void Thams::Increment()
    {
        for (int i = 0; i < 1_000_000; ++i)
        {
            //std::lock_guard<std::mutex> lock(mtx);
            ++counter;
        }
    }

    void Thams::Foo()
    {
        //std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Counter Value: " << counter << std::endl;
    }
}
