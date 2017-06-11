#include<iostream>
using namespace std;

int n, p, mx, baza;
// 405 = 3^4 * 5^1

int main()
{
    cin >> n;
    int i = 2;
    while ( i <= n / 2 )
    {
        p = 0;
        while ( n % i == 0 )
        {
            p++;
            n /= i;
        }
        if ( p )
        {
            cout << i << "^" << p << " * ";
        }
        if ( p > mx )
        {
            mx = p;
            baza = i;
        }
        i++;
    }
    cout << '\n' << baza;
    return 0;
}
