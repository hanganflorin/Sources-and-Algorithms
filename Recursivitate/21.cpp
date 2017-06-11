#include<iostream>
using namespace std;

float F(int i);

int main()
{
    cout << (float)F(2);
    return 0;
}
float F(int n)
{
    if ( n == 1 ) return 1;
    return (float)((float)F(n-1) + (float)(1/n));

}
