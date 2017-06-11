#include <fstream>
using namespace std;

ifstream is("comori.in");
ofstream os("comori.out");

int n, m, a[201][201], c[201][201];

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            is >> a[i][j];
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            c[i][j] = max(c[i-1][j], max(c[i-1][j-1], c[i-1][j+1])) + a[i][j];
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= m; ++j )
            os << c[i][j] << ' ';
        os << '\n';
    }
    return 0;
}
