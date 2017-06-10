#include <fstream>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("royfloyd.in");
ofstream os("royfloyd.out");

int n, a[101][101];

int main()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
        {
            is >> a[i][j];
            if ( a[i][j] == 0 )
                a[i][j] = INF;
        }
    for ( int k = 1; k <= n; ++k )
        for ( int i = 1; i <= n; ++i )
            for( int j = 1; j<= n; ++j )
                if ( i != j )
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= n; ++j )
        {
            if ( a[i][j] == INF )
                os << "0 ";
            else
                os << a[i][j] << ' ';
        }
        os << '\n';
    }
    is.close();
    os.close();
    return 0;
}
