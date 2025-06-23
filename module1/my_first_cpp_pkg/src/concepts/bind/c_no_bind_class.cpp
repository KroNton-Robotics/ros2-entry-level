#include <iostream>

using namespace std;

class A
{
    
public:

    int multiplyByTen(int a)
    {
        return a * 10;
    }


};



int main()
{

    A a;
    // Call the method multiplyByTen with 5 as the argument
    // This is equivalent to a.multiplyByTen(5)
    cout << a.multiplyByTen(5)<< endl; // Output: 50
    
    return 0;
}