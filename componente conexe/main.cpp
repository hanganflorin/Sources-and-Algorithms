#include <fstream>
#include <vector>
using namespace std;

ifstream is("componenteconexe1.in");
ofstream os("componenteconexe1.out");

int n, x, y, nr, X[101];
bool b[101];
vector<int > G[101];

void Df(int x);

int main()
{
    is >> n;
    while ( is >> x >> y)
    {
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for ( int i = 1; i <= n; ++i )
    {
        if ( !b[i] )
        {
            Df(i);
            X[nr++] = i;
        }
    }
    os << nr-1 << '\n';
    for ( int i = 0; i < nr; ++i )
    {
        os << X[i] << ' ';
        if ( i > 0 && i < nr-1 )
        {
            os << '\n';
            os << X[i] << ' ';
        }
    }
    is.close();
    os.close();
    return 0;
}
void Df(int x)
{
    b[x] = true;
    for ( int i = 0; i < G[x].size(); ++i )
        if ( !b[G[x][i]] )
        {
            b[G[x][i]] = true;
            Df(G[x][i]);
        }
}
