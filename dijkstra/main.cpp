#include <fstream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("dijkstra.in");
ofstream os("dijkstra.out");

int n;
vector<vector<pair<int, int> > > G;
vector<int> d;
queue<int> Q;

void Read();
void Dijkstra(int x);
void Write();

int main()
{
    Read();
    Dijkstra(1);
    Write();
    /*
    for ( int i = 1; i <= n; ++i )
    {
        os << i << ": ";
        for ( const auto & x : G[i])
            os << "( " << x.first << ", " << x.second << " )";
        os << '\n';
    }
    */
    is.close();
    os.close();
    return 0;
}
void Read()
{
    int x, y, c, m;
    is >> n >> m;
    d.resize(n+1, INF );
    G.resize(n+1);
    while ( m-- )
    {
        is >> x >> y >> c;
        G[x].push_back(make_pair(y, c));
    }
}
void Dijkstra(int x)
{
    d[x] = 0;
    Q.push(x);
    while ( !Q.empty() )
    {
        x = Q.front();
        Q.pop();
        for ( const auto & v : G[x] )
            if ( d[v.first] > d[x] + v.second )
            {
                d[v.first] = d[x] + v.second;
                Q.push(v.first);
            }
    }
}
void Write()
{
    for ( int i = 2; i <= n; ++i )
    {
        if ( d[i] == INF )
            os << "0 ";
        else
            os << d[i] << ' ';
    }
}
