#include<iostream>
#include<math.h>
using namespace std;

int F(int n, int x );

int main()
{
    cout << F(123456789, 0);
    return 0;
}
int F(int n, int x )
{
    if ( n == 0 ) return x;
    return F(n/10, x*10 + (n%10) );
}
