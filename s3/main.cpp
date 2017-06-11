#include <fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int X[1000], N;

void Build_X(int n);
int First_Digit(int x);
int Last_Digit(int x);
int Max_Digit(int x);
void Build_Matrix();

int main()
{
    Build_X(20);
    for ( int i = 1; i <= N; ++i )
        os << X[i] << ' ';
    is.close();
    os.close();
    return 0;
}
void Build_X(int n)
{
    N = 0;
    for ( int i = 1; i <= n; ++i )
    {
        X[++N] = i;
        for ( int j = 2; j < i; ++j )
            if ( i % j == 0 )
                X[++N] = j;
    }
}
int First_Digit(int x)
{
    if ( x < 10 ) return x;
    return First_Digit(x/10);
}
int Last_Digit(int x)
{
    return x % 10;
}
int Max_Digit(int x)
{
    if ( x < 10 ) return x;
    if ( Max_Digit(x/10) > (x%10) )
        return Max_Digit(x/10);
    return x % 10;
}
void Build_Matrix()
{

}
