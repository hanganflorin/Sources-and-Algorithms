#include <fstream>
#include <cstring>
using namespace std;

ifstream is("gradina.in");
ofstream os("gradina.out");

void Read();
void Directii(int nr);
void Pune(int i, int j, int dir );
void Fill(int i, int j);
bool Ok(int i, int j);
void Print();
void Debug();

bool dir[4];
int n, m, cnt;
int a[43][43];
int b[43][43];
int s[101];
int aria;
//maxime
int mx; //suprafata max
int amax; // aria max dupa unire
int i_max, j_max, dir_max;

int main()
{
    Read();
    //fill
    for ( int i = 0; i <= 2*n; ++i )
        for ( int j = 0; j <= 2*m; ++j )
            if ( a[i][j] <= 1 && b[i][j] == 0 )
            {
                cnt++;
                Fill(i, j);
            }
    //aria maxima
    for ( int i = 1; i < n*2; i +=2 )
        for ( int j = 1; j < (m-1)*2; j +=2)
        {
            //E
            int iv = i;
            int jv = j+2;
            if ( b[i][j] != b[iv][jv] )
            {
                aria = s[b[i][j]] + s[b[iv][jv]];
                if ( aria > amax )
                {
                    amax = aria;
                    i_max = i;
                    j_max = j+1;
                    dir_max = 1;
                }
            }
        }
    for ( int i = 1; i < n*2; i +=2 )
        for ( int j = 1; j < (m-1)*2; j +=2)
        {
            //S
            int iv = i+2;
            int jv = j;
            if ( b[i][j] != b[iv][jv] )
            {
                aria = s[b[i][j]] + s[b[iv][jv]];
                if ( aria > amax )
                {
                    amax = aria;
                    i_max = i+1;
                    j_max = j;
                    dir_max = 2;
                }
            }
        }
    if ( i_max % 2 == 1 )
        i_max++;
    if ( j_max % 2 == 1 )
        j_max++;
    Print();
    //Debug();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    int v;
    is >> n >> m;
    for ( int i = 0; i <= n*2; ++i )
    {
        if ( i % 2 == 0)
            for ( int j = 0; j < 2*m; ++j )
                a[i][j] = 1;
        else
            for ( int j = 0; j <= 2*m; j += 2 )
                a[i][j] = 1;
    }

    for ( int i = 1; i < n*2; i += 2 )
        for ( int j = 1; j < m*2; j += 2 )
        {
            is >> v;
            Directii(v);
            for ( int d = 0; d < 4; ++d )
                if ( dir[d] )
                    Pune(i, j, d);
        }
}
void Directii(int nr)
{
    memset(dir, false, sizeof(dir) );
    if ( nr != 0 )
    {
        if ( nr != 0 && nr >= 8 )
        {
            nr -= 8;
            dir[2] = true;
        }
        if ( nr != 0 && nr >= 4 )
        {
            nr -= 4;
            dir[1] = true;
        }
        if ( nr != 0 && nr >= 2 )
        {
            nr -= 2;
            dir[0] = true;
        }
        if ( nr != 0 && nr >= 1 )
        {
            nr -= 1;
            dir[3] = true;
        }
    }
}
void Pune(int i, int j, int dir )
{
    if ( dir == 0 )
        for (int k = j-1; k <= j+1; ++k )
            a[i-1][k] = 2;
    else if ( dir == 1 )
        for (int k = i-1; k <= i+1; ++k )
            a[k][j+1] = 2;
    else if ( dir == 2 )
        for (int k = j-1; k <= j+1; ++k )
            a[i+1][k] = 2;
    else
        for (int k = i-1; k <= i+1; ++k )
            a[k][j-1] = 2;

}
void Fill(int i, int j)
{
    if ( !Ok(i, j) ) return;
    b[i][j] = cnt;
    if ( a[i][j] == 0 )
    {
        s[cnt]++;
        if ( s[cnt] > mx )
            mx = s[cnt];
    }
    Fill(i-1, j);
    Fill(i, j+1);
    Fill(i+1, j);
    Fill(i, j-1);
}
bool Ok(int i, int j)
{
    if ( i < 0 || j < 0 || i >= 2*n+1 || j >= 2*m+1 )
        return false;
    if ( b[i][j] != 0 )
        return false;
    if ( a[i][j] == 2 )
        return false;
    return true;
}
void Debug()
{
    for ( int i = 0; i <= 2*n; ++i )
    {
        for ( int j = 0; j <= 2*m; ++j )
            os << a[i][j] << ' ';
        os << '\n';
    }
}
void Print()
{
    os << cnt << '\n' << mx << '\n' << amax << ' ' << i_max/2 << ' ' << j_max/2 << ' ';
    if ( cnt > 1 )
    {
        if ( dir_max == 1 )
            os << "E";
        else
            os << "S";
    }
    else
        os << "X";

}
