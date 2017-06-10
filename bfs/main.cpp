#include <cstdio>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

FILE * is = fopen("bfs.in", "r" );
ofstream os("bfs.out");

int n, m, s;
bitset<100001> b;
vector<vector<int> > G;
vector<int> c;
queue<pair<int, int> > Q;

void Read();
void Bfs(int x);
void Write();

int main()
{
    Read();
    Bfs(s);
    Write();
    fclose(is);
    os.close();
    return 0;
}
void Read()
{
    int x, y;
    fscanf(is, "%d%d%d", &n, &m, &s );

    G.resize(n+1);
    c.resize(n+1, -1);

    while ( m-- )
    {
        fscanf(is, "%d%d", &x, &y);
        G[x].push_back(y);
    }
}
void Bfs(int x)
{
    int cost;
    b[x] = true;
    c[x] = 0;
    Q.push(make_pair(x, 0));
    while (!Q.empty() )
    {
        x = Q.front().first;
        cost = Q.front().second;
        c[x] = cost;
        Q.pop();
        for ( const auto & v : G[x] )
            if ( !b[v] )
            {
                b[v] = true;
                Q.push(make_pair(v, cost+1));
            }
    }

}
void Write()
{
    for ( int i = 1; i <= n; ++i )
        os << c[i] << ' ';
}
