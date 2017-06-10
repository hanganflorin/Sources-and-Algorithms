#include <fstream>
using namespace std;

ifstream is("conex.in");
ofstream os("conex.out");

int n, a[101][101], x, y;
bool ok = true;

int main()
{
    is >> n;
    while ( is >> x >> y )
        a[x][y] = a[y][x] = 1;
    for ( int k = 1; k <= n; ++k )
        for ( int i = 1; i <= n; ++i )
            for ( int j = 1; j <= n; ++j )
                if ( !a[i][j] )
                    a[i][j] = a[i][k] * a[k][j];
    for ( int i = 1; i <= n && ok; ++i )
        for ( int j = i+1; j <= n && ok; ++j )
             ok = a[i][j];
    if ( ok )
        os << "DA";
    else
        os << "NU";
    is.close();
    os.close();
    return 0;
}
