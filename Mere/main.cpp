#include <fstream>
#include <vector>
using namespace std;

ifstream is("mere.in");
ofstream os("mere.out");

int n, a[1001], s;
bool b[1001];
vector<int> G[1001];
void Df(int x);

int main()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    for ( int i = 1, x, y; i < n; ++i )
    {
        is >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    Df(1);
    os << s;
    is.close();
    os.close();
    return 0;
}
void Df(int x)
{
    if ( x == 0 )
        return;
    s += a[x];
    b[x] = true;
    int mx = 0, poz = 0;
    for ( vector<int>::iterator it = G[x].begin(); it != G[x].end(); ++it )
        if ( !b[*it] && a[*it] > mx )
        {
            mx = a[*it];
            poz = *it;
        }
    Df(poz);
}
