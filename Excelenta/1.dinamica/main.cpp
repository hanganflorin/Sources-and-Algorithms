#include <fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int n, x[100], a[100], Lmax;

void GetMax(int k);
void B(int k);
void Afis();

int main()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    a[0] = -99999;
    GetMax(1);
    B(1);
    is.close();
    os.close();
    return 0;
}
void GetMax(int k)
{
    Lmax = max(Lmax, k-1);
    if ( k > n ) return;
    for ( int i = x[k-1] + 1; i <= n; ++i )
    {
        x[k] = i;
        if ( a[x[k-1]] < a[i] )
            GetMax(k+1);
    }
}
void B(int k)
{
    if ( k-1 == Lmax )
    {
        Afis();
        return;
    }
    if ( k > n ) return;
    for ( int i = x[k-1]+1; i <= n; ++i )
    {
        x[k] = i;
        if ( a[x[k-1]] < a[i] )
            B(k+1);
    }
}
void Afis()
{
    for ( int i = 1; i <= Lmax; ++i )
        os << a[x[i]] << ' ';
    os << '\n';
}
