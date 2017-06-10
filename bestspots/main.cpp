#include <fstream>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("bestspots.in");
ofstream os("bestspots.out");

int n, m, F, f[501], a[501][501], s, mn = INF, nr;
void Read();
void FW();

int main()
{
    Read();
    FW();
    for ( int i = 1; i <= n; ++i )
    {
        s = 0;
        for ( int k = 1; k <= F; ++k )
            s += a[i][f[k]];
        if ( s < mn )
        {
            mn = s;
            nr = i;
        }
    }
    os << nr;
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> F >> m;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            if ( i != j )
                a[i][j] = INF;
    for ( int i = 1; i <= F; ++i )
        is >> f[i];
    for ( int i = 1, x, y, timp; i <= m; ++i )
    {
        is >> x >> y >> timp;
        a[x][y] = timp;
        a[y][x] = timp;
    }
}
void FW()
{
    for ( int k = 1; k <= n; ++k )
        for ( int i = 1; i <= n; ++i )
            for ( int j = 1; j <= n; ++j )
                if ( i != j )
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j] );
}
