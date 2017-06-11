#include <fstream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("rj.in");
ofstream os("rj.out");

int n, m, ir, jr, ij, jj;
int r[102][102], jl[102][102];
queue <pair<int, int> > R;
queue <pair<int, int> > J;
char a[102][102];

const int d1[] = { -1, -1, 0, 1, 1, 1, 0, -1};
const int d2[] = { 0, 1, 1, 1, 0, -1, -1, -1};

void Lee(int X);
void Read();
bool Ok(int i, int j, int x );
void Write();

int main()
{
    Read();
    Lee(1);
    Lee(2);
    Write();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    memset(r, 63, sizeof(r) );
    memset(jl, 63, sizeof(jl) );

    is >> n >> m;
    is.get();
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
        {
            a[i][j] = is.get();
            if ( a[i][j] == 'R' )
            {
                ir = i;
                jr = j;
                R.push(make_pair(i, j) );
                r[i][j] = 1;
            }
            if ( a[i][j] == 'J' )
            {
                ij = i;
                jj = j;
                J.push(make_pair(i, j) );
                jl[i][j] = 1;
            }
        }
        is.get();
    }
}
void Lee(int X)
{
    int i, j, iv, jv;
    if ( X == 1 )
    {
        while ( !R.empty() )
        {
            i = R.front().first;
            j = R.front().second;
            R.pop();
            for ( int d = 0; d < 8; ++d )
            {
                iv = i+d1[d];
                jv = j+d2[d];
                if ( Ok(iv, jv, X) && r[iv][jv] > r[i][j] + 1 )
                {
                    r[iv][jv] = r[i][j] + 1;
                    R.push(make_pair(iv, jv) );
                }

            }
        }
    }
    else
    {
        while ( !J.empty() )
        {
            i = J.front().first;
            j = J.front().second;
            J.pop();
            for ( int d = 0; d < 8; ++d )
            {
                iv = i+d1[d];
                jv = j+d2[d];
                if ( Ok(iv, jv, X) && jl[iv][jv] > jl[i][j] + 1 )
                {
                    jl[iv][jv] = jl[i][j] + 1;
                    J.push(make_pair(iv, jv) );
                }

            }
        }
    }
}
bool Ok(int i, int j, int x )
{
    if ( i < 0 || j < 0 || i >= n || j >= m )
        return false;
    if ( a[i][j] == 'X' )
        return false;
    if ( x == 1 && a[i][j] == 'J' )
        return false;
    if ( x == 2 && a[i][j] == 'R' )
        return false;
    return true;
}
void Write()
{
    int t = INF, p1, p2;
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j )
            if ( r[i][j] == jl[i][j] && r[i][j] != INF && r[i][j] < t)
            {
                t = r[i][j];
                p1 = i+1;
                p2  =j+1;
            }
    os << t << ' ' << p1 << ' ' << p2;
}
