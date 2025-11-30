#include <iostream>
#include <cstdlib> //for exit
#include <Windows.h> //for Sleep
using namespace std;

class Timer
{
public:
    // Initializes the seconds, countUp and message to arguments.
    Timer(int secondsValue, bool countUpValue, string messageValue);

    // Resets the timer to a new value of seconds.
    void reset(int newSeconds);

    // Starts the timer and outputs the count and the message.
    void start();
private:
    int seconds;
    bool countUp;
    string message;
};

int main()
{
    Timer timer1(3, true, "Time's up!"); // A timer that counts up to 3 seconds
    Timer timer2(3, false, "Time's up!"); // A timer that counts down from 3 seconds

    cout << "Count Up Test\n-------------\n";
    cout << "Starting 3 second timer...\n";
    timer1.start();

    cout << "\nResetting to 5 seconds\n";
    timer1.reset(5);
    cout << "Starting 5 second timer...\n";
    timer1.start();

    cout << "\nCount Down Test\n---------------\n";
    cout << "Starting 3 second timer...\n";
    timer2.start();

    cout << "\nResetting to 5 seconds\n";
    timer2.reset(5);
    cout << "Starting 5 second timer...\n";
    timer2.start();

    return 0;
}

Timer::Timer(int secondsValue, bool countUpValue, string messageValue)
    : seconds(secondsValue), countUp(countUpValue), message(messageValue)
{
    // Empty
}

void Timer::reset(int newSeconds)
{
    seconds = newSeconds;
}

void Timer::start()
{
    int count = countUp ? 1 : seconds; // Initialize count based on countUp
    int step = countUp ? 1 : -1; // Set step based on countUp

    while (true)
    {
        cout << count << " ";

        if ((countUp && count >= seconds) || (!countUp && count <= 1))
        {
            break; // Exit the loop if count exceeds seconds or becomes negative
        }

        count += step; // Increment or decrement the count
        Sleep(1000);   // Pause for 1 second
    }

    cout << "\n" << message << "\n"; // Output the message
}
