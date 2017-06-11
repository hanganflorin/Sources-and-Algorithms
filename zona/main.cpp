#include <fstream>
using namespace std;

ifstream is("zona.in");
ofstream os("zona.out");

const int d1[] = {0, -1, 0, 1, 0};
const int d2[] = {0, 0, 1, 0, -1};
int x, y, n, l;
int p[2502];
int pfx, pfy, x2, y2;
int cnt;
int a[101][101];

int main()
{
    is >> x >> y >> n >> l;
    pfx = x;
    pfy = y;
    for ( int i = 0; i < l; ++i )
    {
        is >> p[i];
        pfx += d1[p[i]];
        pfy += d2[p[i]];
    }
    x2 = x;
    y2 = y;
    for ( int i = 0; pfx != x2 || y2 != pfy; ++i )
    {
        x2 += d1[p[i]];
        y2 += d2[p[i]];
        cnt++;
    }
    os << l-cnt;
    for ( int i = cnt; i < l; ++i )
    {


    }
    is.close();
    os.close();
    return 0;
}
