#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int originalValue;
    int x,y;
    int length;
}node[1000];

int numInput[1000][2];
int countPot[1000] = {0};
int cols, rows;
int xP[8]={-1,-1,-1,0,0,1,1,1};
int yP[8]={-1,0,1,-1,1,-1,0,1};

int compare(const void *n1,const void *n2);
int isImage(int x,int y);
int isPot(int l);
int findValue(int l);
void newValue();
void dealWith();
int maxAbs(int number, int length);

int main()
{
    int i, j, count;
    while(1){
        scanf("%d", &cols);
        if(cols == 0)
            break;
        printf("%d\n",cols);
        for(j=0, i=0, count=0; ; ++j){
            scanf("%d%d", &numInput[j][0], &numInput[j][1]);
            if(i == 0)
                countPot[i] = 0;
            else
                countPot[i] = countPot[i-1] + 1;
            i++;
            countPot[i] = countPot[i-1] + numInput[j][1] - 1;
            i++;
            count += numInput[j][1];
            if(numInput[j][0] == 0 && numInput[j][1] == 0){
                rows = count / cols;
                break;
            }
        }
        dealWith();
    }
    printf("0\n");
    return 0;
}

void dealWith(){
    int i,j,k,n;
    for(i = 0, j = 0, k = 0; ; ++i){
        if(numInput[i][0] == 0 && numInput[i][1] == 0)
            break;
        n = 2;
        while(n--){
            node[j].originalValue = numInput[i][0];
            node[j].x = countPot[k]/cols;
            node[j].y = countPot[k]%cols;
            node[j].length = countPot[k++];
            int value, temp = j;
            if(isImage(node[temp].x-1, node[temp].y) && (value = isPot((node[temp].x-1)*cols + node[temp].y)) != 0){
                node[++j].x = node[temp].x - 1;
                node[j].y = node[temp].y;
                node[j].length = node[j].x * cols + node[j].y;
                node[j].originalValue = value;
            }
            if(isImage(node[temp].x+1, node[temp].y) && (value = isPot((node[temp].x+1)*cols + node[temp].y)) != 0){
                node[++j].x = node[temp].x + 1;
                node[j].y = node[temp].y;
                node[j].length = node[j].x * cols + node[j].y;
                node[j].originalValue = value;
            }
            ++j;
        }
    }
    qsort(node, j, sizeof(struct Node), compare);
    node[j].length = -1;
    newValue();
}

void newValue(){
    int result[1000][2];
    int resultcount=0;
    result[resultcount][0] = maxAbs(node[0].originalValue, node[0].length);
    result[resultcount][1] = 1;
    int temp0 = result[resultcount][0];
    int temp1 = 0;
    int i, num;
    for(i = 1, num = 0; node[i].length != -1; ++i){
        num = node[i].length - node[i-1].length - 1;
        if(num == -1)
            continue;
        if(num > 0){
            temp1 = maxAbs(findValue(node[i-1].length+1), node[i-1].length + 1);
            if(temp1 != temp0)
                result[++resultcount][0] = temp1;
            temp0 = temp1;
            result[resultcount][1] += num;
        }
        temp1 = maxAbs(node[i].originalValue,node[i].length);
        if(temp1 != temp0)
            result[++resultcount][0] = temp1;
        temp0 = temp1;
        result[resultcount][1] += 1;
    }
    for(i = 0; i <= resultcount; ++i){
        printf("%d %d\n", result[i][0], result[i][1]);
    }
    printf("0 0\n");
}

int compare(const void *n1,const void *n2)
{
    if(((struct Node*)n1)->length < ((struct Node*)n2)->length)
        return -1;
    else
        return 1;
}

int isImage(int x, int y)
{
    return (x >= 0 && x < rows) && (y >= 0 && y < cols);
}

int isPot(int l)
{
    int i;
    for(i = 0; countPot[i] <= l; ++i){
        if(l == countPot[i])
            return 0;
    }
    i = (i-1) / 2;
    return numInput[i][0];
}

int findValue(int l){
    int i;
    for(i = 0; countPot[i] <= l; ++i)
        ;
    i = (i-1) / 2;
    return numInput[i][0];
}

int maxAbs(int number, int length){
    int i, num, max = 0;
    for(i = 0; i < 8; i++){
        if(isImage(length/cols + xP[i], length%cols + yP[i])){
            num = findValue(length + xP[i]*cols + yP[i]);
            if((num = abs(num-number)) > max)
                max = num;
        }
    }
    return max;
}
