#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter the number of integers: ";
    cin >> num;
    int arr[num];
    cout << "Enter " << num << " integers: " << endl;
    for (int i = 0; i < num; i++)
    {
         cin >> arr[i]; }

    if (num < 2)
    {
        cout << "Array should have at least two elements." << endl;
        return 0;
    }

    int largest, second_largest;
    int smallest, second_smallest;

    if (arr[0] > arr[1])
    {
        largest = arr[0];
        second_largest = arr[1];
    }
    else
    {
        largest = arr[1];
        second_largest = arr[0];
    }

    if (arr[0] < arr[1])
    {
        smallest = arr[0];
        second_smallest = arr[1];
    }
    else
    {
        smallest = arr[1];
        second_smallest = arr[0];
    }

    for (int i = 2; i < num; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }

        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < second_smallest && arr[i] != smallest)
        {
            second_smallest = arr[i];
        }
    }
       
    cout << "Reverse of the Element Entered: " << endl;
    for (int i = num - 1; i >= 0; i--) {
    cout << arr[i] << " ";
    }
    cout << endl;

    if (largest == second_largest)
    {
        cout << "No second largest element found." << endl;
    }
    else
    {
        cout << "The second largest element is " << second_largest << endl;
    }
    if (smallest == second_smallest)
    {
        cout << "No second smallest element found." << endl;
    }
    else
    {
        cout << "The second smallest element is " << second_smallest << endl;
    }
    return 0;
}