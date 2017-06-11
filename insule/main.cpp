#include <fstream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("insule.in");
ofstream os("insule.out");
void Read();
void Lee();
void Fill(int i, int j, int x);
bool Ok( int i, int j, int x );
bool Ok3( int i, int j, int x);
bool Ok2( int i, int j);
queue<pair<int, int> > Q;

char s[101][101];
bool a1[101][101];
bool a2[101][101];
bool a3[101][101];
int c[101][101];

const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};

int n, m, nr1, nr2, nr3, nr;

int main()
{
    Read();
    nr = INF;
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
        {
            if ( s[i][j] == '1' && a1[i][j] == false )
            {
                nr1++;
                Fill(i, j, 1);
            }
            else if ( s[i][j] == '2' && a2[i][j] == false )
            {
                nr2++;
                Fill(i, j, 2);
            }
            else if ( s[i][j] == '3' && a3[i][j] == false )
            {
                nr3++;
                Fill(i, j, 3);
            }
        }
    os << nr1 << " " << nr2 << " " << nr3 << ' ';
    //2
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
            c[i][j] = INF;

    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
            if ( s[i][j] == '0' )
                for ( int d = 0; d < 4; ++d )
                    if ( Ok3(i + d1[d], j + d2[d], 1) )
                    {
                        Q.push(make_pair(i, j));
                        c[i][j] = 1;
                        break;
                    }
    Lee();
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
            if ( s[i][j] == '0' )
                for ( int d = 0; d < 4; ++d )
                    if ( Ok3(i + d1[d], j + d2[d], 2) )
                    {
                        if ( c[i][j] < nr )
                            nr = c[i][j];
                        break;
                    }
    os << nr;
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m;
    for ( int i = 0; i < n; ++i )
        is >> s[i];
}
void Fill(int i, int j, int x)
{
    if ( !Ok(i, j, x) ) return;
    switch ( x )
    {
        case 1: a1[i][j] = true; break;
        case 2: a2[i][j] = true; break;
        case 3: a3[i][j] = true; break;
    }
    Fill(i-1, j, x);
    Fill(i, j+1, x);
    Fill(i+1, j, x);
    Fill(i, j-1, x);
}
bool Ok( int i, int j, int x )
{
    if ( i < 0 || j < 0 || i >= n || j >= m )
        return false;
    if ( s[i][j] - 48 != x )
        return false;
    if ( x == 1 && a1[i][j] == true )
        return false;
    else if ( x == 2 && a2[i][j] == true )
        return false;
    else if ( x == 3 && a3[i][j] == true )
        return false;
    return true;
}
bool Ok3( int i, int j, int x)
{
    if ( i < 0 || j < 0 || i >= n || j >= m )
        return false;
    if ( x == 1 && s[i][j] != '1' )
        return false;
    if ( x == 2 && s[i][j] != '2' )
        return false;
    return true;
}
void Lee()
{
    int i = 0;
    int j = 0;
    int iv = 0;
    int jv = 0;
    while ( ! Q.empty() )
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i + d1[d];
            jv = j + d2[d];
            if ( Ok2(iv, jv) && c[iv][jv] > c[i][j] +1 )
            {
                c[iv][jv] = c[i][j]+1;
                Q.push(make_pair(iv, jv));
            }
        }
    }
}
bool Ok2( int i, int j)
{
    if ( i < 0 || j < 0 || i >= n || j >= m )
        return false;
    if ( s[i][j] != '0' )
        return false;
    return true;
}
