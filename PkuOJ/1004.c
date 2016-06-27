#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    float temp[12];
    float average = 0;
    for(i = 0; i < 12; i++){
        scanf("%f",&temp[i]);
        average += temp[i];
    }
    average /= 12;
    printf("$%.2f\n",average);
    return 0;
}
