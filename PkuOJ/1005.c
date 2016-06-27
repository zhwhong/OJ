#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.1415926535898

int calculate(double point[]);

int main(void)
{
    int n, i;
    scanf("%d",&n);
    double point[n][2];
    for(i = 0; i < n; i++){
        scanf("%lf %lf",point[i],point[i]+1);
    }
    for(i = 0; i < n; i++){
        printf("Property %d: This property will begin eroding in year %d.\n", i+1, calculate(point[i]));
    }
    printf("END OF OUTPUT.\n");
    return 0;
}

int calculate(double point[])
{
    int k = 1;
    double rr = point[0]*point[0] + point[1]*point[1];
    double temp_rr = 100.0*k/M_PI;
    while(rr > temp_rr){
        k++;
        temp_rr = 100.0*k/M_PI;
    }
    return k;
}
