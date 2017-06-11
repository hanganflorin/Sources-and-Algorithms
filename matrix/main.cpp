#include <fstream>
using namespace std;

ifstream is("matrix.in");
ofstream os("matrix.out");

int n, m, cnt;
unsigned short c[26];
unsigned short d[26][1001][1001];
char a[1001][1001], ch;

bool Ok(int i, int j);


int main()
{
    is >> m >> n;
    for ( int i = 1; i <= m; ++i )
        for ( int j = 1; j <= m; ++j )
            is >> a[i][j];

    for ( int k = 0; k < 26; ++k )
        for ( int i = 1; i <= m; ++i )
            for ( int j = 1; j <= m; ++j )
                d[k][i][j] = d[k][i-1][j] + d[k][i][j-1] - d[k][i-1][j-1] + (a[i][j]-97 == k ? 1 : 0);

    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            is >> ch, c[ch-97]++;

    for ( int i = 1; i <= m-n+1; ++i )
        for ( int j = 1; j <= m-n+1; ++j )
            if ( Ok(i, j) )
                cnt++;

    os << cnt;
    is.close();
    os.close();
    return 0;
}
bool Ok(int i, int j)
{
    for ( int k = 0; k < 26; ++k )
        if ( c[k] != d[k][i+n-1][j+n-1] - d[k][i+n-1][j-1] - d[k][i-1][j+n-1] + d[k][i-1][j-1] )
            return false;
    return true;
}
