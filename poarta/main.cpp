#include <fstream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

ifstream is("poarta.in");
ofstream os("poarta.out");

int n, m;
char a[101][101];
int c[101][101], k, Ip, Jp, Is, Js, d0, d1, d2;
queue<pair<int, int > > Q;

const int di[] = { -1, 0, 1, 0};
const int dj[] = { 0, 1, 0, -1};

void Read();
void Lee1();
void Lee2();
void Lee3();
void Debug();

int main()
{
    Read();
    Lee1();
    Lee2();
    Lee3();
    os << min(d0, d1+d2+1) << '\n';
    Debug();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m >> k >> Ip >> Jp >> Is >> Js;
    a[Ip][Jp] = 'P';
    a[Is][Js] = 'S';
    for ( int i = 0; i < k; ++i )
    {
        int x, y;
        is >> x >> y;
        a[x][y] = 'X';
    }
}
void Debug()
{
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= m; ++j )
        {
            if ( a[i][j] == 'P' )
                os << "P ";
            else if ( a[i][j] == 'S' )
                os << "S ";
            else if ( a[i][j] == 'X' )
                os << "X ";
            else
                os << "N ";
        }
        os << '\n';
    }
}
void Lee1()
{
    int i, j, iv, jv;
    memset(c, 63, sizeof(c) );
    c[Ip][Jp] = 0;
    Q.push(make_pair(Ip, Jp));
    while(!Q.empty())
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i+di[d];
            jv = j+dj[d];
            if ( iv > 0 && iv <= n && jv > 0 && iv <= m )
            {
                c[iv][jv] =c[i][j] + 1;
                if ( a[iv][jv] == 'X' )
                {
                    d1 = c[iv][jv];
                    return;
                }
                Q.push(make_pair(iv, jv));
            }
        }
    }
}
void Lee2()
{
    int i, j, iv, jv;
    memset(c, 63, sizeof(c) );
    c[Is][Js] = 0;
    while(!Q.empty())
        Q.pop();
    Q.push(make_pair(Is, Js));
    while(!Q.empty())
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i+di[d];
            jv = j+dj[d];
            if ( iv > 0 && iv <= n && jv > 0 && iv <= m )
            {
                c[iv][jv] =c[i][j] + 1;
                if ( a[iv][jv] == 'X' )
                {
                    d2 = c[iv][jv];
                    return;
                }
                Q.push(make_pair(iv, jv));
            }
        }
    }
}
void Lee3()
{
    int i, j, iv, jv;
    memset(c, 63, sizeof(c) );
    c[Ip][Jp] = 0;
    while(!Q.empty())
        Q.pop();
    Q.push(make_pair(Ip, Jp));
    while(!Q.empty())
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i+di[d];
            jv = j+dj[d];
            if ( iv > 0 && iv <= n && jv > 0 && iv <= m && a[iv][jv] != 'X')
            {
                c[iv][jv] =c[i][j] + 1;
                if ( a[iv][jv] == 'S' )
                {
                    d0 = c[iv][jv];
                    return;
                }
                Q.push(make_pair(iv, jv));
            }
        }
    }
}
