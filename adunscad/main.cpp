#include <fstream>
using namespace std;

ifstream is("adunscad.in");
ofstream os("adunscad.out");

int S, n, a[21], sm, x[21];
void B(int k);
void Afis();
bool ok;

int main()
{
    is >> S >> n;
    for( int i = 1; i <= n; ++i )
        is >> a[i];
    B(1);
    if ( !ok )
        os << 0 << '\n';
    is.close();
    os.close();
    return 0;
}
void B(int k)
{
    if ( ok ) return;
    if ( k > n )
    {
        if ( sm == S )
            Afis(), ok = true;
        return;
    }
    x[k] = 1;
    sm += a[k];
    B(k+1);
    sm -= a[k];

    x[k] = -1;
    sm -= a[k];
    B(k+1);
    sm += a[k];
}
void Afis()
{
    for (int i = 1; i <= n; ++i )
    {
        if ( x[i] == -1 )
            os << '-';
        else if ( i != 1 )
            os << '+';
        os << a[i];
    }
}
