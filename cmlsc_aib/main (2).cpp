#include <fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int n, x[100];
int L[100];

int main()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
        is >> x[i];

    for ( int i = 1; i <= n; ++i )
    {
        L[i] = 1;
        for ( int j = 1; j < i; ++j )
            if ( x[j] < x[i] && L[i] < L[j]+1)
                L[i] = L[j]+1;
    }
    for ( int i = 1; i <= n; ++i )
        os << L[i] << ' ';
    is.close();
    os.close();
    return 0;
}
