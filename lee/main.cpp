#include <fstream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
#include<iomanip>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

void Read();
void Lee();
void Scrie(int i, int j);
void Debug();
bool Ok(int i, int j);

int n, m, c[100][100], Ip, Jp, Is, Js;
const int d1[] = {-1, 0, 1, 0};
const int d2[] = { 0, 1, 0, -1};
char a[100][100];
queue<pair<int, int> > Q;

int main()
{
    Read();
    Lee();
    Scrie(Is, Js);
    //Debug();
    //os << c[Is][Js];
    is.close();
    os.close();
    return 0;
}
void Read()
{
    memset(c, 63, sizeof(c) );
    is >> n >> m;
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
        {
            is >> a[i][j];
            if ( a[i][j] == 'P' )
            {
                c[i][j] = 0;
                Q.push(make_pair(i, j));
                Ip = i;
                Jp = j;
            }
            if ( a[i][j] == 'S' )
            {
                Is = i;
                Js = j;
            }
        }
}
void Lee()
{
    int i, j, iv, jv;
    while(!Q.empty() )
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i+d1[d];
            jv = j+d2[d];
            if ( Ok(iv, jv) && c[iv][jv] > c[i][j]+1)
            {
                c[iv][jv] = c[i][j]+1;
                Q.push(make_pair(iv, jv));
            }
        }
    }
}
void Scrie(int i, int j)
{
    if ( c[i][j] == 0 )
    {
        os << i << ' ' << j << '\n';
        return;
    }
    for ( int d = 0; d < 4; ++d )
    {
        int iv = i+d1[d];
        int jv = j+d2[d];
        if ( Ok(iv, jv) && c[iv][jv] == c[i][j]-1 )
        {
            Scrie(iv, jv);
            os << i << ' ' << j << '\n';
            return;
        }
    }
}
void Debug()
{
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
        {
            if ( c[i][j] == INF )
                os << setw(3) << "X";
            else if ( a[i][j] == '#' )
                os << setw(3) << "#";
            else
                os << setw(3) << c[i][j];
        }
        os << '\n';
    }
}
bool Ok(int i, int j)
{
    if ( i < 0 || j < 0 || i >= n || j >= n )
        return false;
    if ( a[i][j] == '#' )
        return false;
    return true;
}
