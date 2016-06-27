#include <stdio.h>
#include <stdlib.h>

int calculate(int p, int e, int i, int d);

int main(void)
{
    int p, e, i, d;
    int k = 1;
    scanf("%d %d %d %d",&p, &e, &i, &d);
    while(!(p == -1 && e == -1 && i == -1 && d == -1)){
        printf("Case %d: the next triple peak occurs in %d days.\n", k, calculate(p,e,i,d));
        k++;
        scanf("%d %d %d %d",&p, &e, &i, &d);
    }
    return 0;
}

int calculate(int p, int e, int i, int d)
{
    int temp = 1;
    p %= 23;
    e %= 28;
    i %= 33;
    while((temp%23 != p) || (temp%28 != e) || (temp%33 != i)){
        temp++;
    }
    temp -= d;
    if(temp <= 0)
        temp += 21252;
    return temp;
}
