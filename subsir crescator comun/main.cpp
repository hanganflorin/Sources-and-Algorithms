#include <fstream>
#include <cstring>
using namespace std;

ifstream is("codul.in");
ofstream os("codul.out");

void Read();
void Schimba();
void Write(int x);
void Dinamica();

char a[201], b[201], rez1[1025], rez2[1025];
char res[1025];
int n, m, k, d[201][201];

int main()
{
    Read();
    Dinamica();
    for ( int i = k - 1; i >= 0; --i )
        rez1[k-1-i] = res[i];
    memset(d, 0, sizeof(d) );
    memset(res, 0, sizeof(res) );
    Schimba();
    Dinamica();
    for ( int i = k - 1; i >= 0; --i )
        rez2[k-1-i] = res[i];

    //afiseaza
    for ( int i = 0; i < k; ++i )
    {
        if ( rez1[i] > rez2[i] )
        {
            Write(1);
            break;
        }
        else if ( rez1[i] <  rez2[i] )
        {
            Write(2);
            break;
        }
    }

    is.close();
    os.close();
    return 0;
}
void Read()
{
    n = 1;
    a[n] = is.get();
    while ( a[n] != '\n')
    {
        n++;
        a[n] = is.get();
    }
    n--;
    m = 1;
    b[m] = is.get();
    while ( b[m] != '\n')
    {
        m++;
        b[m] = is.get();
    }
    m--;
}
void Dinamica()
{
    int i = n, j = m;
    k = 0;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            if ( a[i] == b[j] )
                d[i][j] = d[i-1][j-1] +1;
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    while ( k != d[n][m] )
    {
        if ( a[i] == b[j] )
        {
            res[k++] = a[i];
            i--;
            j--;
        }
        else
        {
            if ( d[i][j-1] > d[i-1][j] )
                j--;
            else
                i--;
        }
    }
}
void Write(int x)
{
    for ( int i = 0; i < k; ++i )
    {
        if ( x == 1 )
            os << rez1[i];
        else
            os << rez2[i];
    }
}
void Schimba()
{
    char x[200];
    for ( int i = 1; i <= n; ++i )
        x[i] = a[i];
    memset(a, 0, sizeof(a) );
    for ( int i = 1; i <= m; ++i )
        a[i] = b[i];
    memset(b, 0, sizeof(b) );
    for ( int i = 1; i <= n; ++i )
        b[i] = x[i];
    int aux = n;
    n = m;
    m = aux;
}
