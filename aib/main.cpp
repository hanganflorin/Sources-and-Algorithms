#include <fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int aib[1000];
int n, t, v, p, k;
void Update(int p, int v);
int Suma(int p);

int main()
{
    is >> n >> t;
    for ( int i = 1; i <= n; ++i )
    {
        is >> v;
        Update(i, v);
    }
    for ( int i = 0; i < t; ++i )
    {
        is >> k; // k = 1 update    k = 0 afis
        if ( k == 1 )
        {
            is >> p >> v;
            Update(p, v);
        }
        else
        {
            is >> p;
            os << Suma(p) << '\n';
        }
    }
    is.close();
    os.close();
    return 0;
}
void Update(int p, int v)
{
    for ( int i = p; i <= n; i += i & -i )
        aib[i] += v;
}
int Suma(int p)
{
    int s;
    for ( int i = p; i > 0; i -= i & -i )
        s += aib[i];
    return s;
}
void Update(int p1, int p2, int v)
{
    for ( int i = p1; i <= n; i += i & -i )
        for ( int j = p2; j <= n; j += i & -i );
            aib[i][j] += v;
}
int Suma(int p1, int p2)
{
    int s;
    for ( int i = p1; i > 0; i -= i & -i )
        for ( int j = p2; j > 0; j -= j & -j )
            s += aib[i][j];
    return s;
}
