#include<fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int n, Jp, a[100][100], c[100][100];
void Read();

int main()
{
    Read();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> Jp;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            is >> a[i][j];
}
