#include <fstream>
#include <queue>
#include <cstring>
#include <iomanip>
#define M 1000
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int n, m, c[M][M], Ip, Jp, Is, Js;
const int d1[] = { -1, 0, 1, 0 };
const int d2[] = { 0, 1, 0, -1 };
char a[M][M];
queue<pair<int, int > > Q;

void Read();
void Lee();
bool Ok(int i, int j);
void Debug();

int main()
{
    Read();
    Lee();
    os << c[Is][Js] << '\n';
    Debug();
    return 0;
}
void Read()
{
    is >> n >> m >> Ip >> Jp >> Is >> Js;
    for ( int i = 0; i < n; ++i )
        is >> a[i];
}
void Lee()
{
    memset(c, 63, sizeof(c) );
    c[Ip][Jp] = 0;
    Q.push(make_pair(Ip, Jp));
    int i, j, iv, jv;
    while(!Q.empty())
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0;d < 4; ++d )
        {
            iv = i + d1[d];
            jv = j + d2[d];
            if ( Ok(iv, jv) && c[iv][jv] > c[i][j] + 1 )
            {
                c[iv][jv] = c[i][j] + 1;
                Q.push(make_pair(iv, jv));
            }
        }
    }

}
bool Ok(int i, int j)
{
    if ( i < 0 || j < 0 || i >= n || j >= m )
        return false;
    if ( a[i][j] == '-')
        return false;
    return true;
}
void Debug()
{
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
        {
            if ( c[i][j] == 0x3f3f3f3f )
                os << setw(3) << "N";
            else
                os << setw(3) << c[i][j];
        }
        os << '\n';
    }
}
