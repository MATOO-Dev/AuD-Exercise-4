#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include "include/Fibonacci.h"
#include "include/BinarySearch.h"
#include "include/Exercise15.h"

void Task13_A_R(int maxSeconds)
{
    std::cout << "Running recursive calculations with max " << std::to_string(maxSeconds) << "s/iteration" << std::endl;
    time_point<std::chrono::steady_clock> startTime = std::chrono::steady_clock::now();
    int i = 0;
    while (true) 
    {
        unsigned int result = 0;
        try
        {
            result = Fibonacci::fib_r(i, startTime, maxSeconds);
        }
        catch(std::runtime_error error)
        {

            std::cout << error.what() << std::endl;
            return;
        }
        std::string resultString = "Successfully calculated result " + std::to_string(result) + " ";
        std::string stepString = "for n = " + std::to_string(i) + " ";
        double elapsedDuration = duration<double>(steady_clock::now() - startTime).count();
        std::string durationString = "at " + std::to_string(elapsedDuration) + " seconds";
        std::cout << resultString <<  stepString << durationString << std::endl;
        i++;
    }
}

void Task13_A_I(int maxSeconds)
{
    std::cout << "Running iterative calculations with max " << std::to_string(maxSeconds) << "s/iteration" << std::endl;
    time_point<std::chrono::steady_clock> startTime = std::chrono::steady_clock::now();
    int i = 0;
    while (true) 
    {
        unsigned int result = 0;
        try
        {
            result = Fibonacci::fib_i(i, startTime, maxSeconds);
        }
        catch(std::runtime_error error)
        {
            std::cout << error.what() << std::endl;
            return;
        }
        std::string resultString = "Successfully calculated result " + std::to_string(result) + " ";
        std::string stepString = "for n = " + std::to_string(i) + " ";
        double elapsedDuration = duration<double>(steady_clock::now() - startTime).count();
        std::string durationString = "at " + std::to_string(elapsedDuration) + " seconds";
        std::cout << resultString <<  stepString << durationString << std::endl;
        i++;
    }
}

void Task13_B_I(int maxSeconds)
{
    std::cout << "Running iterative calculations with max " << std::to_string(maxSeconds) << "s/iteration" << std::endl;
    time_point<std::chrono::steady_clock> startTime = std::chrono::steady_clock::now();
    int i = 0;
    while (true) 
    {
        unsigned int result = 0;
        try
        {
            result = Fibonacci::fib_i_three(i, startTime, maxSeconds);
        }
        catch(std::runtime_error error)
        {
            std::cout << error.what() << std::endl;
            return;
        }
        std::string resultString = "Successfully calculated result " + std::to_string(result) + " ";
        std::string stepString = "for n = " + std::to_string(i) + " ";
        double elapsedDuration = duration<double>(steady_clock::now() - startTime).count();
        std::string durationString = "at " + std::to_string(elapsedDuration) + " seconds";
        std::cout << resultString <<  stepString << durationString << std::endl;
        i++;
    }
}

void Task14()
{
    //set random seed
    std::srand(std::time(nullptr));

    //fill vektor of size 100 with random numbers
    Vektor binSearch = Vektor(100);
    for(int i = 0; i < binSearch.size(); i++)
    {
        binSearch.set(i, rand() % 200 - 100);
    }

    //sort vektor and print values to console
    binSearch.quick_sort(0, binSearch.size());
    binSearch.print();

    //search for value
    int searchValue = 35;
    int foundIndex = binSearch.bin_suche(searchValue);

    //display results
    if(foundIndex != -1)
        std::cout << "Found value " << searchValue << " at index " << foundIndex << std::endl;
    else
        std::cout << "Could not find desired value " << searchValue << std::endl;
}

void Task15()
{
    std::cout << "Running recursive" << std::endl;
    for(int i = 1; i <= 10; i++)
        std::cout << "T(" << i << ") = " << Exercise15::T_r(i) << std::endl;

    std::cout << "Running iterative" << std::endl;
    for(int i = 1; i <= 10; i++)
        std::cout << "T(" << i << ") = " << Exercise15::T_i(i) << std::endl;
}

int main()
{
    //13-A-Recursive
    //Task13_A_R(1);
    //Task13_A_R(10);
    //Task13_A_R(60);
    //Time complexity:  O(2*n!) -> O(n!)
    //Space complexity: ?


    //13-A-Iterative
    //Task13_A_I(1);
    //Task13_A_I(10);
    //Task13_A_I(60);
    //Time complexity:  O(n)
    //Space complexity: O(n+1) -> O(n)


    //13-B-Iterative
    //Task13_B_I(1);
    //Task13_B_I(10);
    //Task13_B_I(60);
    //Time complexity: O(n)
    //Space complexity: O(3) -> O(3*1) -> O(1)


    //14-A
    //Task14();

    //14-B
    //worst case: O(log(n))
    //best case: O(1)
    //average case: O(log(n))?


    //15-A/B
    Task15();
    //T(1)=1
    //T(2)=2*1+2=4
    //T(3)=3*4+3=15
    //T(4)=4*15+4=64
    //T(5)=5*64+5=325
    //T(6)=6*325+6=1956
    //T(7)=7*1956+7=13699
    //T(8)=8*13699+8=109600
    //T(9)=9*109600+9=986409
    //T(10)=10*986409+10=9864100

    //15-C
    //O(n)?
    //15-D
    //n-1
    //15-E
    //O(n)?

    return 0;
}