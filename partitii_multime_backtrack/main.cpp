#include <fstream>
#include <algorithm>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

long long n, x[100], nrsol;
void Part(long long k, long long m);
void Afis(long long m);

int main()
{
    for ( int p = 1; p <= 25; ++p )
    {
        n = p;
        nrsol = 0;
        Part(1, 0);
        os << nrsol << '\n';
    }

    is.close();
    os.close();
    return 0;
}
void Part(long long k, long long m)
{
    if ( k == n +1 )
    {
        nrsol++;
        return;
    }
    for ( int i = 1; i <= m + 1; ++i )
    {
        x[k] = i;
        Part(k+1, max((long long)i, m));
    }

}
void Afis(long long m)
{
    for ( int i = 1; i <= m; ++i )
    {
        os << "{ ";
        for ( int j = 1; j <= n; ++j)
            if ( x[j] == i )
                os << j << ' ';
        os << "} ";
    }
    os << '\n';

}
