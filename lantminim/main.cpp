#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

ifstream is("lungimeminima.in");
ofstream os("lungimeminima.out");

int n, a[101][101], p, L, dist[101], nr;
vector<int> G[101];
queue<int> Q;
bitset<101> b;

void Read();
void Bf(int x);

int main()
{
    Read();
    Bf(p);
    os << nr << '\n';
    for ( int i = 1; i <= n; ++i )
        if ( dist[i] == L )
            os << i << ' ';
    is.close();
    os.close();
    return 0;
}
void Read()
{
    int x, y;
    is >> n >> p >> L;
    while ( is >> x >> y )
    {
        if ( !a[x][y] )
        {
            G[x].push_back(y);
            G[y].push_back(x);
            a[x][y] = a[y][x] = 1;
        }
    }
}
void Bf(int x)
{
    b[x] = true;
    Q.push(x);
    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();
        for ( vector <int>::iterator it = G[x].begin(); it != G[x].end(); it++ )
            if ( !b[*it] )
            {
                b[*it] = true;
                Q.push(*it);
                dist[*it] = dist[x]+1;
                if ( dist[*it] == L )
                    nr++;
            }
    }

}
