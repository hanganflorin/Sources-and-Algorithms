#include <fstream>
using namespace std;

ifstream is("inversmodular.in");
ofstream os("inversmodular.out");

void Euclid(int a, int b, int &x, int & y);
int a, n, x, y;

int main()
{
    is >> a >> n;
    Euclid(a, n, x, y);
    if ( x <= 0 )
        x += n;
    os << x;

    is.close();
    os.close();
    return 0;
}
void Euclid(int a, int b, int &x, int & y)
{
    if ( b == 0 )
    {
        x = 1;
        y = 0;
        return;
    }
    int x0, y0;
    Euclid(b, a%b, x0, y0 );
    x = y0;
    y = x0 - (a/b) * y0;
}
