#include <fstream>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("ghiozdan.in");
ofstream os("ghiozdan.out");
void Scrie(int x);

int n, g, x, a[75001], p[75001], nr;

int main()
{
    is >> n >> g;
    for ( int i = 1; i <= g; ++i )
        a[i] = INF;
    for ( int i = 0; i < n; ++i )
    {
        is >> x;
        for ( int j = g-x; j>= 0; --j )
        {
            if ( a[j+x] > a[j] + 1 )
            {
                a[j+x] = a[j] + 1;
                p[j+x] = j;
            }
        }
    }
    nr = g;
    while ( a[nr] == INF )
        nr--;
    os << nr << ' ' << a[nr] << '\n';
    Scrie(nr);
    is.close();
    os.close();
    return 0;
}
void Scrie(int x)
{
    if ( x == 0 ) return;
    Scrie(p[x]);
    os << x - p[x] << '\n';
}
