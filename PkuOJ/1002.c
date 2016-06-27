#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void Convert(char* in_line,char* out_line){
    int x=0;
    int n;
    char table[26] = {
        '2','2','2',        //ABC
        '3','3','3',        //DEF
        '4','4','4',        //GHI
        '5','5','5',        //JKL
        '6','6','6',        //MNO
        '7','7','7','7',    //PQRS
        '8','8','8',        //TUV
        '9','9','9','9'     //WXYZ
    };
                // 对输入的电话串处理，跳过'-'，对字母按table字典查找
    for(n=0;n<80;n++){
        if(x == 7)
            return;
        if(in_line[n] == '-')
            continue;
        if(isdigit(in_line[n])){
            out_line[x] = in_line[n];
            x++;
            continue;
        }
        if(isalpha(in_line[n])){
            out_line[x] = table[in_line[n] - 'A'];
            x++;
        }
    }
}

void Display(int value){
    char telephone[8];
    int n;
            //按000-0000格式输出电话串
    for(n=6;n>=0;n--){
        telephone[n] = value % 10 + '0';
        value = value / 10;
    }
    for(n=0;n<3;n++)
        printf("%c", telephone[n]);
    printf("-");
    for(n=3;n<7;n++)
        printf("%c", telephone[n]);

    return;
}

int Compare(const void* elem1,const void* elem2){
    int x = *(int*)elem1;
    int y = *(int*)elem2;

    return x - y;
}
int main(void){
    int lines,counts = 0;
    char strLine[80];
    char strTele[8];
    int *numbers;
    int current,count = 0;
    int n;

    scanf("%d", &lines);        //读入行数，开辟相应的空间
    numbers = (int *)malloc(sizeof(int) * lines);
    for(n = 0;n<lines;n++){        //读一行电话串，调用Convert函数转换为我们需要的形式；接着转换为整型值，存在numbers数组中
        scanf("%s", strLine);
        Convert(strLine,strTele);
        strTele[7] = '\0';
        numbers[n] = atoi(strTele);
    }                //调用qsort按数字大小对numbers数组排序，即对电话串按字典排序
    qsort(numbers,lines,sizeof(int),Compare);
    for(n=0;n<lines;n++){    //由于numbers数组按大小排过序，搜寻出现次数大于1的电话串变得异常简单
        if(n == 0){
            current = numbers[n];
            count = 1;
        }
        else if(current == numbers[n]){
            count++;
        }
        else{
            if(count > 1){
                Display(current);
                counts++;
                printf(" %d\n", count);
            }
            current = numbers[n];
            count = 1;
        }
        if((n == lines-1) && (count > 1)){    //不要忘记最后一个出现次数大于1的情况
            Display(current);
            counts++;
            printf(" %d\n", count);
        }
    }
    if(counts == 0)        // 不要忘记'No duplicates'
        printf("No duplicates.\n");
    free(numbers);

    return 0;
}
