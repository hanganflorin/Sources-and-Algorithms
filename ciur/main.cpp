#include <fstream>
#include <cstring>
using namespace std;

ifstream is("ciur.in");
ofstream os("ciur.out");

bool p[2000002];
int cnt, n;


int main()
{
    memset(p, 1, sizeof(p) );
    is >> n;
    for ( int i = 2; i <= n; ++i )
        if ( p[i] )
        {
            cnt++;
            for ( int j = 2; j * i <= n; ++j )
                p[i*j] = false;
        }
    os << cnt;
    is.close();
    os.close();
    return 0;
}
