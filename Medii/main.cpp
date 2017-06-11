#include <fstream>
using namespace std;

ifstream is("medii.in");
ofstream os("medii.out");

int x[11], t, p, s, aux;
float m, a;
void Gen(int k);
void Afis();
bool Ok(int p);
bool b;

int main()
{
    x[0] = 1;
    is >> m >> t;
    a  = (int)(( 4 * m - t ) / 3 * 1000);
    for ( p = 3; p <= 10; ++p )
        if ( Ok(p) )
            Gen(1);
    if ( !b )
        os << 0;
    is.close();
    os.close();
    return 0;
}
void Gen(int k)
{
    aux = (s*1000) / p;
    if ( aux == a)
    {
        Afis();
        return;
    }
    if ( aux > a )
        return;
    for ( int i = x[k-1]; ((s+i)*1000) / p <= a && i <= p; ++i )
    {
        x[k] = i;
        s += i;
        Gen(k+1);
        s -= i;
    }
}
void Afis()
{
    b = true;
    for ( int i = 1; i <= p; ++i )
        os << x[i] << ' ';
    os << '\n';
}
bool Ok(int p)
{
    p *= a;
    for ( int i = 0; i < 3; ++i )
    {
        if ( p % 10 != 0 )
            return false;
        p /= 10;
    }
    return true;
}
