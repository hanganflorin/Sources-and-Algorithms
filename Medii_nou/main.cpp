#include <fstream>
using namespace std;

ifstream is("medii.in");
ofstream os("medii.out");

float m, a;
int t, s, x[11], a2;
unsigned short aux;
bool ok;

void Gen(int k);
void Afis(int k);

int main()
{
    is >> m >> t;
    a = ( ( (4 * m) - t ) / 3 );
    a2 = a * 1000;
    x[0] = 1;
    Gen(1);
    if ( !ok )
        os << 0;
    is.close();
    os.close();
    return 0;
}
void Gen( int k )
{
    if ( k == 1 )
        aux = 1;
    else
        aux = k - 1;

    if ( ( s*1000 ) / aux == a2 && k > 3 )  Afis(k);

    if ( k > 10 || ( s*1000 ) / aux > a2) return;

    for ( int i = x[k-1]; i <= 10; ++i )
    {
        x[k] = i;
        s += i;
        Gen(k+1);
        s -=i;
    }
}
void Afis(int k)
{
    ok = true;
    for ( int i = 1; i < k; ++i )
        os << x[i] << ' ';
    os << '\n';
}
