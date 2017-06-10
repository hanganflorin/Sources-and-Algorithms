#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#define M 193000
using namespace std;

ifstream is("banana.in");
ofstream os("banana.out");

int nr, k, sm;
int x, y, n, m, dim = 1, p;
int c[10002][10002];
bool a[10002][10002];
char ch[193000];
vector<int> s;
queue<pair<int, int> > Q;

void Fill();
bool Ok(int i, int j);
void Maxim(int x);
void GetX(int &x);
void GetY(int &y);

int main()
{
    is >> nr >> k;
    is.get();
    is.get(ch, M, EOF);
    for ( int i = 1; i <= nr; ++i )
    {
        x = 0;
        y = 0;
        GetX(x);
        GetY(y);
        a[x][y] = true;
        n = max(n, x);
        m = max(m, y);
    }
    s.push_back(0);
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( a[i][j] && c[i][j] == 0 )
            {
                s.push_back(0);
                Fill(i, j);
                dim++;
            }
    sort(s.begin(), s.end() );
    while ( k )
    {
        sm += s[dim-1];
        dim--;
        k--;
    }
    os << sm;
    is.close();
    os.close();
    return 0;
}
void Fill(int i, int j)
{
    if ( !Ok(i, j) ) return;
    c[i][j] = dim;
    s[dim]++;
    Fill(i-1, j);
    Fill(i, j+1);
    Fill(i+1, j);
    Fill(i, j-1);

}
bool Ok(int i, int j )
{
    if ( i < 1 || j < 1 || i > n || j > m ) return false;
    if ( a[i][j] == false ) return false;
    if ( c[i][j] != 0 ) return false;
    return true;
}
void GetX(int &x)
{
    while( ch[p] != ' ')
    {
        x = x * 10 + ch[p]-48;
        p++;
    }
}
void GetY(int &y)
{
    p++;
    while( ch[p] != '\n')
    {
        y = y * 10 + ch[p]-48;
        p++;
    }
    p++;
}
