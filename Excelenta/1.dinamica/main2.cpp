#include <fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int n, x[100], a[100], Lmax, L[100];

void GetMax();
void B(int k);
void Afis();

int main()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    a[0] = -99999;
    GetMax();
    B(1);
    is.close();
    os.close();
    return 0;
}
void GetMax()
{
    for ( int i = 1; i <= n; ++i )
    {
        L[i] = 1;
        for ( int j = 1; j< i; ++j )
            if ( a[j] < a[i] && L[i] < L[j]+1 )
                Lmax = L[j];
        L[i] = Lmax+1;
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
