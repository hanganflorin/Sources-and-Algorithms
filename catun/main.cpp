#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("catun.in");
ofstream os("catun.out");

struct {
    int f, dim = INF;
}x[36001];

int n, m, d[36001], k, a[36001];
bool b[36001];

vector<pair<int, int> > G[36001];
priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

void Read();
void Disjkstra(int x);
void Write();

int main()
{
    Read();
    for ( int i = 1; i <= k; ++i )
        Disjkstra(a[i]);
    Write();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m >> k;
    for ( int i = 1; i <= k; ++i )
    {
        is >> a[i];
        b[a[i]] = true;
    }
    for ( int i = 0, x, y, c; i < m; ++i )
    {
        is >> x >> y >> c;
        G[x].push_back({y, c});
        G[y].push_back({x, c});
    }
}
void Disjkstra(int nod )
{
    int c, nd;
    vector<pair<int, int> > :: iterator it;
    memset(d, 63, sizeof(d) );
    d[nod] = 0;
    Q.push({0, nod});
    while ( !Q.empty() )
    {
        c = Q.top().first ;
        nd = Q.top().second;
        Q.pop();
        for ( it = G[nd].begin(); it != G[nd].end(); it++ )
            if ( d[it->first] > c + it->second && !b[it->first] )
            {
                d[it->first] = c + it->second;
                Q.push({d[it->first], it->first});
                if ( x[it->first].dim > d[it->first]  )
                {
                    x[it->first].dim = d[it->first];
                    x[it->first].f = nod;
                }
            }
    }
}
void Write()
{
    for ( int i = 1; i <= n; ++i )
        os << x[i].f << ' ';
}
