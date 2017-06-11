#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <bitset>
using namespace std;

ifstream is("lanturi.in");
ofstream os("lanturi.out");

int n, m, p, q, d[1001];
long long nr[1001];
bitset<1001> b;
vector<pair<int, int> > G[1001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

void Read();
void Dijkstra(int x);

int main()
{
    Read();
    Dijkstra(p);
    for ( int i = 1; i <= n; ++i )
        os << d[i] << ' ';
    os << "\n";
    for ( int i = 1; i <= n; ++i )
        os << nr[i] << ' ';
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
    memset(d, 63, sizeof(d));
    d[x] = 0;
    nr[x] = 1;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        c = Q.top().first;
        x = Q.top().second;
        Q.pop();
        b[x] = false;
        vector<pair<int, int> > ::iterator it;
        for(it = G[x].begin(); it != G[x].end(); it++)
        {
            if ( d[it->first] > c + it->second )
            {
                d[it->first] = c + it->second;
                nr[it->first] = nr[x];
                if ( b[it->first] == false )
                {
                    b[it->first] = true;
                    Q.push(make_pair(d[it->first], it->first));
                }
            }
            else if ( d[it->first] == c + it->second )
                nr[it->first] += nr[x];
        }
    }
}

for ( int i = 1; i <= k; ++i )
{
    is >> nrelem;
    ok = true;
    ok2 = true;
    for ( int j = 1; j <= nrelem; ++j )
    {
        is >> b[i];
        c[b[i]]++;
        if ( c[b[i]] > 1 )
            ok2 = false;
        if ( j > 1 && a[b[j-1]][b[j]] == false )
        {
            ok = false;
            return;
        }
    }
    if ( ok == false )
        os << "NU\n";
    else

}
