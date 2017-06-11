#include <fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int x[100], n;
int s[100]; // s[i] - val maxima de la s[0] la s[i]

void Print(int w);
void Part(int k);
int Suma(int k);
bool Ok(int k, int i);

int main()
{
    is >> n;
    Part(1);
    is.close();
    os.close();
    return 0;
}
void Print(int w)
{
    for (int i = 1; i <= w; ++i )
        os << x[i] << ' ';
    os << '\n';
}
void Part(int k)
{
    if ( k == n+1) return;
    for ( int i = 1; i <= n; ++i )
    {
        if ( s[k-1] <= i )
        {
            x[k] = i;
            s[k] = max(s[k], i);
        }
        if ( Suma(k) == n )
            Print(k);
        Part(k+1);
    }
}
int Suma(int k)
{
    int a = 0;
    for ( int i = 1; i <= k; ++i )
        a += x[i];
    return a;
}
bool Ok(int k, int a )
{
    for ( int i = 1; i < k; ++i )
        if ( x[i] > a )
            return false;
    return true;
}
