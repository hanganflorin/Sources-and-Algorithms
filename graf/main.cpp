#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#define OK (dist[i].d1+dist[i].d2==Lmin)
using namespace std;

ifstream is("graf.in");
ofstream os("graf.out");

struct {
    int d1, d2;
} dist[7502];

int n, m, p, q, Lmin, nr;
vector<vector<int> > G;
queue<int> Q;
bitset<7502> b;
vector<int> aux[7501], aux2;

void Read();
void Bf(int x, int aux);

int main()
{
    Read();
    Bf(p, 1);
    Bf(q, 2);
    Lmin = dist[q].d1;

    for ( int i = 1; i <= n; ++i )
        if ( OK )
            aux[dist[i].d1].push_back(i);
    for ( int i = 0; i <= Lmin; ++i )
        if ( aux[i].size() == 1 )
        {
            nr++;
            aux2.push_back(aux[i][0]);
        }
    os << nr << '\n';
    sort(aux2.begin(), aux2.end());
    for ( int i = 0; i < nr; ++i )
        os << aux2[i] << ' ';
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m >> p >> q;
    G.resize(n+1);
    for ( int i = 0, x, y; i < m; ++i )
    {
        is >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}
void Bf(int x, int aux)
{
    if ( aux == 2 )
        b.reset();
    Q.push(x);
    b[x] = true;
    while ( !Q.empty() )
    {
        x = Q.front();
        Q.pop();
        for ( vector<int>::iterator it = G[x].begin(); it != G[x].end(); it++)
            if ( !b[*it] )
            {
                b[*it] = true;
                Q.push(*it);
                if ( aux == 1 )
                    dist[*it].d1 = dist[x].d1 + 1;
                else
                    dist[*it].d2 = dist[x].d2 + 1;
            }
    }
}
