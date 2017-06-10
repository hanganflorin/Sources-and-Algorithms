#include <fstream>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("distante.in");
ofstream os("distante.out");

int T, n, m, s, a[50001], d[50001];
bool ok;

int main()
{
    is >> T;
    while ( T-- )
    {
        ok = true;
        is >> n >> m >> s;
        for ( int i = 1; i <= n; ++i )
        {
            is >> a[i];
            d[i] = INF;
        }
        d[s] = 0;
        for ( int i = 0, x, y, c; i < m; ++i )
        {
            is >> x >> y >> c;
            if ( d[x] > a[y] + c )
                d[x] = a[y]+c;
            if ( d[y] > a[x] + c )
                d[y] = a[x] + c;
        }
        for ( int i = 1; i <= n; ++i )
            if ( a[i] != d[i] )
            {
                ok = false;
                break;
            }
        if ( ok )
            os << "DA\n";
        else
            os << "NU\n";

    }
    is.close();
    os.close();
    return 0;
}
