#include <fstream>
#include <iomanip>
using namespace std;

ofstream os("a.out");

int n, x[5];
void A(int k);
void Afis();

int main()
{
    A(1);
    os.close();
    return 0;
}
void A(int k)
{
    if ( k > 3 )
    {
        Afis();
        return;
    }
    for (int i = -1; i <= 1; ++i )
    {
        x[k] = i;
        A(k+1);
    }
}
void Afis()
{
    for ( int i = 1; i <=3; ++i )
        os << setw(3) << x[i];
    os << '\n';
}
