#include <fstream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("tir.in");
ofstream os("tir.out");

int n, k, v[51];
int d[1001], t[1001];
void Afis(int p);

int main()
{
    is >> n >> k;
    for ( int i = 1; i <= n; ++i )
        is >> v[i];
    memset(d, 63, sizeof(d) );
    d[0] = 0;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 0; j <= k-v[i]; ++j )
            if ( d[j] != INF && d[j+v[i]] >= d[j] + 1 )
            {
                d[j+v[i]] = d[j] + 1;
                t[j+v[i]] = j;
            }
    if ( d[k] == INF )
        os << "0";
    else
    {
        os << d[k] << '\n';
        Afis(k);
    }
    is.close();
    os.close();
    return 0;
}
void Afis(int p)
{
    if ( p == 0 )
        return;
    Afis(t[p]);
    os << p - t[p] << ' ';
}
