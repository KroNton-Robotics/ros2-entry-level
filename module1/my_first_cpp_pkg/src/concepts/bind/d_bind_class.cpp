#include <iostream>
#include <functional>


class Multiply
{
    
public:

    int multiply(int a,int b)
    {
        return a * b;
    }


};

int main()
{
    Multiply multi;
    
    auto callbackMethod= std::bind(&Multiply::multiply,multi,10,std::placeholders::_1);

    std::cout << callbackMethod(5)<< std::endl; // Output: 50
    
    return 0;
}