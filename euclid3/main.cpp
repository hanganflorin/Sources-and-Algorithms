#include <fstream>
using namespace std;

ifstream is("euclid3.in");
ofstream os("euclid3.out");

void Euclid(int a, int b, int & d, int &x, int &y );
int a, b, c, d, x, y;
int t;

int main()
{
    is >> t;
    while ( t-- )
    {
        is >> a >> b >> c;
        Euclid(a, b, d, x, y );
        if ( c % d )
            os << "0 0\n";
        else
            os << x * (c/d) << ' ' << y * (c/d)<< '\n';
    }

    is.close();
    return 0;
}
void Euclid(int a, int b, int &d, int &x, int &y )
{
    if ( b == 0 )
    {
        d = a;
        x = 1;
        y = 0;
        return;
    }
    int x0, y0;
    Euclid(b, a%b, d, x0, y0 );
    x = y0;
    y = x0 - (a/b) * y0;
}
