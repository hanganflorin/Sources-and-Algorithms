#include<iostream>
using namespace std;

void F(int n);

int main()
{
    F(123456789);
    return 0;
}
void F(int n)
{
    if ( n == 0 ) return;
    F(n/10);
    cout << n%10 << ' ';
}
