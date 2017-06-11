#include <fstream>
#define MOD 9901
using namespace std;

ifstream is("cladire1.in");
ofstream os("cladire1.out");

int n, m, k, x, y, a[1001][1001];

int main()
{
    is >> n >> m >> k;
    while (k--)
    {
        is >> x >> y;
        a[x][y] = -1;
    }
    a[1][0] = 1;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( a[i][j] != -1 )
                a[i][j] = ( ( a[i-1][j] == -1 ? 0 : a[i-1][j] ) +
                            ( a[i][j-1] == -1 ? 0 : a[i][j-1] ) ) % MOD;
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= m; ++j )
        {
            if ( a[i][j] == -1 )
                os << "x ";
            else
                os << a[i][j] << ' ';
        }
        os << '\n';
    }
    is.close();
    os.close();
    return 0;
}
