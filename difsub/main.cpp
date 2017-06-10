#include <fstream>
using namespace std;

ifstream is("difsub.in");
ofstream os("difsub.out");

#define MAX 1001

int n, r, s1, s2, sum;
int st[MAX], dr[MAX], t[MAX], v[MAX];

void Read()
{
    is >> n;
    int x, y, z;
    for ( int i = 1; i <= n; ++i )
    {
        is >> x >> y >> z;
        v[i] = x;
        st[i] = y;
        dr[i] = z;
        t[y] = t[z] = i;
    }
}

void DFS( int nod )
{
    if ( st[nod] )
    {
        sum += v[st[nod]];
        DFS(st[nod]);
    }
    if( dr[nod] )
    {
       sum += v[dr[nod]];
       DFS(dr[nod]);
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
    sum = v[st[r]];
    DFS(st[r]);
    s1 = sum;
    sum = v[dr[r]];
    DFS(dr[r]);
    s2 = sum;
    if ( s1 > s2 )
        os << s1-s2;
    else
        os << s2-s1;

}

int main()
{
    Read();
    Solve();

    is.close();
    os.close();
    return 0;
}
