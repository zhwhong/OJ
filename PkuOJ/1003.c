#include <stdio.h>
#include <stdlib.h>

int calculate(float num);

int main(void)
{
    float temp;
    scanf("%f", &temp);
    //getchar();
    while(temp != 0.00){
        printf("%d card(s)\n",calculate(temp));
        scanf("%f", &temp);
        //getchar();
    }
    return 0;
}

int calculate(float num)
{
    int k = 1;
    float sum = 0;
    while(sum < num){
        k++;
        sum += 1.0/k;
    }
    k--;
    return k;
}
