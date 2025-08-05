#include <iostream>
#include <functional> // Required for std::bind and std::placeholders

using namespace std;

// Function that multiplies two integers
int multiply(int a, int b)
{
    return a * b;
}

// Alternative function that multiplies by 10 (not used in main)
// int multiplyByTen(int a)
// {
//     return multiply(a, 10);
// }

int main()
{
    // Create a new function that binds the first argument of multiply to 10
    // The second argument will be provided when calling bound_function
    auto bound_function = std::bind(multiply, 10, std::placeholders::_1);
    
    // Call the bound function with 5 as the second argument
    // This is equivalent to multiply(10, 5)
    cout << bound_function(5) << endl; // Output: 50
    
    return 0;
}