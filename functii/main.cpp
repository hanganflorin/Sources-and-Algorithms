#include <fstream>
#define M 30103
using namespace std;

ifstream is("functii.in");
ofstream os("functii.out");

int n, s;
int Comb(int n, int k);
void Fact();
int Pow(int n, int x);
int f[10001];

int main()
{
    is >> n >> s;
    Fact();
    os <<  Comb(n, s) *( ( Pow(2, s) - 2 ) % M);
    is.close();
    os.close();
    return 0;
}
int Comb(int n, int k)
{
    int cmb = 1;
    cmb = ( 1LL * f[n] * Pow(f[k], M-2) ) % M;
    cmb = ( 1LL * cmb * Pow(f[n-k], M-2) ) % M;
    return cmb;
}
void Fact()
{
    f[0] = 1;
    for ( int i = 1; i <= n; ++i )
        f[i] = ( 1LL * f[i-1] * i ) % M;
}
int Pow(int n, int x)
{
    if ( x == 0 ) return 1;
    int P = Pow(n, x >> 1) % M;
    P = ( 1LL * P * P ) % M;
    if ( x & 1 )
        P = (1LL * P * n ) % M;
    return P;
}
