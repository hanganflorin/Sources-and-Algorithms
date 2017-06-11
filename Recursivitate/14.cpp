#include<iostream>
using namespace std;

int F(int n);

int main()
{
    cout << F(323456789);
    return 0;
}
int F(int n)
{
    if ( n < 10 ) return n;
    return F(n/10);
}
