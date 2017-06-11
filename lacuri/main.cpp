#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

ifstream is("lacuri.in");
ofstream os("lacuri.out");

void Read();
void Fill(int i, int j);
void Lee();
void Scrie(int i, int j);
bool Ok(int i, int j );
bool Ok2(int i, int j );
bool Patrat( int x);

int n, a[101][101], c[101][101], cnt, cost[101][101];
const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};
queue<pair<int, int> > Q;
int lacuri;

struct {
    int x, i, j;
}s[2600];

int main()
{
    Q.push(make_pair(1, 1));
    memset(cost, 63, sizeof(cost) );
    cost[1][1] = 0;
    Read();
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= n; ++j )
            os << a[i][j];
        os << '\n';
    }
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            if ( a[i][j] == 1 && c[i][j] == 0 )
            {
                cnt++;
                s[cnt].i = i;
                s[cnt].j = j;
                Fill(i, j);
            }
    //verifica
    lacuri = cnt;
    for ( int i = 1; i <= cnt; ++i )
    {
        if ( !Patrat(s[i].x))
        {
            lacuri--;
        }
        else
        {
            for ( int j = 1; j*j < s[i].x; ++j )
                if ( a[s[i].i + j][s[i].j] != a[s[i].i][s[i].j + j] )
                {
                    lacuri--;
                    break;
                }
        }
    }
    if ( lacuri == cnt )
    {
        Lee();
        os << cnt << '\n';
        Scrie(n, n);
    }
    else
        os << lacuri;
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            is >> a[i][j];
}
void Fill(int i, int j)
{
    if ( !Ok(i, j) ) return;
    c[i][j] = cnt;
    s[cnt].x++;
    Fill(i-1, j);
    Fill(i, j+1);
    Fill(i+1, j);
    Fill(i, j-1);
}
bool Ok(int i, int j )
{
    if ( i < 1 || j < 1 || i > n || j > n )
        return false;
    if ( c[i][j] != 0 )
        return false;
    if ( a[i][j] == 0 )
        return false;
    return true;
}
bool Ok2(int i, int j )
{
    if ( i < 1 || j < 1 || i > n || j > n )
        return false;
    if ( a[i][j] == 1 )
        return false;
    return true;
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
            iv = i + d1[d];
            jv = j + d2[d];
            if ( Ok2(iv, jv) && cost[iv][jv] > cost[i][j]+1 )
            {
                cost[iv][jv] = cost[i][j]+1;
                Q.push(make_pair(iv, jv));
            }
        }
    }
}
void Scrie(int i, int j)
{
    if ( i == 1 && j == 1 )
    {
        os << "1 1\n";
        return;
    }
    for ( int d = 0; d < 4; ++d )
    {
        int iv = i+d1[d];
        int jv = j+d2[d];
        if ( Ok2(iv, jv) && cost[iv][jv] == cost[i][j]-1 )
        {
            Scrie(iv, jv);
            os << i << ' ' << j << '\n';
            return;
        }
    }
}
bool Patrat( int x)
{
    if ( x == 1 ) return true;
    for ( int i = 1; i <= x/2; ++i )
    {
        if ( i*i == x )
            return true;
        if ( i*i > x )
            return false;
    }
    return false;
}
