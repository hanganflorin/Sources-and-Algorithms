#include<iostream>
using namespace std;

void F(int n, int i);

int main()
{
    F(5,1);
    return 0;
}
void F(int n, int i)
{
    if ( n == 0 ) return;
    F(n-1, 1);
    if ( i > n )
    {
        cout << '\n';
        return;
    }
    cout << i << ' ';
    F(n, i+1);
}
