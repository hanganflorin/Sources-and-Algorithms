#include<iostream>
#include<fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int F(int n, int c1, int c2);

int main()
{
    int n, p1, p2;
    cin >> n >> p1 >> p2;
    cout << F(n, p1, p2);
    is.close();
    os.close();
    return 0;
}
int F(int n, int c1, int c2)
{
    if ( n < 10 )
    {
        if ( n == c1 ) return c2;
        return n;
    }
    if ( n%10 == c1 )
        return ((F(n/10, c1, c2) * 10) + c2);
    return ((F(n/10, c1, c2) * 10) + (n%10));
}
