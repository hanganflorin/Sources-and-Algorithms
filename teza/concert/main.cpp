#include <fstream>
#include <algorithm>
using namespace std;

ifstream is("concert.in");
ofstream os("concert.out");

int n, t, nr, s, aux[101];
pair<int, int> a[101];
char ch;

int main()
{
    is >> n >> t;
    for ( int i = 0, m, s; i < n; ++i )
    {
        is >> m >> ch >> s;
        a[i].first = 60*m + s;
        a[i].second = i+1;
    }
    sort(a, a+n);
    while( s + a[nr].first < t )
    {
        s += a[nr].first;
        aux[nr] = a[nr++].second;
    }
    sort(aux, aux+nr);
    os << nr << '\n';
    for ( int i = 0; i < nr; ++i )
        os << aux[i] << ' ';
    is.close();
    os.close();
    return 0;
}
