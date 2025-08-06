#include <iostream>

using namespace std;

class Multiply
{
    
public:
    int multiply(int a,int b)
    {
        return a * b;
    }

    int multiplyByTen(int a)
    {
        return multiply(a,10);
    }


};


int main()
{

    Multiply multi;
    // Call the method multiplyByTen with 5 as the argument
    // This is equivalent to a.multiplyByTen(5)
    cout << multi.multiplyByTen(5)<< endl; // Output: 50
    
    return 0;
}