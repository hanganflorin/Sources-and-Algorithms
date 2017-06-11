#include<fstream>
using namespace std;

ifstream is("subgraf.in");
ofstream os("subgraf.out");

const int MaxN = 101;
bool a[MaxN][MaxN];
int n;
int g[MaxN];
int minim = 999999;
int cnt;

void Read();
void Write();


int main()
{
    Read();
    Write();
    os << cnt;
    is.close();
    os.close();
    return 0;
}
void Read()
{
    int x,y;
    is >> n;
    while(is >> x >> y)
    {
        if( a[x][y] == false)
        {
            g[x]++;
            g[y]++;
        }
        a[x][y] = a[y][x] = true;
    }
}
void Write()
{
    for(int i = 1; i <= n;++i)
        if(g[i] < minim)
            minim = g[i];
    for(int i = 1; i <= n;++i)
        if ( g[i] != minim )
            for ( int j = 1; j < i; ++j )
                if ( g[j] != minim && a[i][j] == true )
                    cnt++;
}
