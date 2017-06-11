#include <fstream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("hotel.in");
ofstream os("hotel.out");

void Inm(int* a, int b);
void Fact(int p1, int p2);

int c[201];
int n, k, p;
bool b[201];
int cod[1001], etj[1001];
int cnt = 1;
int a[5000];


int main()
{
    is >> n >> k;
    for ( int i = 0; i < n; ++i )
    {
        is >> cod[i] >> etj[i];
        if ( b[etj[i]] == false )
        {
            p++;
            b[etj[i]] = true;
        }
    }
    if ( p > k )
    {
        os << 0;
        is.close();
        os.close();
        return 0;
    }
    a[0] = 1;
    a[1] = 1;
    Fact(k-p, k);
    for ( int i = a[0]; i > 0; --i )
        os << a[i];
    os << '\n';

    memset(c, 63, sizeof(c) );
    for ( int i = 0; i < n; ++i )
    {
        if ( c[etj[i]] == INF )
            c[etj[i]] = cnt++;
        os << cod[i] << ' ' << c[etj[i]] << '\n';
    }
    is.close();
    os.close();
    return 0;
}
void Inm(int* a, int b)
{
    int i, t=0;
    for ( i = 1; i <= a[0] || t; ++i, t /= 10 )
    {
        t = a[i]*b+t;
        a[i] = t%10;
    }
    a[0] = i-1;
}
void Fact(int p1, int p2 ) // p1 < p2
{
    if ( p1 == p2 ) return;
    Inm(a, p2);
    Fact(p1, p2-1);
}
