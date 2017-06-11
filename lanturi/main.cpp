#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream is("ciclu.in");
ofstream os("ciclu.out");

int n, m, a[21][21], X[21], p;
bool b[21], ok = true;
vector<int> G[21];

void Df(int k, int x);

int main()
{
    is >> n >> m;
    for ( int i = 0, x, y; i < m; ++i )
    {
        is >> x >> y;
        if ( !a[x][y] )
        {
            a[x][y] = a[y][x] = 1;
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }
    is >> p;
    b[p] = true;
    Df(1, p);
    is.close();
    os.close();
    return 0;
}
void Df(int k, int x)
{
    X[k] = x;
    if ( x == p && k != 1 )
    {
        for ( int i = 1; i <= k; ++i )
            os << X[i] << ' ';
        ok = false;
        return;
    }
    if ( k > n ) return;
    if ( k == 3 ) b[p] = false;
    for ( int i = 0; i < G[x].size() && ok; ++i )
        if ( !b[G[x][i]] )
        {
            b[G[x][i]] = true;
            Df(k+1, G[x][i]);
            b[G[x][i]] = false;
        }
}
