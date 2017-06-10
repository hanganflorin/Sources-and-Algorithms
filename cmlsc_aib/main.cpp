#include <fstream>
using namespace std;

ifstream fin  ("scmax.in");
ofstream fout ("scmax.out");


const int Dim = 100001;
const int Vmax = 1000;   // Aici e o problema

int a[Dim], aib[Dim], n;
int L[Dim], Lmax, t[Dim];

void Update(int v, int i) ;
int Query(int v);
void Read();
void Write(int i);

int main ()
{
    Read();

    //int imax = 1;
    int j;
    for (int i = 1 ; i <= n ; ++ i)
    {
        j = Query(a[i] - 1);
        //t[i] = j;
        L[i] = L[j] + 1;

        Update(a[i], i);

        //if(Lmax < L[i])
          //  imax = i, Lmax = L[i];
    }

    //fout << Lmax << '\n';
    //Write(imax);
    for ( int i = 1; i <= n; ++i )
        fout << L[i] << ' ';

    fin.close();
    fout.close();
    return 0;
}

void Update(int v, int i)
{
    for (; v <= Vmax; v += v & -v)
       if ( L[i] > L[aib[v]] )
			aib[v] = i;
}

int Query(int v)
{
    int j = 0;
    for ( ; v > 0 ; v -= v & -v)
        if ( L[aib[v]] > L[j] )
			j = aib[v];

    return j;
}

void Write(int i)
{
	if ( !i ) return;
	Write(t[i]);
	fout << a[i] << ' ';
}

void Read ()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
}
