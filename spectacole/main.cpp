#include <fstream>
#include <algorithm>
using namespace std;

ifstream is("spectacole.in");
ofstream os("spectacole.out");

int n, nr = 1, p;
struct X{
    int i, j;
} a[101];
bool Cmp(const X & a1, const X & a2 )
{
    return a1.j < a2.j;
}

int main()
{
    is >> n;
    for ( int i = 0; i < n; ++i )
        is >> a[i].i >> a[i].j;
    sort(a, a + n, Cmp );
    p = a[0].j;
    for ( int i = 1; i < n; ++i )
    {
        if ( a[i].i >= p )
        {
            nr++;
            p = a[i].j;
        }
    }
    os << nr;
    is.close();
    os.close();
    return 0;
}
