#include <fstream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("soricel2.in");
ofstream os("soricel2.out");

void Read();
void Lee1(); // soarec
void Lee2(); // pisica
bool Ok(int i, int j );

int n, m, a[101][101], c1[101][101], c2[101][101], Ip, Jp, nr;
const int d1[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d2[] = {0, 1, 1, 1, 0, -1, -1, -1};
queue<pair<int, int> > Q1;
queue<pair<int, int> > Q2;
queue<pair<int, int> > Drum;

int main()
{
    Read();
    Lee1();
    Lee2();
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( a[i][j] == 1 && c1[i][j] != INF && c1[i][j]*2 < c2[i][j] )
            {
                nr++;
                Drum.push(make_pair(i, j));
            }
    os << nr << '\n';
    while ( !Drum.empty() )
    {
        os << Drum.front().first << ' ' << Drum.front().second << '\n';
        Drum.pop();
    }
    //Debug();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    memset(c1, 63, sizeof(c1) );
    memset(c2, 63, sizeof(c2) );
    is >> n >> m >> Ip >> Jp;
    Q1.push(make_pair(Ip, Jp));
    c1[Ip][Jp] = 0;
    is >> Ip >> Jp;
    Q2.push(make_pair(Ip, Jp));
    c2[Ip][Jp] = 0;
    int k;
    is >> k;
    for ( int i = 0; i < k; ++i )
    {
        int x, y;
        is >> x >> y;
        a[x][y] = 1;
    }
    is >> k;
    for ( int i = 0; i <k; ++i )
    {
        int x, y;
        is >> x >> y;
        a[x][y] = 2;
    }


}
void Lee1()
{
    int i, j, iv, jv;
    while ( !Q1.empty() )
    {
        i = Q1.front().first;
        j = Q1.front().second;
        Q1.pop();
        for ( int d = 0; d < 8; ++d )
        {
            iv = i+d1[d];
            jv = j+d2[d];
            if ( Ok(iv, jv) && c1[iv][jv] > c1[i][j] +1 )
            {
                c1[iv][jv] = c1[i][j] +1;
                Q1.push(make_pair(iv, jv));
            }
        }
    }
}
void Lee2()
{
    int i, j, iv, jv;
    while ( !Q2.empty() )
    {
        i = Q2.front().first;
        j = Q2.front().second;
        Q2.pop();
        for ( int d = 0; d < 8; ++d )
        {
            iv = i+d1[d];
            jv = j+d2[d];
            if ( Ok(iv, jv) && c2[iv][jv] > c2[i][j] +1 )
            {
                c2[iv][jv] = c2[i][j] +1;
                Q2.push(make_pair(iv, jv));
            }
        }
    }
}
bool Ok(int i, int j )
{
    if ( i < 1 || j < 1 || i > n || j > m )
        return false;
    if ( a[i][j] == 2 )
        return false;
    return true;
}
