#include <fstream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("sant.in");
ofstream os("sant.out");

int s, n, c;
int L[11], P[11];
int D[101][101], t[101][101];
void Scrie(int i, int j);

int main()
{
    is >> s >> n >> c;
    for ( int i = 1; i <= c; ++i )
        is >> L[i] >> P[i];
    memset(D, 63, sizeof(D) );
    D[0][0] = 0;

    for ( int i = 1; i <= c; ++i )
        for ( int j = 0; j <= s; ++j )
            for ( int k = 0; k < n; ++k )
                if ( D[k][j] != INF && D[k+1][j+L[i]] > D[k][j] + P[i] )
                {
                    D[k+1][j+L[i]] = D[k][j] + P[i];
                    t[k+1][j+L[i]] = i;
                }

    if ( D[n][s] == INF )
        os << 0;
    else
    {
        os << D[n][s] << '\n';
        Scrie(n, s);
    }
    is.close();
    os.close();
    return 0;
}
void Scrie(int i, int j)
{
    if ( i == 0 || j == 0)
        return;
    Scrie(i-1, j - L[t[i][j]]);
    os << t[i][j] << ' ';
}
