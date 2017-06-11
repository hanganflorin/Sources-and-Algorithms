#include <fstream>
#include <cstring>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int n, cnt = 1;

void Morse(string x );

int main()
{
    is >> n;
    Morse("");
    is.close();
    os.close();
    return 0;
}
void Morse(string x )
{
    if ( x.size() == n  )
    {
        os << x << '\n';
        return;
    }
    Morse(x+'-');
    Morse(x+'.');
}
