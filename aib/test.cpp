#include<fstream>
using namespace std;

ifstream is1("aib.out");
ifstream is2("grader_test6.ok");
ofstream os("aib.in");

int a, b, i = 1;

int main()
{
    while( is1 >> a && is2 >> b )
    {
        if ( a != b )
            os << i << ": " << a << " " << b << '\n';
        i++;
    }
    is1.close();
    is2.close();
    os.close();
    return 0;
}
