#include <fstream>
#include <vector>
using namespace std;

ifstream is("expozitie.in");
ofstream os("expozitie.out");

struct Exp{
    short x[1001];
    int n;
};
void Modifica();
void Adun(int j);

vector<Exp> a;
vector<Exp> b;
int n, k, d;

int main()
{
    is >> n >> d >> k;
    n -= k*d;
    if ( n == 0 )
    {
        os << 1;
        is.close();
        os.close();
        return 0;
    }
    if ( n < 1 )
    {
        os << 0;
        is.close();
        os.close();
        return 0;
    }
    n += d-1;
    d--;
    Modifica();
    for ( int i = 2; i <= n; ++i )
    {
        b[0].n = 1;
        b[0].x[0] = 1;
        for ( int j = 1; j <= d; ++j )
            Adun(j);
        a = b;

    }
    for ( int i = a[d].n-1; i >= 0; --i )
        os << a[d].x[i];
    is.close();
    os.close();
    return 0;
}
void Modifica()
{
    a.resize(d+1);
    b.resize(d+1);
    a[0].n = 1;
    a[0].x[0] = 1;
    a[1].n = 1;
    a[1].x[0] = 1;
}
void Adun(int j)
{
    int i, t = 0;
    for ( i = 0; i < a[j].n || i < a[j-1].n || t; i++, t /= 10 )
    {
        t += a[j].x[i] + a[j-1].x[i];
        b[j].x[i] = t % 10;
    }
    b[j].n = i;
}
