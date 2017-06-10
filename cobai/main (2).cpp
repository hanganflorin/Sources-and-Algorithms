#include <fstream>
#include <queue>
#include <cstring>
#include <iomanip>
#define OK ( i > 0 && j > 0 && i <=n && j <= m)
using namespace std;

ifstream is("cobai.in");
ofstream os("cobai.out");

int n, m, camere, L, nr;
char c[51][51], dr[1001];
const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};
queue<pair<int, int> > Q1, Q2;

void Read();
void Solve();
void Pune(int i, int j, int dir);
int Directie(char c);

int main()
{
    Read();
    Solve();
    os << Q1.size();
    //nr = Q1.size() * 100;
    //os  << fixed << setprecision(2) << ((double)nr/camere);
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            is >> c[i][j];
            if (c[i][j] == '.')
                camere++;
            if ( c[i][j] == '*' )
                Q1.push(make_pair(i, j));
        }
    is >> dr;
    L = strlen(dr);
}
void Solve()
{
    int i, j;
    for ( int k = 0; k < 2; ++k )
    {
        while(!Q1.empty())
        {
            i = Q1.front().first;
            j = Q1.front().second;
            Q1.pop();
            Pune(i, j, Directie(dr[k]) );
        }
        swap(Q1, Q2);
    }
}
int Directie(char c)
{
    switch ( c )
    {
        case 'N': return 0;
        case 'E': return 1;
        case 'S': return 2;
        case 'V': return 3;
    }
}
void Pune(int i, int j, int dir)
{
    i += d1[dir];
    j += d2[dir];
    while ( OK && c[i][j] == '.')
    {
        Q2.push(make_pair(i, j));
        i += d1[dir];
        j += d2[dir];
    }
}
