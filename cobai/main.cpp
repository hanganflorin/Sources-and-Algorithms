#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

ifstream is("cobai.in");
ofstream os("cobai.out");

void Read();
void Pune(int i, int j, short d );
bool Ok(int i, int j);
short Directie(char c );
void Debug(int x );

char c[51][51];
char dr[1001];
int n, m, camere;
const short d1[] = {-1, 0, 1, 0 };
const short d2[] = {0, 1, 0, -1 };

vector<pair<int, int > > a;
vector<pair<int, int > > b;

int main()
{
    Read();
    int kk = strlen(dr);
    for ( int k = 0; k < kk; ++k )
    {
        short d = Directie(dr[k]);
        for ( int i = 0; i < a.size(); ++i )
            Pune(a[i].first, a[i].second, d );
        a = b;
        b.clear();
    }
    int x = a.size() * 100;
    os  << (double)x/camere;
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
            if ( c[i][j] == '.' )
                camere++;
            if ( c[i][j] == '*' )
                a.push_back(make_pair(i, j) );
        }
    is >> dr;
}
bool Ok(int i, int j)
{
    if ( i < 1 || j < 1 || i > n || j > m )
        return false;
    if ( c[i][j] != '.' )
        return false;
    return true;
}
short Directie(char c )
{
    switch ( c )
    {
        case 'N' : return 0;
        case 'E' : return 1;
        case 'S' : return 2;
        case 'V' : return 3;
    }
}
void Pune(int i, int j, short d )
{
    i += d1[d];
    j += d2[d];
    while ( Ok(i, j) )
    {
        b.push_back(make_pair(i, j) );
        i += d1[d];
        j += d2[d];
    }
}
