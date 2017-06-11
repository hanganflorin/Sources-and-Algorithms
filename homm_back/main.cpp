#include <fstream>
using namespace std;

ifstream is("homm.in");
ofstream os("homm.out");

int n, m, k, a[101][101], x[101][101];
int Ip, Jp, Is, Js, nr;
const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};

void Back(int i, int j, int p );
bool Ok(int i, int j);
void Print();

int main()
{
    is >> n >> m >> k;
    for( int i = 1; i <= n; ++i )
        for( int j = 1; j <= m; ++j )
            is >> a[i][j];
    is >> Ip >> Jp >> Is >> Js;
    Back(Ip, Jp, 1 );
    is.close();
    os.close();
    return 0;
}
void Back(int i, int j, int p )
{
    x[i][j] = p;
    if ( i == Is && j == Js )
    {
        nr++;
        Print();
    }

    int iv, jv;
    for (int d = 0; d < 4; ++d )
    {
        iv = i + d1[d];
        jv = j + d2[d];
        if ( Ok(iv, jv ) )
            Back(iv, jv, p+1);
    }
    x[i][j] = 0;
}
bool Ok(int i, int j)
{
    if ( i < 1 || j < 1 || i > n || j > m )
        return false;
    if ( a[i][j] )
        return false;
    if ( x[i][j] )
        return false;
    return true;
}
void Print()
{
    os << nr << '\n';
    for (int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= m; ++j )
            os << x[i][j] << ' ';
        os << '\n';
    }
}
