#include <chrono>
#include <type_traits>
using namespace std::chrono;

class Fibonacci
{
public:
    static unsigned int fib_r(int n, time_point<steady_clock> startTime, int maxSeconds);
    static unsigned int fib_i(int n, time_point<steady_clock> startTime, int maxSeconds);
    static unsigned int fib_i_three(int n, time_point<steady_clock> startTime, int maxSeconds);
};