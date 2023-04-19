#include "../include/Fibonacci.h"
#include <atomic>
#include <bits/chrono.h>
#include <chrono>
#include <stdexcept>
#include <string>
using namespace std::chrono;


unsigned int Fibonacci::fib_r(int n, time_point<steady_clock> startTime, int maxSeconds)
{
    if(n <= 2)
        return 1;

    int elapsedSeconds = duration<double>(steady_clock::now() - startTime).count();
    if(elapsedSeconds >= maxSeconds)
    {
        
        throw std::runtime_error("Timed out after " + std::to_string(elapsedSeconds) + " seconds of runtime");
    }
    
    return fib_r(n-1, startTime, maxSeconds) + fib_r(n-2, startTime, maxSeconds);
}

unsigned int Fibonacci::fib_i(int n, time_point<steady_clock> startTime, int maxSeconds)
{
    unsigned int fibonacciNumbers[n+1];
    fibonacciNumbers[1] = 1;
    fibonacciNumbers[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        int elapsedSeconds = duration<double>(steady_clock::now() - startTime).count();
        if(elapsedSeconds >= maxSeconds)
            throw std::runtime_error("Timed out after " + std::to_string(elapsedSeconds) + " seconds of runtime");
        fibonacciNumbers[i] = fibonacciNumbers[i-1] + fibonacciNumbers[i-2];
    }
    return fibonacciNumbers[n];
}

unsigned int Fibonacci::fib_i_three(int n, time_point<steady_clock> startTime, int maxSeconds)
{
    unsigned int nMinusOne = 1;
    unsigned int nMinusTwo = 1;
    for(int i = 3; i <= n; i++)
    {
        int elapsedSeconds = duration<double>(steady_clock::now() - startTime).count();
        if(elapsedSeconds >= maxSeconds)
            throw std::runtime_error("Timed out after " + std::to_string(elapsedSeconds) + " seconds of runtime");
        unsigned int result = nMinusOne + nMinusTwo;
        nMinusTwo = nMinusOne;
        nMinusOne = result;
    }
    return nMinusOne;
}