#include <fstream>
using namespace std;

ifstream is("cladire2.in");
ofstream os("cladire2.out");

int n, m, nr, c[201][201];
void Write(int i, int j);

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            is >> nr;
            c[i][j] = max(c[i-1][j], c[i][j-1]) + nr;
        }
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= m; ++j )
             os << c[i][j] << ' ';
        os << '\n';
    }
    Write(n, m);
    is.close();
    os.close();
    return 0;
}
void Write(int i, int j)
{
    if ( i < 1 || j < 1 )
        return;
    if ( c[i-1][j] >= c[i][j-1] && i != 1)
        Write(i-1, j);
    else
        Write(i, j-1);
    os << i << ' ' << j << '\n';
}
