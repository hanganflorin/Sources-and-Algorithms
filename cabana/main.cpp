#include <fstream>
#define M 1000000007
using namespace std;

ifstream is("cabana.in");
ofstream os("cabana.out");

long long  n;
int k, f[1000001], t;
void Fact();
int Pow(int n, int x );
int imod;
int fct;

int main()
{
    is >> t;
    Fact();
    for ( int i = 0; i < t; ++i )
    {
        is >> n >> k;
        fct = Pow(f[k], (n/k)+1);
        imod = Pow(f[k - (n%k)], M-2 );
        os << ( ( 1LL * fct * imod ) % M ) << '\n';

    }
    is.close();
    os.close();
    return 0;
}
void Fact()
{
    f[0] = 1;
    for ( int i = 1; i <= 1000000; ++i )
        f[i] = (1LL*f[i-1]*i) % M;
}
int Pow(int n, int x )
{
    if ( x == 0 ) return 1;
    int res = Pow(n, x/2 );
    res = ( 1LL * res * res ) % M;
    if ( x % 2 == 1 )
        res = ( 1LL * res * n ) % M;
    return res;
}
