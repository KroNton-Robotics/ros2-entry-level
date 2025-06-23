#include <iostream>
#include <functional>


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
    auto callbackMethod= std::bind(&A::multiplyByTen,a,std::placeholders::_1);
    std::cout << callbackMethod(5)<< std::endl; // Output: 50
    
    return 0;
}