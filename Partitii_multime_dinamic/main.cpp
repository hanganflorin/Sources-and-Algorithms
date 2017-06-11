#include <fstream>
using namespace std;

using namespace std;

ifstream is("a.in");
ofstream os("a.out");

long long n, s;
long long nr[100][100];
void Dinamica();

int main()
{
    is >> n;
    Dinamica();
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= n; ++j )
            os << nr[i][j] << ' ';
        os << '\n';
    }
    is.close();
    os.close();
    return 0;
}
void Dinamica()
{
    for ( int i = 1; i <= n; ++i )
    {
        nr[i][i] = 1;
        nr[1][i] = 1;
    }
    for ( int i = 2; i <= n; ++i )
        for ( int j = i + 1; j <= n; ++j )
            nr[i][j] = nr[i-1][j-1] + nr[i][j-1] * i;
}
