#include <fstream>
#define INF 0x3f3f3f3f
#define M 51
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int c[M], s, a, n;

int main()
{
    is >> s;
    for ( int i = 1; i < M; ++i )
        c[i] = INF;
    while ( is >> a )
        for ( int j = 0; j <= s-a; ++j )
            if ( c[j] != INF )
                if ( c[j+a] > c[j] + 1 )
                    c[j+a] = c[j]+1;
    if ( c[s] != INF )
        os << c[s];
    else
        os << "Imposibil";

    is.close();
    os.close();
    return 0;
}
