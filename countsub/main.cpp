#include <fstream>
using namespace std;

ifstream is("countsub.in");
ofstream os("countsub.out");

#define MAX 1001

int n, k, r;
int st[MAX], dr[MAX], v[MAX], t[MAX];

void Read()
{
    is >> n;
    int x, y, z;
    for ( int i = 1; i <= n; ++i )
    {
        is >> x >> y >> z;
        st[i] = y;
        dr[i] = z;
        t[y] = t[z] = i;
    }
}

void DFS( int nod )
{
    if ( st[nod] )
    {
        DFS( st[nod] );
        v[nod] += v[st[nod]];
    }
    if ( dr[nod] )
    {
        DFS( dr[nod] );
        v[nod] += v[dr[nod]];
    }
}

void Solve()
{
    for ( int i = 1; i <= n; ++i )
        if ( !t[i] )
        {
            r = i;
            break;
        }
    for ( int i = 1; i <= n; ++i )
        v[i] = 1;
    DFS( r );
    is >> k;
    for ( int i = 1; i <= k; ++i )
    {
        is >> r;
        os << v[r] << '\n';
    }

}

int main()
{
    Read();
    Solve();

    is.close();
    os.close();
    return 0;
}
