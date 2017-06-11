#include <fstream>
#include <cmath>
#include <climits>
using namespace std;

ifstream is("taste.in");
ofstream os("taste.out");

void Read();
int Cal(int a, int b );

struct {
    int i, j;
} c[10];

int x, nr, max_cal = INT_MAX, max_h, max_m;

int main()
{
    Read();
    for ( int h = x / 100; h < 100; h += 24 )
        for ( int m = x % 100; m < 100; m += 60 )
        {
            nr = Cal(h/10, h%10) + Cal(h%10, m/10) + Cal(m/10, m%10);
            if ( nr < max_cal )
            {
                max_cal = nr;
                max_h = h;
                max_m = m;
            }

        }
    os << max_cal << '\n';
    if ( max_h < 10 )
        os << '0';
    os << max_h;
    if ( max_m < 10 )
        os << '0';
    os << max_m;
    is.close();
    os.close();
    return 0;
}

void Read()
{
    for ( int i = 0; i < 10; ++i )
        is >> c[i].i >> c[i].j;
    is >> x;
}
int Cal(int a, int b )
{
    return ( abs(c[a].i - c[b].i) + abs(c[a].j - c[b].j) );

}
