#include <fstream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("paianjen.in");
ofstream os("paianjen.out");
void Read();
void Debug();
void Lee();
bool Ok(int i, int j);
void Scrie(int i, int j);

int n, m, a[281][281], c[281][281];
const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};
int Ip, Jp, Is, Js;
queue<pair<int, int> > q;

struct {
    int i, j;
}x[281][281];

int main()
{
    Read();
    Lee();
    os << c[Is][Js] << '\n';
    Scrie( Is, Js );
    is.close();
    os.close();
    return 0;
}
void Read()
{
    int k;
    is >> n >> m >> Ip >> Jp >> Is >> Js >> k;
    Ip *=2;
    Jp *=2;
    Is *=2;
    Js *=2;
    for ( int i = 0; i <= n*2; ++i )
        for ( int j = 0; j <= m*2; ++j )
            c[i][j] = INF;
    q.push(make_pair(Ip, Jp));
    c[Ip][Jp] = 0;
    int i1, j1, i2, j2;
    for ( int i = 0; i < k; ++i )
    {
        is >> i1 >> j1 >> i2 >> j2;
        i1 *= 2;
        i2 *= 2;
        j1 *= 2;
        j2 *= 2;
        if ( i1 == i2 )
            for ( int j = j1+1; j < j2; j+= 2)
                a[i1][j] = 2;
        else
            for ( int j = i1+1; j < i2; j += 2 )
                a[j][j1] = 2;
    }
}
void Lee()
{
    int iv, jv, i, j;
    while(!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i + d1[d];
            jv = j + d2[d];
            if ( Ok ( iv, jv ) )
            {
                iv += d1[d];
                jv += d2[d];
                if ( Ok(iv, jv) && c[iv][jv] > c[i][j]+1 )
                {
                    c[iv][jv] = c[i][j] + 1;
                    q.push(make_pair(iv, jv));
                }
            }
        }
    }
}
bool Ok(int i, int j)
{
    if ( i < 0 || j < 0 || i >= (n*2)+1 || j >=(m*2)+1 )
        return false;
    if ( a[i][j] == 2 )
        return false;
    return true;
}
void Scrie(int i, int j)
{
    if ( i == Ip && j == Jp )
    {
        os << Ip/2 << ' ' << Jp/2 << '\n';
        return;
    }
    int iv, jv;
    for ( int d = 0; d < 4; ++d )
    {
        iv = i + d1[d];
        jv = j + d2[d];
        iv += d1[d];
        jv += d2[d];
        if ( iv >= 0 && jv >= 0 && iv < (n*2)+1 && jv < (m*2)+1 )
        {
            if ( c[iv][jv] == c[i][j]-1 )
            {
                Scrie(iv, jv);
                os<< i/2 << ' ' << j/2 << '\n';
                return;
            }
        }
    }
}
