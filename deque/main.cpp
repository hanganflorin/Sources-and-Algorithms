#include <fstream>
#define MAX 10000010
using namespace std;

ifstream is("deque.in");
ofstream os("deque.out");

int n, k, mn, p;
long long s;
int a[5000002];

int main()
{
    is >> n >> k;
    for ( int i = 0; i < n; ++i )
        is >> a[i];
    mn = MAX;
    for ( int i = 0; i < n; ++i )
    {
        if ( a[i] <= mn )
        {
            mn = a[i];
            p = i;
        }
        if ( p <= i - k)
        {
            mn = MAX;
            for ( int j = 0; j < k; ++j )
                if ( a[i-j] < mn )
                {
                    mn = a[i-j];
                    p = i-j;
                }
        }
        if ( i+1 >= k )
            s += mn;
    }
    os << s;
    is.close();
    os.close();
    return 0;
}
