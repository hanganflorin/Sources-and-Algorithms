#include <fstream>
using namespace std;

int a[100][100], n, m, nr;
int b[100][100];
void Read();
void Fill(int i, int j);
bool Ok(int i, int j);

ifstream is("a.in");
ofstream os("a.out");

int main()
{
    Read();
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < n; ++j )
            if ( a[i][j] == 0 && b[i][j] == 0 )
            {
                nr++;
                Fill(i, j);
            }
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0;j < m; ++j )
            os << b[i][j] << " ";
        os << '\n';
    }
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
void Fill(int i, int j)
{
    if ( !Ok(i, j) ) return;
    b[i][j] = nr;
    Fill(i-1, j);
    Fill(i, j+1);
    Fill(i+1, j);
    Fill(i, j-1);
}
bool Ok(int i, int j)
{
    if ( i < 0 || j < 0 || i >= n || j >= m )
        return false;
    if ( a[i][j] == 1 )
        return false;
    if ( b[i][j] != 0 )
        return false;
    return true;
}
