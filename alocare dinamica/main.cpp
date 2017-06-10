#include <fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

class Punct{
    int x;
    int y;
public:
    Punct(int a = 0, int b = 0 ) : x(a), y(b)
    {

    }

    void Print() const
    {
        os << x << ' ' << y << '\n';
    }

};

int main()
{
    int n, a, b;
    is >> n;
    Punct* *p = new Punct*[n];
    for ( int i = 0; i < n; ++i )
    {
        is >> a >> b;
        p[i] = new Punct(a, b);
    }
    for ( int i = 0; i < n; ++i )
        p[i]->Print();
    is.close();
    os.close();
    return 0;
}
