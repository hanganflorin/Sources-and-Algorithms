#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    cin >> n;
    for ( int i = 1; i <= n; ++i )
    {
        cin >> x;
        j = i-1;
        while ( j > 0 && a[j] > x )
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
    return 0;
}
