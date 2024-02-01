#include "int.h"
#include<iostream>

using std::cout;

int main()
{
    cout<<"Echo: "<<echo_variable(10)<<"\n";

    auto num = 10;

    cout<<"Bytes required to store int: "<<sizeof(num)<<"\n";

    auto decimal = 10.5;

    cout<<"Bytes required to store double: "<<sizeof(decimal)<<"\n";

    auto ch = 'A';

    cout<<"Bytes required to store char: "<<sizeof(ch)<<"\n";

    return 0;
}
