#include <fstream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("inginer.in");
ofstream os("inginer.out");

void Read();
void Lee();
void Debug();
bool Ok(int i, int j);

int n, m, c[77][77], Ip, Jp, Is, Js;
char a[77][77];
const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};
queue<pair<int, int> >Q;


int main()
{
    Read();
    is >> Ip >> Jp >> Is >> Js;
    while ( Ip != 0 || Jp != 0 || Is != 0 || Js != 0 )
    {
        memset(c, 63, sizeof(c) );
        Q.push(make_pair(Ip, Jp));
        c[Ip][Jp] = 0;
        a[Is][Js] = '.';
        Lee();
        a[Is][Js] = 'X';
        if ( c[Is][Js] == INF )
            os << "0\n";
        else
            os << c[Is][Js] << '\n';
        is >> Ip >> Jp >> Is >> Js;
    }
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m;
    n++;
    m++;
    for ( int i = 0; i <= m; ++i )
    {
        a[0][i] = '.';
        a[n][i] = '.';
    }
    for ( int i = 0; i <= n; ++i )
    {
        a[i][0] = '.';
        a[i][m] = '.';
    }
    for ( int i = 1; i < n; ++i )
        for ( int j = 1; j < m; ++j )
            is >> a[i][j];
}
void Lee()
{
    int i, j, iv, jv;
    while ( !Q.empty() )
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i+d1[d];
            jv = j+d2[d];
            if ( Ok(iv, jv) && c[iv][jv] > c[i][j]+1 )
            {
                c[iv][jv] = c[i][j]+1;
                Q.push(make_pair(iv, jv));
            }
        }
    }
}
bool Ok(int i, int j)
{
    if ( i < 0 || j < 0 || i > n || j > m )
        return false;
    if ( a[i][j] == 'X')
        return false;
    return true;
}
void Debug()
{
    for ( int i = 0; i <= n; ++i )
    {
        for ( int j =0; j <= m; ++j )
        {
            if ( a[i][j] == 'X' )
                os << "X ";
            else if ( c[i][j] == INF )
                os << "N ";
            else
                os << c[i][j] << ' ';
        }
        os << '\n';
    }
}
