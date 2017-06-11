#include <fstream>
#include <algorithm>
#include<vector>
using namespace std;

ifstream is("bomboane.in");
ofstream os("bomboane.out");

int n, nr, dif, s, mn, mx, poz_mn, poz_mx;
int a[1001], b[1010][3];

struct Data{
    int p1, p2, dif;
} d;
vector<Data> V;

void Update();
void Read();
void Write();

int main()
{
    Read();
    if ( (s/n)*n != s )
    {
        os << -1;
        is.close();
        os.close();
        return 0;
    }
    s /= n;

    Update();
    while( mn != mx )
    {
        dif = min(a[poz_mx]-s, s-a[poz_mn]);

        a[poz_mn] += dif;
        a[poz_mx] -= dif;

        d.p1 = poz_mx;
        d.p2 = poz_mn;
        d.dif = dif;
        V.push_back(d);
        Update();
    }
    Write();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
        is >> a[i], s += a[i];
}
void Update()
{
    mn = 2000;
    mx = 0;
    for ( int i = 1; i <= n; ++i )
    {
        if ( a[i] > mx )
        {
            mx = a[i];
            poz_mx = i;
        }
        else if ( a[i] < mn )
        {
            mn = a[i];
            poz_mn = i;
        }
    }
}
void Write()
{
    os << nr << '\n';
    for ( int i = 0; i < nr; ++i )
        os << V[i].p1 << ' ' << V[i].p2 << ' ' << V[i].dif << '\n';
}
