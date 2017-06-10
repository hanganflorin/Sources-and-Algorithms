#include <fstream>
#include <cstring>
#include <queue>
#include <iomanip>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("abq.in");
ofstream os("abq.out");

void Read();
void Lee();
bool Ok(int i, int j);
void Debug();

int n, m, c[202][202], Ip, Jp, Is, Js, k;
char a[202][202];
queue<pair<int, int> > Q;
const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};

int main()
{
    Read();
    is >> k;
    for ( int i = 0; i < k; ++i )
    {

        is >> Ip >> Jp >> Is >> Js;
        Ip--;
        Jp--;
        Is--;
        Js--;
        if ( a[Ip][Jp] == 'b' || a[Is][Js]== 'b' )
            os << "-1\n";
        else
        {
            memset(c, 63, sizeof(c));
            Q.push(make_pair(Ip, Jp));
            c[Ip][Jp] = 1;
            Lee();
            if ( c[Is][Js] == INF || a[Ip][Jp] == 'b' )
                os << "-1\n";
            else
                os << c[Is][Js] << '\n';
        }


    }
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m;
    is.get();
    for ( int i = 0; i < n; ++i )
    {
        is >> a[i];
        if ( strlen(a[i]) != m )
        {
            char g[] = "a";
            strcpy(a[i], g);
        }
    }

}
void Lee()
{
    int i, j, iv, jv;
    while (!Q.empty() )
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i+d1[d];
            jv = j+d2[d];
            if ( Ok(iv, jv) && c[iv][jv] > c[i][j] +1 )
            {
                c[iv][jv] = c[i][j]+1;
                Q.push(make_pair(iv, jv));
            }
        }
    }
}
bool Ok(int i, int j)
{
    if ( i < 0 || j < 0 || i >= n || j >= m )
        return false;
    if ( a[i][j] == 'b' )
        return false;
    return true;
}
void Debug()
{
    os << '\n';
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= m; ++j )
        {
            if ( a[i][j] == 'b' )
                os <<setw(3)<< "b";
            else if ( c[i][j] == INF )
                os <<setw(3)<< "N";
            else
                os <<setw(3)<< c[i][j];
        }
        os << '\n';
    }
}
