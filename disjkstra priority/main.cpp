#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("dijkstra.in");
ofstream os("dijkstra.out");

int n, m, d[50001];
vector<pair<int, int> > G[50001];
priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

void Read();
void Disjkstra();
void Write();

int main()
{
    Read();
    Disjkstra();
    Write();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m;
    for ( int i = 0, x, y, c; i < m; ++i )
    {
        is >> x >> y >> c;
        G[x].push_back({y, c});
    }
}
void Disjkstra()
{
    int x, c;
    vector<pair<int, int> > :: iterator it;
    memset(d, 63, sizeof(d) );
    d[1] = 0;
    Q.push({0, 1}); // nodul 1 cu costul 0
    while ( !Q.empty() )
    {
        c = Q.top().first ;
        x = Q.top().second;
        Q.pop();
        for ( it = G[x].begin(); it != G[x].end(); it++ )
            if ( d[it->first] > c + it->second )
            {
                d[it->first] = c + it->second;
                Q.push({d[it->first], it->first});
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
