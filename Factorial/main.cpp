#include <fstream>
using namespace std;

ifstream is("fact.in");
ofstream os("fact.out");

int st = 1, dr = 1000000000;
int p, v, m;
int Calculeaza(int x);

int main()
{
    is >> p;
    if ( p == 0 )
        os << 1;
    else
    {
        while ( st <= dr )
        {
            m = st + (dr-st)/2;
            v = Calculeaza(m);
            if ( p == v )
                break;
            if ( v > p )
                dr = m-1;
            else
                st = m+1;

        }
        while( m%5 != 0 )
            m--;
        if ( Calculeaza(m) != p )
            os << -1;
        else
            os << m;
    }
    is.close();
    os.close();
    return 0;
}
int Calculeaza(int x)
{
    int nr = 0;
    int putere = 5;
    while ( putere <= x )
    {
        nr += x / putere;
        putere *= 5;
    }
    return nr;
}
