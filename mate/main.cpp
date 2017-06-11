#include <fstream>
using namespace std;

ofstream os("a.out");
int cnt;

int main()
{
    for ( int i = 1000; i <= 9999; ++i )
        if ( i % 3 == 0 )
        {
            os << i << '\n';
            cnt++;
        }
    os << "Sunt " << cnt << " numere";
    os.close();
    return 0;
}
