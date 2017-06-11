#include<iostream>
using namespace std;

int F(int n);

int main()
{
    cout << F(123456789);
    return 0;
}
int F(int n)
{
    if ( n == 0 ) return 0;
    return F(n/10)+1;
}
