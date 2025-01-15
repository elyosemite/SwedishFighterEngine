#ifndef CONCURRENCY_H
#define CONCURRENCY_H

#include <mutex>
#include <iostream>

namespace Concurrency
{
    class Thams
    {
    private:
        std::mutex mtx;
        int counter;

    public:
        Thams();
        void Increment();
        void Foo();
    };
}

#endif
