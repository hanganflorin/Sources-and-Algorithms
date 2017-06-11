#include <fstream>
#include <queue>
using namespace std;

ifstream is("lant.in");
ofstream os("lant.out");

int a[21][21], n, m, p, q, x, y;
void Df(int k, int p);
void Bf(int x);
bool v[21];
int X[21];

int main()
{
    is >> n >> m;
    while ( m-- )
    {
        is >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    is >> p >> q;
    v[p] = true;
    Df(1, p);
    is.close();
    os.close();
    return 0;
}
void Df(int k, int p)
{
    X[k] = p;
    if ( p == q )
    {
        for ( int i = 1; i <= k; ++i )
            os << X[i] << ' ';
        os << '\n';
    }
    for ( int i = 1; i <= n; ++i )
        if ( !v[i] && a[p][i] )
        {
            v[i] = true;
            Df(k+1, i);
            v[i] = false;
        }
}
