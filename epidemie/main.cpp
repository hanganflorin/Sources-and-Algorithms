#include <fstream>
#include <queue>
#include <vector>
#include<bitset>
using namespace std;

ifstream is("epidemie.in");
ofstream os("epidemie.out");

int n, m, nr, p;

bitset<1001> b;
vector<vector<int> > G;
queue<int> Q1, Q2;

void Read();

int main()
{
    Read();
    while(!Q1.empty())
    {
        while(!Q1.empty())
        {
            p = Q1.front();
            Q1.pop();
            for ( vector<int> :: iterator it = G[p].begin(); it != G[p].end(); ++it )
                if ( !b[*it] )
                {
                    b[*it] = true;
                    Q2.push(*it);
                }
        }
        nr++;
        swap(Q1, Q2);
    }
    os << nr;
    is.close();
    os.close();
    return 0;
}
void Read()
{
    int k, x, y;
    is >> n >> m;
    G.resize(n+1);
    while ( m-- )
    {
        is >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    is >> k;
    while(k--)
    {
        is >> x;
        b[x] = true;
        Q1.push(x);
    }
}
