#include <fstream>
#include <cstring>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

long long n, s;
int nr[102][102][102];
/*
    nr[i][j][k]
    i = nr cupe
    j = nr bile
    k = nr bile din ultima cupa
*/
void Dinamica();

int main()
{
    is >> n;
    Dinamica();
    for (int i = 1; i <= n; ++i )
    {
        for ( int k = 1; k <= n; ++k )
            s +=nr[i][n][k] << ' ';
       // os << '\n';
    }
    os << s;
    is.close();
    os.close();
    return 0;
}
void Dinamica()
{
    for ( int i = 1; i <= n; ++i )
        nr[i][i][1] = 1;
    for ( int j = 1; j <= n; ++j )
        nr[1][j][j] = 1;
    for ( int i = 2; i <= n; ++i )
        for ( int j = 2; j <= n; ++j )
            for ( int k = 1; k <= n; ++k )
                nr[i][j][k] = nr[i][j-1][k-1] + nr[i-1][j-k][k];
}
