#include <fstream>
#include <cstring>
#define M 11005
using namespace std;

ifstream is("energii.in");
ofstream os("energii.out");

long long c[M];
int n, w, nr, energie;
long long s;

int main()
{
    memset(c, 63, sizeof(c) );
    c[0] = 0;
    is >> n >> w;
    for ( int i = 0; i < n; ++i )
    {
        is >> nr >> energie;
        s += 1LL * energie;
        for ( int j = M; j >=0; --j )
            if ( c[j]+energie < c[j+nr] )
                c[j+nr] = c[j] + energie;
    }
    if ( s < w )
        os << -1;
    else
    {
        int r = 0x3f3f3f3f;
        for ( int i = w; i < M; ++i )
            if ( c[i] < r )
                r = c[i];
        os << r;
    }

    is.close();
    os.close();
    return 0;
}
