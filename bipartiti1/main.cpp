#include <fstream>
#include <cstring>
using namespace std;

ifstream is("veriflant.in");
ofstream os("veriflant.out");

int n, m, K, a[101][101], x, y, b[201], nr;
bool ok, c[201], ok2;

int main()
{
    is >> n >> m;
    while ( m-- )
    {
        is >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    is >> K;
    is.get();
    for ( int k = 0; k < K; ++k )
    {
        ok = true;
        ok2 = false;
        memset(c, 0, sizeof(c) );

        is >> nr;
        for ( int i = 0; i < nr; ++i )
        {
            is >> b[i];
            if ( c[b[i]] )
                ok2 = true;
            else
                c[b[i]] = true;
        }
        for ( int i = 1; i < nr; ++i )
        {
            if ( !a[b[i]][b[i-1]] )
            {
                ok = false;
                break;
            }
        }
        if ( !ok )
            os << "NU\n";
        else if ( !ok2 )
            os << "ELEMENTAR\n";
        else
            os << "NEELEMENTAR\n";
    }
    is.close();
    os.close();
    return 0;
}
