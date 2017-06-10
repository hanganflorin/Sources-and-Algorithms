#include <fstream>
using namespace std;

ofstream os("a.out");

void Back(int k);
int n;
void Print();
int x[100];

int main()
{
    n = 4;
    Back(1);
    os.close();
    return 0;
}
void Back(int k)
{
    if ( k > n )
    {
        Print();
        return;
    }
    x[k] = 1;
    Back(k+1);
    x[k] = 2;
    Back(k+1);
}
void Print()
{
    for ( int i = 1; i <= n; ++i )
        os << x[i] << ' ';
    os << '\n';
}
