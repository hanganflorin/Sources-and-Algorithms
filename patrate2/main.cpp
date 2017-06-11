#include <fstream>
#include <cstring>
using namespace std;

ifstream is("patrate2.in");
ofstream os("patrate2.out");

void M( short* a, int b );
void M2( short * a );
void Write();

int n, nr;
short a[10000];
void Pow(int x);


int main()
{
    is >> n;
    Pow(n*n);
    for ( int i = 2; i <= n; ++i )
        M(a, i);
    Write();
    is.close();
    os.close();
    return 0;
}
void M( short * a, int b )
{
    int i, t = 0;
    for ( i = 0; i < nr || t; ++i, t/=10 )
    {
        t += a[i] * b;
        a[i] = t%10;
    }
    nr = i;
}
void Write()
{
    for ( int i = nr-1; i >= 0; --i )
        os << a[i];
}
void Pow(int x)
{
    if ( x == 0 )
    {
        nr = 1;
        a[0] = 1;
        return;
    }
    Pow(x/2);
    M2(a);
    if ( x % 2 == 1 )
        M(a, 2);
}
void M2( short * a )
{
    int i, j, t = 0, nr_c;
    short c[10000];
    memset(c, 0, sizeof(c) );
    for ( i = 0; i < nr; ++i )
    {
        for ( t = 0, j = 0; j < nr || t; ++j, t /= 10 )
        {
            t += c[i+j] + a[i] * a[j];
            c[i+j] = t % 10;
        }
        nr_c = i+j;
    }
    memcpy(a, c, sizeof(c) );
    nr = nr_c;
}
