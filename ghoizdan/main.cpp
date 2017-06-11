#include <fstream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("ghiozdan.in");
ofstream os("ghiozdan.out");

int n, g, a[20002], x[20002];
int D[75002], nr;
bool ok;
void Scrie(int p);

int main()
{
    is >> n >> g;
    memset(D, 63, sizeof(D) );
    D[0] = 0;
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    for ( int i = 1;i <= n; ++i )
    {
        ok = true;
        for ( int j = g - a[i]; j >= 0; --j )
            if ( D[j+a[i]] > D[j] + 1 )
            {
                if ( ok )
                {
                    x[j+a[i]] = j;
                    ok = false;
                }
                D[j+a[i]] = D[j] + 1;

            }
    }
    while ( D[g] == INF )
        g--;
    os << g << ' ';
    Scrie(g);
    is.close();
    os.close();
    return 0;
}
void Scrie(int p)
{
    if ( p == 0 )
    {
        os << nr << '\n';
        return;
    }
    nr++;
    Scrie(x[p]);
    os << p - x[p] << '\n';
}
