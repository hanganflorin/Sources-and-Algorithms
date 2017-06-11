#include <fstream>
using namespace std;

ifstream is("plopi1.in");
ofstream os("plopi1.out");

int n, L[1001], a[1001], mx, t[1001], poz;
bool b[1001];

int main()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
    {
        is >> a[i];
        L[i] = 1;
        for ( int j = 1; j < i; ++j )
            if ( a[j] > a[i] && L[j]+1 > L[i] )
            {
                L[i] = L[j]+1;
                t[i] = j; // aici e sirl de tati // captain obvious
            }
        if ( L[i] > mx )
            mx = L[i], poz = i;
    }
    os << n - mx << '\n';
    // marchez elementele care contin
    // cel mai lung subsir comun
    //
    //e ca functia recursiva de afisare da e iterativa
    for (; t[poz]; poz = t[poz] )
        b[poz] = true;
    b[poz] = true; // marchez si pozitia celui mai mare element
                   // t[poz] = 0 si iese din for
    // sfarsit functie

    //afisez restu
    for ( int i = 1; i <= n; ++i )
        if ( !b[i] )
            os << i << ' ';
    is.close();
    os.close();
    return 0;
}
