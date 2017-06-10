#include <iostream>
using namespace std;

int n, x, nr;
int Cifra(int x);

int main()
{
    cin >> n >> x;
    for ( int i = 1; nr < n; ++i )
        if ( Cifra(i) == x )
        {
            cout << i << ' ';
            nr++;
        }
    return 0;
}
int Cifra(int x)
{
    int s = 0;
    if ( x < 10 ) return x;
    while ( x )
    {
        s += x%10;
        x /= 10;
    }
    return Cifra(s);
}
