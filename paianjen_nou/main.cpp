#include <cstdio>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

FILE * is = fopen("paianjen.in", "r");
ofstream os("paianjen.out");

void Read();
void Lee();
void Debug();
void Scrie(int i, int j);
bool Ok(int i, int j);

int n, m, c[141][141],Ip, Jp, Is, Js;
const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};
queue<pair<int, int> > Q;
struct {
    bool b[4];
}a[141][141];

int main()
{
    Read();
    Lee();
    os << c[Is][Js] << '\n';
    Scrie(Is, Js);
    fclose(is);
    os.close();
    return 0;
}
void Read()
{
    int k, aux;
    fscanf(is, "%d%d%d%d%d%d%d", &n, &m, &Ip, &Jp, &Is, &Js, &k );
    n--;
    m--;
    memset(a, 1, sizeof(a));
    int l1, c1, l2, c2;
    for ( int i = 0; i < k; ++i )
    {
        fscanf(is, "%d%d%d%d", &l1, &c1, &l2, &c2 );
        if ( l1 == l2 )
        {
            if ( c1 > c2 )
            {
                aux = c1;
                c1 = c2;
                c2 = aux;
            }
            for ( int j = c1; j < c2; ++j )
            {
                a[l1][j].b[1] = false;
                a[l1][j+1].b[3] = false;
            }
        }
        if ( c1 == c2 )
        {
            if ( l1 > l2 )
            {
                aux = l1;
                l1 = l2;
                l2 = aux;
            }
            for ( int j = l1; j < l2; ++j )
            {
                a[j][c1].b[2] = false;
                a[j+1][c1].b[0] = false;
            }
        }
    }

}
void Lee()
{
    int i, j, iv, jv;
    memset(c, 63, sizeof(c) );
    Q.push(make_pair(Ip, Jp));
    c[Ip][Jp] = 0;
    while ( !Q.empty() )
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i+d1[d];
            jv = j+d2[d];
            if ( Ok(iv, jv) && a[i][j].b[d] == true && c[iv][jv] > c[i][j] + 1)
            {
                c[iv][jv] = c[i][j] + 1;
                Q.push(make_pair(iv, jv));
            }
        }
    }
}
void Scrie(int i, int j)
{
    if ( i == Ip && j == Jp )
    {
        os << i << ' ' << j << '\n';
    }
    int iv, jv;
    for ( int d = 0; d < 4; ++d )
    {
        iv = i+d1[d];
        jv = j+d2[d];
        if ( Ok(iv, jv) && c[iv][jv] == c[i][j]-1 && a[i][j].b[d] == true )
        {
            Scrie(iv, jv);
            os << i << ' ' << j << '\n';
            return;
        }
    }
}
bool Ok(int i, int j)
{
    if ( i < 0 || j < 0 || i > n || j > m )
        return false;
    return true;
}
