#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("camionas.in");
ofstream os("camionas.out");

int n, m, g, d[50001];
vector< pair<int, int> > G[50001];
priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

void Read();
void Dijkstra();

int main()
{
    Read();
    Dijkstra();
    os << d[n];
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m >> g;
    for ( int i = 0, x, y ,c; i < m; ++i )
    {
        is >> x >> y >> c;
        c = ( c < g );
        G[x].push_back(make_pair(y, c));
        G[y].push_back(make_pair(x, c));
    }
}
void Dijkstra()
{
    int x, c;
    memset(d, 63, sizeof(d) );
    d[1] = 0;
    Q.push({0, 1});
    while ( !Q.empty() )
    {
        c = Q.top().first;
        x = Q.top().second;
        Q.pop();
        for (const auto& v : G[x] )
            if ( d[v.first] > v.second + c )
            {
                d[v.first] = v.second + c;
                Q.push({d[v.first], v.first});
            }
    }
}
