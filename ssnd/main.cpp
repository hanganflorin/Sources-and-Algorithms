#include <fstream>
#include <bitset>
#define M 1000010
using namespace std;

ifstream is("ssnd.in");
ofstream os("ssnd.out");

int n, nr, prim[M], m;
bitset<M> b;

void Ciur();
void Rezolva(int n);

int main()
{
    Ciur();
    is >> n;
    while ( n-- )
    {
        is >> nr;
        Rezolva(nr);

    }
    is.close();
    os.close();
    return 0;
}
void Ciur()
{
    for ( int i = 2; i <= M; ++i )
        if ( !b[i] )
        {
            prim[m++] = i;
            for ( int j = 2; j * i <= M; ++j )
                b[i*j] = true;
        }
}
void Rezolva(int n)
{
    int r1 = 1, r2 = 0;
    int aux = n;
    if ( !b[n] )
    {
        r1 = 2;
        r2 = n+1;
    }
    else
    {
        for ( int i = 0; 1LL * prim[i] * prim[i] <= aux; ++i )
        {
            int p = 0;
            while ( n % prim[i] == 0 )
            {
                p++;
                n /= prim[i];
            }
            if ( p )
                r1 *= p+1;
        }
    }
    os << r1 << '\n';
}
