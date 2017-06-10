#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ifstream is ( "a.in");
ofstream os ( "a.out");

int n = 8;
int c[100];
bool b[100];
short a[100000][10];
int p = 0;

void Backtrack(int i, bool f );
void Afis(); // afiseaza sirul
int Primu(); // returneaza primul numar care nu e in sir
short Add(short i); // returneaza cu cat pot creste valoarea de pe pozitia i (0 daca nu pot)
void Print();

int main()
{
    Backtrack(1, true);
    Afis();
    is.close();
    os.close();
    return 0;
}
void Backtrack(int i, bool f)
{
    if ( i == 0 )
        return;
    if ( i == n+1 )
    {
        Print();
        p++;
        Backtrack(i-1, false );
        return;
    }
    if ( f )
    {
        c[i] = Primu();
        b[c[i]] = true;
        Backtrack(i+1, true );
    }
    else
    {
        short x = Add(i);
        if ( x == 0 )
        {
            b[c[i]] = false;
            Backtrack(i-1, false );
        }
        else
        {
            b[c[i]] = false;
            c[i] += x;
            b[c[i]] = true;
            Backtrack(i+1, true );
        }
    }
}
void Afis()
{
    for ( int i = 0; i < p; ++i )
    {
        for ( int j = 1; j <= n; ++j )
            os << a[i][j] << ' ';
        os << '\n';
    }
}
int Primu()
{
    int i = 1, x = 0;
    for (i; b[i] == true; ++i )
        x = i;
    return x+1;
}
short Add( short i )
{
    for ( int j = c[i] + 1; j <= n; ++j )
    {
        if ( !b[j] )
            return j - c[i];
    }
    return 0;
}
void Print()
{
    for ( int i = 1; i <= n; ++i )
        a[p][i] = c[i];
}
