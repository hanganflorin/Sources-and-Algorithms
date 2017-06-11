#include <fstream>
#include <cstring>
#include <algorithm>
#define M1 5000002
#define M2 5500100
using namespace std;

ifstream is("raci.in");
ofstream os("raci.out");

struct {
    char a, b;
} x[M1];

int n, k, Lmax, l;
int L[M1];
char s[M2], ch;


int main()
{
    is >> n >> k;
    is.get(ch);
    is.getline(s, M2);
    l = strlen(s);
    n = 1;
    for ( int i = 0; i < l; ++i )
    {
        if ( s[i] == ' ' )
        {
            x[n++].b = s[i-1];
            x[n].a = s[i+1];
        }
    }
    x[1].a = s[0];
    x[n].b = s[l-1];

    for ( int i = 1; i <= n; ++i )
    {
        L[i] = 1;
        for ( int j = i-1; j >= 0; --j )
        {
            if ( x[j].b == x[i].a && i - j <= k && L[i] < L[j] + 1 )
            {
                L[i] = L[j]+1;
                Lmax = max(L[i], Lmax );
                break;
            }
        }
    }
    os << Lmax;
    is.close();
    os.close();
    return 0;
}
