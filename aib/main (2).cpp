#include <fstream>
using namespace std;

ifstream is("aib.in");
ofstream os("aib.out");

int n, m, aib[100001], op, a, b;

void Update(int p, int v)
{
    for ( int i = p; i <= n; i += i & -i )
        aib[i] += v;
}
int Query(int p)
{
    int s = 0;
    for ( int i = p; i; i -= i & -i )
        s += aib[i];
    return s;
}
/*
int Bs(int s)
{
    int st = 1, dr = n, mid;
    while( st < dr )
    {
        mid = (dr+st)/2;
        if ( Query(mid) >= s )
            dr = mid;
        else
            st = mid+1;
    }
    return Query(st) == s ? st : -1;
}
*/
int Bs(int s)
{
    int i = 0;
    for ( int p = 1 << 17; p; p >>= 1 )
    {
        if ( i+p <= n && Query(i+p) <= s )
            i += p;
    }
    if ( Query(i) == s && i != 0)
        return i;
    return -1;

}

int main()
{
    is >> n >> m;
    for ( int i = 1, nr; i <= n; ++i )
    {
        is >> nr;
        Update(i, nr);
    }
    while ( m-- )
    {
        is >> op;
        if ( op == 0 )
        {
            is >> a >> b;
            Update(a, b);
        }
        else if ( op == 1 )
        {
            is >> a >> b;
            os << Query(b) - Query(a-1) << '\n';
        }
        else
        {
            is >> a;
            os << Bs(a) << '\n';
        }

    }
    is.close();
    os.close();
    return 0;
}
