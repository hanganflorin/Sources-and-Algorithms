#include <fstream>
using namespace std;

ifstream is("munte.in");
ofstream os("munte.out");

int n, d, K, v[51];
long long nr[101][51][51][2];
void Dinamica();

int main()
{
    is >> n >> d >> K;
    for ( int i = 1; i <= K; ++i )
        is >> v[i];
    Dinamica();
    os << nr[d][n][K][1];
    is.close();
    os.close();
    return 0;
}
void Dinamica()
{
    nr[1][0][0][0] = 1;
    for ( int i = 2; i <= d; ++i )
        for ( int j = 0; j <= n; ++j )
            for ( int k = 0; k <= K; ++k)
                for ( int t = 0; t <= 1; ++t )
                {
                    if ( j == n )
                    {
                        if ( v[k] == j )
                            nr[i][j][k][t]= nr[i-1][j-1][k-1][0] +
                                            nr[i-1][j-1][k-1][1] +
                                            nr[i-1][j]  [k-1][0] +
                                            nr[i-1][j]  [k-1][1];
                        else
                            nr[i][j][k][t]= nr[i-1][j-1][k][0] +
                                            nr[i-1][j-1][k][1] +
                                            nr[i-1][j]  [k][0] +
                                            nr[i-1][j]  [k][1];
                    }
                    else
                    {
                        if ( v[k] == j )
                            nr[i][j][k][t]= nr[i-1][j-1][k-1][0] +
                                            nr[i-1][j-1][k-1][1] +
                                            nr[i-1][j]  [k-1][0] +
                                            nr[i-1][j]  [k-1][1] +
                                            nr[i-1][j+1][k-1][0] +
                                            nr[i-1][j+1][k-1][1];
                        else
                            nr[i][j][k][t]= nr[i-1][j-1][k][0] +
                                            nr[i-1][j-1][k][1] +
                                            nr[i-1][j]  [k][0] +
                                            nr[i-1][j]  [k][1] +
                                            nr[i-1][j+1][k][0] +
                                            nr[i-1][j+1][k][1];
                    }
                }

}
