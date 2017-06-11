#include <fstream>
#include <cstdio>
#include <queue>
using namespace std;

FILE * is = fopen("sahara.in", "r" );
ofstream os("sahara.out");

int n, m, q, Q, T, mx;
int x1, y1, x2, y2;
int a[1001][1001];
int b[1001][1001];
bool x[1001][1001];
const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};
queue<pair<int, int> > F;
void Fill();
bool Ok(int i, int j);

int main()
{
    //is >> n >> m >> Q >> T;
    fscanf(is, "%d%d%d%d", &n, &m, &Q, &T );
    for ( int t = 0; t < T; ++t )
    {
        //is >> x1 >> y1 >> x2 >> y2 >> q;
        fscanf(is, "%d%d%d%d%d", &x1, &y1, &x2, &y2, &q );
        b[x1][y1] += q;
        b[x1][y2+1] -= q;
        b[x2+1][y1] -= q;
        b[x2+1][y2+1] += q;

    }
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            a[i][j] = b[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( a[i][j] >= Q && !x[i][j] )
            {
                F.push( make_pair(i, j) );
                Fill();
            }
    os << mx;
    fclose(is);
    os.close();
    return 0;
}
void Fill()
{
    int i, j, iv, jv, nr = 0;
    while ( !F.empty() )
    {
        i = F.front().first;
        j = F.front().second;
        F.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i + d1[d];
            jv = j + d2[d];
            if ( Ok(iv, jv) )
            {
                x[iv][jv] = true;
                nr++;
                F.push( make_pair(iv, jv) );
            }
        }
    }
    mx = max(mx, nr);
}
bool Ok(int i, int j)
{
    if ( i < 1 || j < 1 || i > n || i > m )
        return false;
    if ( a[i][j] < Q )
        return false;
    if ( x[i][j] )
        return false;
    return true;
}
