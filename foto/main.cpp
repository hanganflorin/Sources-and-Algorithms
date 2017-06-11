#include <fstream>
using namespace std;

ifstream is("foto.in");
ofstream os("foto.out");

int n, m, a[101][101], c[101][101], nr = 1, s[3000], mx;

void Read();
void Fill ( int i, int j );
bool Ok(int i, int j);
void Debug();

int main()
{
    Read();
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
            if (a[i][j] == 0 && c[i][j] == 0 )
            {
                Fill(i, j);
                if ( s[nr] > mx )
                    mx = s[nr];
                nr++;
            }
    os << mx;
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m;
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
            is >> a[i][j];
}
void Fill ( int i, int j )
{
    if ( !Ok(i, j) ) return;
    c[i][j] = nr;
    s[nr]++;
    Fill (i-1, j);
    Fill (i, j+1);
    Fill (i+1, j);
    Fill (i, j-1);
}
bool Ok(int i, int j)
{
    if ( i < 0 || j < 0 || i >= n || j >= m )
        return false;
    if ( c[i][j] != 0 )
        return false;
    if ( a[i][j] == 1 )
        return false;
    return true;
}
void Debug()
{
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
            os << c[i][j] << ' ';
        os << '\n';
    }
    os << '\n';
    for ( int i = 1; i <= nr; ++i )
        os << s[i] << ' ';
}
