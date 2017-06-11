#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int n, m, a[101][101], X[101], aux[101], mn = 200 , p, q, x, y;
bool b[101];
vector<int> G[101];
void Df(int k, int x);

int main()
{
    is >> n >> p >> q;
    while ( is >> x >> y )
    {
        if ( !a[x][y] )
        {
            a[x][y] = a[y][x] = 1;
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }
    Df(1, p);
    os << mn << '\n';
    for ( int i = 1; i <= mn; ++i )
       os << aux[i] << ' ';

    is.close();
    os.close();
    return 0;
}
void Df(int k, int x)
{
    X[k] = x;
    if ( x == q )
    {
        if ( k < mn )
        {
            mn = k;
            for (int i = 1; i <= k; ++i )
                aux[i] = X[i];
        }
        return;
    }
    for ( int i = 0; i < G[x].size(); ++i )
        if ( !b[G[x][i]] )
        {
            b[G[x][i]] = true;
            Df(k+1, G[x][i]);
            b[G[x][i]] = false;
        }
}
