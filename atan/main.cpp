#include <iostream>
#include<cmath>
using namespace std;

double x;

int main()
{
    while ( true )
    {
        cin >> x;
        x = atan(x);
        x *= 180;
        x /= 3.1415;
        cout << x << '\n';
    }

    return 0;
}
