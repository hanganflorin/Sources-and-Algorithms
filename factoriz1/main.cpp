#include <iostream>
#include <cstring>
using namespace std;
// 405 = 3^4 * 5^1

int n, p, mx, baza;
bool b[299999999];

void Ciur();

int main()
{
    cin >> n;
    int i = 2;
    while ( i <= n )
    {
        p = 0;
        while ( n % i == 0 )
        {
            p++;
            n /= i;
        }
        if ( p )
        {
            cout << i << "^" << p;
            if ( i < n )
                cout << " * ";
        }
        if ( p > mx )
        {
            mx = p;
            baza = i;
        }
        if ( i == 2 )
            i++;
        else
            i += 2;
    }
    cout << '\n' << baza;
    return 0;
}
void Ciur()
{

}
