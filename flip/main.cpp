#include <fstream>
using namespace std;

ifstream is("flip.in");
ofstream os("flip.out");

int n, m, x[20], a[17][17], s, smax;
void Back(int k);
int Suma();
int Abs(int x);

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            is >> a[i][j];
    Back(1);
    os << smax;
    is.close();
    os.close();
    return 0;
}
void Back(int k)
{
    if ( k > m )
    {
        s = Suma();
        if ( s > smax )
            smax = s;
        return;
    }
    x[k] = 1, Back(k+1);
    x[k] = -1, Back(k+1);
}
int Suma()
{
    int sm = 0, suma = 0;
    for ( int i = 1; i <= n; ++i )
    {
        sm = 0;
        for ( int j = 1; j <= m; ++j )
            sm += a[i][j] * x[j];
        suma += Abs(sm);
    }
    return suma;
}
int Abs(int x)
{
    if ( x >= 0 )
        return x;
    return -1 * x;
}
