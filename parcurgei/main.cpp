#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

ifstream is("dfs.in");
ofstream os("dfs.out");

int n, m, p;
bool b[101];
vector<int> G[101];
queue<int> Q;

void Bf(int x);
void Df(int x);

int main()
{
    is >> n >> m >> p;
    for ( int i = 0, x, y; i < m; ++i )
    {
        is >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for ( int i = 1; i <= n; ++i )
        sort(G[i].begin(), G[i].end());
    b[p] = true;
    Df(p);
    is.close();
    os.close();
    return 0;
}
void Bf(int x)
{
    b[x] = true;
    os << x << ' ';
    Q.push(x);
    while ( !Q.empty() )
    {
        x = Q.front();
        Q.pop();
        for ( int i = 0; i < G[x].size(); ++i )
            if ( !b[G[x][i]] )
            {
                os << G[x][i] << ' ';
                b[G[x][i]] = true;
                Q.push(G[x][i]);
            }
    }
}
void Df(int x)
{
    os << x << ' ';
    b[x] = true;
    for ( int i = 0; i < G[x].size(); ++i )
        if ( !b[G[x][i]] )
            Df(G[x][i]);
}
