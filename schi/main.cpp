#include <fstream>
using namespace std;

ifstream is("schi.in");
ofstream os("schi.out");

int n, x[30001], poz;
int aib[30001];
int b[30001];

void Update(int p, int v)
{
    for ( int i = p; i <= n; i += i & -i )
        aib[i] += v;
}

int Find(int v)
{
    int i = 0;
    for ( int p = 1 << 15; p; p >>= 1 )
        if ( i + p <= n && aib[i+p] < v )
        {
            v -= aib[i + p];
            i += p;
        }
    return i+1;
}

int main()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
    {
        is >> x[i];
        Update(i, 1);
    }
    for ( int i = n; i > 0; --i )
    {
        poz = Find( x[i] );
        b[poz] = i;
        Update(poz, -1);
    }
    for ( int i = 1; i <= n; ++i )
        os << b[i] << '\n';
    is.close();
    os.close();
    return 0;
}
