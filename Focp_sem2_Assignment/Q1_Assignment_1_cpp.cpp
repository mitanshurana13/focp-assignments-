/*  Q) Take a input of a positive integer and check whether it is prime or not, 
if not prime enter all its factors and also print the next prime number. */

#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "\nEnter a number: ";
    cin >> num;
    if (num <= 0)
    { 
        cout << "Invalid number. Please enter a positive integer.\n";
        return 0;
    }

    // Check if the number is prime
    bool isPrime = true;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {   isPrime = false;
            break;
        }
    }
    if (isPrime && num > 1)
    { cout << "The number " << num << " is a prime number.\n"; 
    } else {
        cout << "The number " << num << " is not a prime number.\n";
        cout << "The factors of " << num << " are: ";
        for (int i = 1; i <= num / 2; i++)
        {    if (num % i == 0)    {
                cout << i << " ";
            }
        } cout << num << "\n";
    }

    // Finding the next prime number after the entered number

    int next = num + 1;
    while (true)
    {    bool isNextPrime = true;
            for (int i = 2; i <= next / 2; i++) {
            if (next % i == 0)
            { isNextPrime = false;
                break; }
    }
        if (isNextPrime)
        {   cout << "The next prime number after " << num << " is " << next << "\n";
            break; }
        next++;
        }
        
        return 0;
}