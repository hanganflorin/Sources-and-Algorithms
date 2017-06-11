#include<iostream>
using namespace std;

int F(int i);
int F1(int n);
int n = 10;
int a[] = {1, 2, 3, 4, 5, 6, 7, 100, 200, 123456789 };

int main()
{
    cout << F(0);
    return 0;
}
int F(int i)
{
    if ( i== n ) return 0;
    return F(i+1) + F1(a[i]);

}
int F1(int n)
{
    if ( n == 0 ) return 0;
    return (F1(n/10)+(n%10));
}
