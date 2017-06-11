#include <fstream>
using namespace std;

using namespace std;

ifstream is("a.in");
ofstream os("a.out");

long long x[100], n, s, nrsol;
void Part(int k);
void Afis(int k);

int main()
{
    is >> n;
    x[0] = 1;
    Part(1);
    os << nrsol;
    is.close();
    os.close();
    return 0;
}
void Part(int k)
{
    if ( s == n )
    {
        nrsol++;
        return;
    }
    if ( s > n ) return;
    for ( int i = x[k-1]; s + i <= n; ++i )
    {
        x[k] = i;
        s +=i;
        Part(k+1);
        s -=i;
    }
}
void Afis(int k)
{
    for ( int i = 1; i <= k; ++i )
        os << x[i] << ' ';
    os << '\n';
}
