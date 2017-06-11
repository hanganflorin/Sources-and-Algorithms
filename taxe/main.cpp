#include <fstream>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//0 -1 5 90 81 -1 7 39 671 2703

ifstream is("taxe.in");
ofstream os("taxe.out");

void Read();
void Lee();
void Debug();
bool Ok(int i, int j );

int n, S, c[101][101], a[101][101];
const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};
queue<pair<int, int> > Q;

int main()
{
    Read();
    Lee();
    if ( S - c[n-1][n-1] < 0 )
        cout << -1;
    else
        cout << S - c[n-1][n-1];
    is.close();
    os.close();
    return 0;
}
void Read()
{
    memset(c, 63, sizeof(c) );
    Q.push(make_pair(0, 0));
    is >> S >> n;
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < n; ++j )
            is >> a[i][j];
    c[0][0] = a[0][0];
}
void Lee()
{
    int i, j, iv, jv;
    while(!Q.empty() )
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i+d1[d];
            jv = j+d2[d];
            if ( Ok(iv, jv) && c[iv][jv] > c[i][j] + a[iv][jv] )
            {
                c[iv][jv] = c[i][j] + a[iv][jv];
                Q.push(make_pair(iv, jv));
            }
        }
    }
}
bool Ok(int i, int j )
{
    if ( i < 0 || j < 0 || i >= n || j >= n )
        return false;
    return true;
}
void Debug()
{
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < n; ++j )
            os << a[i][j] << ' ';
        os << '\n';
    }
    os << '\n';
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < n; ++j )
            os << c[i][j] << ' ';
        os << '\n';
    }
}
