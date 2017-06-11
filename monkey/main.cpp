#include <fstream>
using namespace std;

ifstream is("monkey.in");
ofstream os("monkey.out");

int n, m, mx, BIT;
const int d1[] = { -1, 0, 1, 0};
const int d2[] = { 0, 1, 0, -1};
char a[21][21];

void Back(int i, int j, int p);
bool Ok(int i, int j);
void B2(int x)
{
    if ( x == 0 )
    {
        os << '\n';
        return;
    }
    B2(x/2);
    os << x % 2;
}

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            is >> a[i][j];
    BIT |= 1 << (a[1][1]-65);
    Back(1, 1, 1);
    os << mx;
    is.close();
    os.close();
    return 0;
}
void Back(int i, int j, int p)
{
    mx = max(mx, p);
    int iv, jv;
    for ( int d = 0; d < 4; ++d )
    {
        iv = i + d1[d];
        jv = j + d2[d];
        if ( Ok ( iv, jv) )
        {
            BIT |= 1 << ( a[iv][jv]-65);
            Back(iv, jv, p+1);
            BIT ^= 1 << ( a[iv][jv]-65);
        }
    }
}
bool Ok(int i, int j)
{
    if ( i < 1 || j < 1 || i > n || j > m )
        return false;
    if ( BIT & ( 1 << (a[i][j]-65) ) )
        return false;
    return true;
}
