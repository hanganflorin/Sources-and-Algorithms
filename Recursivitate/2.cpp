#include<iostream>
#include<fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int F(int n);

int main()
{
    int n;
    cin >> n;
    cout << F(n);
    is.close();
    os.close();
    return 0;
}
int F(int n)
{
    if ( n < 10 )
    {
        if ( n%2 == 0 ) return n+1;
        return n-1;
    }
    if ( n%2 == 0 )
        return ((F(n/10) * 10) +((n%10)+1));
    return ((F(n/10) * 10) +((n%10)-1));
}
