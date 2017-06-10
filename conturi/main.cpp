#include <fstream>
using namespace std;

ifstream is("conturi.in");
ofstream os("conturi.out");

int n, x, mx, nr;
char s[7];

int ConstrNr(char s[7] );

int main()
{
    is >> n >> x;
    for ( int i = 0; i < n; ++i )
    {
        is >> s;
        if ( s[0] - 48 == x && s[1]-48 == 1 )
        {
            nr = ConstrNr(s);
            if ( nr > mx )
                mx = nr;
        }
    }
    os << mx;
    os.close();
    is.close();
    return 0;
}
int ConstrNr(char s[7] )
{
    int nr;
    nr = s[2] - 48;
    nr *= 10;
    nr += s[3] - 48;
    nr *= 10;
    nr += s[4] - 48;
    nr *= 10;
    nr += s[5] - 48;
    return nr;
}
