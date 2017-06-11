#include <cstdio>
#include <fstream>
#include <vector>
using namespace std;

FILE * is = fopen("masina2.in", "r" );
ofstream os("masina2.out");

void Read();
void Write();
void Debug(int x);
void Pune ( int i, int j, int d );
int Dir();
bool Ok(int i, int j);

int n, m, k, d;
char c[52][52];
char dr[5];
const int d1[] = {-1, 0, 1, 0 };
const int d2[] = {0, 1, 0, -1 };
vector<pair<int, int > > a;
vector<pair<int, int > > b;

int main()
{
    Read();
    for ( int h = 0; h < k; ++h )
    {
        d = Dir();
        for ( int i = 0; i < a.size(); ++i )
            Pune(a[i].first, a[i].second, d );
        a = b;
        b.clear();
    }
    Write();
    fclose(is);
    os.close();
    return 0;
}
void Read()
{
    fscanf(is, "%d%d", &n, &m );
    for ( int i = 0; i < n; ++i )
    {
        fscanf(is, "%s", c[i] );
        if ( a.empty() )
            for ( int j = 0; j < m; ++j )
                if ( c[i][j] == '*' )
                {
                    c[i][j] = '.';
                    a.push_back(make_pair(i, j));
                    break;
                }
    }
    fscanf(is, "%d", &k);
}
void Debug(int x)
{
    if ( x == 2 )
        for ( int i = 0; i < b.size(); ++i )
            os << b[i].first << ' ' << b[i].second << '\n';
    else
        for ( int i = 0; i < a.size(); ++i )
            os << a[i].first << ' ' << a[i].second << '\n';
}
int Dir()
{
    fscanf(is, "%s", dr );
    switch ( dr[0] )
    {
        case 'N': return 0;
        case 'S': return 2;
        case 'E': return 1;
        case 'V': return 3;
    }
}
void Pune ( int i, int j, int d )
{
    i += d1[d];
    j += d2[d];
    while ( Ok(i, j) )
    {
        b.push_back(make_pair(i, j) );
        i += d1[d];
        j += d2[d];
    }
}
bool Ok(int i, int j)
{
    if ( i < 0 || j < 0 || i >= n || j >= m )
        return false;
    if ( c[i][j] == 'X' )
        return false;
    return true;
}
void Write()
{
    for ( int i = 0; i < a.size(); ++i )
        c[a[i].first][a[i].second] = '*';
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
            os << c[i][j];
        os << '\n';
    }
}
