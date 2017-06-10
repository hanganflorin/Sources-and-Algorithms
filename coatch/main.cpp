#include <fstream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("coatch.in");
ofstream os("coatch.out");

int n, m, t, a[101][101], c[101], mn, mx, aux[101], p1, p2, A[101][101];

void Read();
void FW();
void Write();
void Modifica();

int main()
{
    Read();
    sort(aux, aux+n);
    FW();
    os << p1 << ' ' << p2 << ' ' << mn << ' ' << mx;
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m >> t;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            if ( i != j )
                A[i][j] = INF;
    for ( int i = 1; i <= n; ++i )
    {
        is >> c[i];
        aux[i] = c[i];
    }
    for ( int i = 1, x, y, cst; i <= m; ++i )
    {
        is >> x >> y >> cst;
        A[x][y] = A[y][x] = cst;
    }
}
void FW()
{
    for ( int x = 1; x < n; ++x )
        for ( int y = x+1; y <= n; ++y )
        {
            mn = aux[x];
            mx = aux[y];
            Modifica();
            for ( int k = 1; k <= n; ++k )
                for ( int i = 1; i <= n; ++i )
                    for ( int j = 1; j <= n; ++j )
                        if (i != j &&
                            c[k] >= mn && c[k] <= mx &&
                            c[i] >= mn && c[i] <= mx &&
                            c[j] >= mn && c[j] <= mx)
                        {
                            a[i][j] = min(a[i][j], a[i][k] + a[k][j] );
                            if ( a[i][j] == t )
                            {
                                p1 = i;
                                p2 = j;
                                return;
                            }
                        }

        }

}
void Write()
{
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= n; ++j )
        {
            if ( a[i][j] == INF )
                os << "x ";
            else
                os << a[i][j] << ' ';
        }
        os << '\n';
    }
}
void Modifica()
{
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            a[i][j] = A[i][j];
}
