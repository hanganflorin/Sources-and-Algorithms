#include <iostream>
#include <fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int x[100], n;
bool b[100];

void Perm(int k);
void Print();

int main()
{
    is >> n;
    Perm(1);
    is. close();
    os.close();
    return 0;
}
void Print()
{
    for ( int i = 1; i <= n; ++i )
        os << x[i];
    os << '\n';
}
void Perm(int k)
{
    if ( k == n+1 )
    {
        Print();
        return;
    }
    for ( int i = 0; i <= 1; ++i )
    {
        x[k] = i;
        Perm(k+1);
    }
}
