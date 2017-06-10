#include <fstream>
#include <cstring>
using namespace std;

ifstream is("farfurii.in");
ofstream os("farfurii.out");

int n, t, a[80], d[1001], sm[1001], pz[1001];
int nmax, tmin;

int main()
{
    is >> n >> t;
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    memset(d, 0xff, sizeof(d));
    d[0] = 0;
    for ( int i = 1; i <= n; ++i )
        for ( int j = t - a[i]; j >= 0; --j )
            if ( d[j+a[i]] <= d[j] + 1 )
            {
                d[j+a[i]] = d[j] + 1;
                pz[j+a[i]] = i;
                sm[j+a[i]] = sm[j] + a[i];
            }
    for ( int i = 1; i <= t; ++i )
        if ( d[i] > nmax )
        {
            nmax = d[i];
            tmin = sm[i] + pz[i] - d[i];
        }
    os << nmax << ' ' << tmin;
    is.close();
    os.close();
    return 0;
}
