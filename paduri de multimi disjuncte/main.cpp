#include <fstream>
using namespace std;

ifstream is("disjoint.in");
ofstream os("disjoint.out");

int n, m, t[100001], r[100001];
int Tata(int x);
void Unesc(int x, int y);

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        t[i] = i, r[i] = 1;
    is
    is.close();
    os.close();
    return 0;
}
int Tata(int x)
{
    if ( t[x] = x )
        return x;
    int nr = Tata(t[x]);
    t[x] = nr;
    return nr;
}
void Unesc(int x, int y)
{
    if ( r[x] > r[y] )
        t[y] = x;
    else
        t[x] = y;
    if ( r[x] == r[y] )
        r[y]++;

}
