#include <cstdio>
using namespace std;

FILE* is = fopen("perm2.in", "r");
FILE* os = fopen("perm2.out", "w");

int n, a[100002], aux;
int Nr(int p, int i);
int Cmmmc(int a, int b);

int main()
{
    /*
    fprintf(os, "%d\n", 100000 );
    for ( int i = 2; i <= 100000; ++i )
        fprintf(os, "%d ", i );
    fprintf(os, "%d", 1 );
*/
    fscanf(is, "%d", &n);
    for ( int i =1; i <= n; ++i )
        fscanf(is, "%d", &a[i]);
    aux = Nr(1, 1);
    for ( int i = 2; i <= n; ++i )
        aux = Cmmmc(aux, Nr(i, i));
    fprintf(os, "%d", aux );
    fclose(is);
    fclose(os);
    return 0;
}
int Nr(int p, int i)
{
    if ( a[p] == i ) return 1;
    return ( Nr(a[p], i) + 1);
}
int Cmmmc(int a, int b)
{
    int a1 = a;
    int b1 = b;
    int rest;
    do
    {
        rest = a % b;
        a = b;
        b = rest;
    } while ( rest );
    return ((a1 * b1) / a);
}
