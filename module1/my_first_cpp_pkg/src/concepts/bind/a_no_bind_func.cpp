#include <iostream>

using namespace std;

// Function that multiplies two integers
int multiply(int a, int b)
{
    return a * b;
}

// Alternative function that multiplies by 10 (not used in main)
int multiplyByTen(int a)
{
    return multiply(a, 10);
}

int main()
{

    
    cout << multiplyByTen(5)<< endl; // Output: 50
    
    return 0;
}