#include <fstream>
#include <algorithm>
using namespace std;

ifstream is("bomboane.in");
ofstream os("bomboane.out");

int n, a[101], m, mn;

int main()
{
    is >> n;
    for ( int i = 0; i < n; ++i )
    {
        is >> a[i];
        m += a[i];
    }
    m /= n;
    sort(a, a+n);
    while ( a[0] != a[n-1] )
    {
        mn = m - a[0];
        a[0]+=mn;
        a[n-1]-=mn;
    }
    is.close();
    os.close();
    return 0;
}
