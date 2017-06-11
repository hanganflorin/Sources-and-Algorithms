#include <fstream>
#include <queue>
using namespace std;

ifstream is("homm.in");
ofstream os("homm.out");

const int x1[] = { -1, 0, 1, 0 };
const int x2[] = { 0, 1, 0, -1 };
bool Ok(int i, int j);
void Din();

queue< pair <int, int > > Q;
queue< pair <int, int > > Q2;

int n, m, K, Is, Js, Ip, Jp, s, aux = 1;
int a[101][101], d[101][101][21];

int main()
{
    is >> n >> m >> K;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            is >> a[i][j];
    is >> Ip >> Jp >> Is >> Js;

    Q.push(make_pair(Ip, Jp));
    Q2.push(make_pair(Ip, Jp));
    Din();

    for ( int k = 1; k < 10; ++k )
    {
        os << k << '\n';
        for ( int i = 1; i <= n; ++i )
        {
            for ( int j = 1; j <= m; ++j )
                os << d[i][j][k] << ' ';
            os << '\n';
        }
        os << '\n';
    }

    is.close();
    os.close();
    return 0;
}
bool Ok(int i, int j)
{
    if ( i < 1 || j < 1 || i > n || j > m )
        return false;
    if ( a[i][j] )
        return false;
    if ( Q2.front().first = i && Q2.front().second == j )
    {
        Q2.pop();
        return false;
    }
    return true;
}
void Din()
{
    int i, j, k, iv, jv;
    while(aux < 10)
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int x = 0; x < 4; ++x )
        {
            iv = i + x1[x];
            jv = j + x2[x];
            if ( Ok(iv, jv) )
            {
                d[iv][jv][aux]++;
                Q.push(make_pair(iv, jv));
                Q2.push(make_pair(iv, jv));
            }
        }
        aux++;
    }
}
