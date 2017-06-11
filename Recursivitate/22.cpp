#include<iostream>
using namespace std;

int F(int i);

int main()
{
    cout << F(100);
    return 0;
}
int F(int n)
{
    if ( n == 0 ) return 0;
    return (F(n-1) + n*(n+1));

}
