#include <stdio.h>
#include <stdlib.h>

int inverse_num(char str[], int length);
int compare(const void *a, const void *b);

int main(void)
{
    int i, j, k;
    int length, rows;
    scanf("%d %d", &length, &rows);
    getchar();
    int num[rows];
    int num_sort[rows];
    char temp[rows][length+1];
    for(i = 0; i < rows; i++){
        for(j = 0; j < length; j++){
            scanf("%c",&temp[i][j]);
        }
        getchar();
        temp[i][j] = '\0';
        num[i] = inverse_num(temp[i], length);
        num_sort[i] = num[i];
    }
    qsort((void *)num_sort, rows, sizeof(int), compare);
    for(i = 0, k = -1; i < rows; i++){
        if(num_sort[i] == k)
            continue;
        for(j = 0; j < rows; j++){
            if(num[j] == num_sort[i]){
                printf("%s\n",temp[j]);
            }
        }
        k = num_sort[i];
    }
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int inverse_num(char str[], int length)
{
    int i;
    int left_C = 0, left_G = 0, left_T = 0;
    int count = 0;
    for(i = length-1; i >= 0; i--)
    {
        switch(str[i])
        {
        case 'A':
            left_C++;
            left_G++;
            left_T++;
            break;
        case 'C':
            left_G++;
            left_T++;
            count+=left_C;
            break;
        case 'G':
            left_T++;
            count+=left_G;
            break;
        case 'T':
            count+=left_T;
            break;
        }
    }
    return count;
}
