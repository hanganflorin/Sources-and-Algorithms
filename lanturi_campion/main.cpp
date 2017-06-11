#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

ifstream is("lanturi.in");
ofstream os("lanturi.out");

int n, m, p, q, d[1001], nr[1001];
vector < pair<int, int> > G[1001];
priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

void Read();
void Dijkstra(int x);

int main()
{
    Read();
    Dijkstra(p);
    os << nr[q];
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m >> p >> q;
    for ( int i = 0, x, y, c; i < m; ++i )
    {
        is >> x >> y >> c;
        G[x].push_back(make_pair(y, c));
        G[y].push_back(make_pair(x, c));
    }
}
void Dijkstra(int x)
{
    int c;
    vector<pair<int, int > >::iterator it;
    memset(d, 63, sizeof(d) );
    d[x] = 0;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        c = Q.top().first;
        x = Q.top().second;
        Q.pop();
        for ( it = G[x].begin(); it != G[x].end(); it++ )
        {
            if ( d[it->first] > c + it->second )
            {
                d[it->first] = c + it->second;
                Q.push(make_pair(d[it->first], it->first));
                nr[it->first] = 1;
            }
            else if ( d[it->first] == c + it->second )
                nr[it->first] += nr[x];
        }
    }
}
