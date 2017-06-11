#include <fstream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

ifstream is("lbd.in");
ofstream os("lbd.out");

void Read();
void Lee();
void Zile();
bool Ok(int i, int j);

int n, m, Ip = -1, Jp, Is, Js;
short c[1500][1500];
short d[1500][1500];
const short d1[] = {-1, 0, 1, 0};
const short d2[] = {0, 1, 0, -1};
char a[2250000];
queue <pair<int, int> > Q;
queue <pair<int, int> > X;

int main()
{
    Read();
    Zile();
    Lee();
    os << c[Is][Js];
    is.close();
    os.close();
    return 0;
}
void Read()
{
    int k = 0;
    memset(d, 63, sizeof(d) );
    is >> n >> m;
    is.get();
    is.getline(a, 2250000, EOF );
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
        {
            if ( a[k] == 'L' )
            {
                d[i][j] = 0;
                X.push(make_pair(i, j));
                if ( Ip == -1 )
                {
                    Ip = i;
                    Jp = j;
                }
                else
                {
                    Is = i;
                    Js = j;
                }
            }
            if ( a[k] == '.' )
            {
                X.push(make_pair(i, j));
                d[i][j] = 0;
            }
            k++;
        }
        k++;
    }
}
void Lee()
{
    memset(c, 63, sizeof(c) );
    Q.push(make_pair(Ip, Jp));
    c[Ip][Jp] = 0;
    int i, j, iv, jv;
    while ( !Q.empty() )
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int k = 0; k < 4; ++k )
        {
            iv = i+d1[k];
            jv = j+d2[k];
            if ( Ok(iv, jv) && c[iv][jv] > max(c[i][j], d[iv][jv] ) )
            {
                c[iv][jv] = max(c[i][j], d[iv][jv] );
                Q.push(make_pair(iv, jv));
            }
        }
    }
}
void Zile()
{
    int i, j, iv, jv;
    while ( !X.empty() )
    {
        i = X.front().first;
        j = X.front().second;
        X.pop();
        for ( int k = 0; k < 4; ++k )
        {
            iv = i+d1[k];
            jv = j+d2[k];
            if ( Ok(iv, jv) && d[iv][jv] > d[i][j]+1)
            {
                d[iv][jv] = d[i][j]+1;
                X.push(make_pair(iv, jv));
            }
        }
    }
}
bool Ok(int i, int j)
{
    if ( i < 0 || j < 0 || i >= n || j >= m )
        return false;
    return true;
}
