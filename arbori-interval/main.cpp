#include <stdio.h>
#include <fstream>
#include <assert.h>
using namespace std;

#define in "arbint.in"
#define out "arbint.out"
#define dim 100001

int N, M;
int MaxArb[4*dim+66];
int start, finish, Val, Pos, maxim;

inline int Maxim(int a, int b) {
       if ( a > b ) return a;
       return b;
}

void Update(int,int,int);
void Query(int,int,int);

int main()
{
    int X, A, B;
    freopen(in,"r",stdin);
    freopen(out,"w",stdout);

    scanf("%d%d", &N, &M);
    for ( int i = 1; i <= N; i++ )
    {
        scanf("%d", &X);
        Pos = i, Val = X;
        Update(1,1,N);
    }

    for ( int i = 1; i <= M; i++ )
    {
        scanf("%d%d%d", &X, &A, &B);
        if ( X == 0 )
        {
             maxim = -1;
             start = A, finish = B;
             Query(1,1,N);

             printf("%d\n", maxim);
        }
        else
        {
            Pos = A, Val = B;
            Update(1,1,N);
        }
    }
}

void Update(int nod, int left, int right)
{
     if ( left == right )
     {
          MaxArb[nod] = Val;
          return;
     }

     int div = (left+right)/2;
     if ( Pos <= div ) Update(2*nod,left,div);
     else              Update(2*nod+1,div+1,right);

     MaxArb[nod] = Maxim( MaxArb[2*nod], MaxArb[2*nod+1] );
}

void Query(int nod, int left, int right)
{
     if ( start <= left && right <= finish )
     {
          if ( maxim < MaxArb[nod] ) maxim = MaxArb[nod];
          return;
     }

     int div = (left+right)/2;
     if ( start <= div ) Query(2*nod,left,div);
     if ( div < finish ) Query(2*nod+1,div+1,right);
}
