#include <fstream>
#include <cstring>
#define M 60000
using namespace std;

ifstream is("buyhay.in");
ofstream os("buyhay.out");

int c[M];
int n, h, cost, p;

int main()
{
    memset(c, 63, sizeof(c));
    c[0] = 0;
    is >> n >> h;
    for ( int i = 0; i < n; ++i )
    {
        is >> p >> cost;
        for ( int j = 0; j <= h; ++j )
            if ( c[j] + cost < c[j+p] )
                c[j+p] = c[j]+cost;
    }
    int r = 0x3f3f3f3f;
    for ( int i = h; i < M; ++ i )
        if ( c[i] < r )
            r = c[i];
    os << r;
    is.close();
    os.close();
    return 0;
}
