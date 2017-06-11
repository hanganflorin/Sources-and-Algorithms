#include <fstream>
#include <cstring>
using namespace std;

ifstream is("kbiti.in");
ofstream os("kbiti.out");

int n, k, nr = 1;
unsigned short a[501][151];
unsigned short b[501][151];

void Adun(unsigned short * a, unsigned short * b );

int main()
{
    is >> n >> k;
    n /= 2;
    a[0][0] = a[0][1] = 1;
    a[1][0] = a[1][1] = 1;
    while ( nr <= n )
    {
        for ( int i = 1; i <= nr; ++i )
        {
            Adun(b[i], a[i] );
            Adun(b[i], a[i-1] );
        }
        memcpy(a, b, sizeof(b) );
        memset(b, 0, sizeof(b));
        a[0][0] = a[0][1] = 1;
        a[nr][0] = a[nr][1] = 1;
        nr++;
    }

    for ( int i = a[k][0]; i > 0; --i )
        os << a[k][i];
    is.close();
    os.close();
    return 0;
}
void Adun(unsigned short * a, unsigned short * b )
{
    int i, t = 0;
    for ( i = 1; i <= a[0] || i <= b[0] || t; ++i, t /= 10 )
    {
        t += a[i] + b[i];
        a[i] = t % 10;
    }
    a[0] = i-1;
}
