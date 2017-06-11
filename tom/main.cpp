#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

ifstream is("tom.in");
ofstream os("tom.out");

void Read();
void LeeT();
void LeeJ();
bool Ok1(int i, int j);
bool Ok2(int i, int j);

int n, m, t[275][275], jr[275][275];
char a[257][257];
const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};
queue<pair<int, int> > T;
queue<pair<int, int> > J;
queue<pair<int, int> > Drum;

int main()
{
    Read();
    LeeT();
    LeeJ();
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( t[i][j] == jr[i][j]*2 )
                Drum.push(make_pair(i, j));
    //scrie
    os << Drum.size() << '\n';
    while ( !Drum.empty() )
    {
        os << Drum.front().first << ' ' << Drum.front().second << '\n';
        Drum.pop();
    }
    is.close();
    os.close();
    return 0;
}
void Read()
{
    memset(t, 63, sizeof(t) );
    memset(jr, 63, sizeof(jr) );
    is >> n >> m;
    for ( int i = 1; i <=n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            is >> a[i][j];
            if ( a[i][j] == 'T' )
            {
                t[i][j] = 0;
                T.push(make_pair(i, j));
            }
            if ( a[i][j] == 'J' )
            {
                jr[i][j] = 0;
                J.push(make_pair(i, j));
            }
        }
}
void LeeT()
{
    int i, j, iv, jv;
    while ( !T.empty() )
    {
        i = T.front().first;
        j = T.front().second;
        T.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i+d1[d];
            jv = j+d2[d];
            if ( Ok1(iv, jv) && t[iv][jv] > t[i][j] + 1)
            {
                t[iv][jv] = t[i][j] + 1;
                t[iv][jv] = t[i][j] + 1;
                T.push(make_pair(iv, jv));
            }
        }
    }
}
void LeeJ()
{
    int i, j, iv, jv;
    while ( !J.empty() )
    {
        i = J.front().first;
        j = J.front().second;
        J.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i+d1[d];
            jv = j+d2[d];
            if ( Ok2(iv, jv) && jr[iv][jv] > jr[i][j] + 1)
            {
                jr[iv][jv] = jr[i][j] + 1;
                J.push(make_pair(iv, jv));
            }
        }
    }
}
bool Ok1(int i, int j)
{
    if ( i < 1 || j < 1 || i > n || j > m )
        return false;
    if ( a[i][j] == 'P' || a[i][j] == 'C' )
        return false;
    return true;
}
bool Ok2(int i, int j)
{
    if ( i < 1 || j < 1 || i > n || j > m )
        return false;
    if ( a[i][j] == 'P' )
        return false;
    return true;
}
