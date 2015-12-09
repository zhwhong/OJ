#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
void add(char *s1, char *s2);  
char *multi(char *s1, char *s2);  
char *result(char *s, int n);  
  
int main(void) {  
    char ch[100];   
    char *res;  
    int  num, np;  
    char tem, *temp1, *temp2;  
    char *chp;  
  
    while ( scanf("%s%d", ch, &num) != EOF ) {  
        chp = ch + strspn(ch, "0");           // 去掉前导0  
        temp1 = &ch[strlen(ch)-1];  
        if ( (temp2 = strchr(ch, '.')) != NULL ) {  // 如果有小数点  
            while ( *temp1 == '0' )  // 去掉小数末尾的0  
                *temp1-- = 0;  
            np  = strlen(temp2) - 1;  
            np *= num;                  // 小数位的num倍是最终结果的小数位数  
            memmove(temp2, temp2+1, strlen(temp2));  // 去掉小数点  
        }  
        else  
            np = 0;             // 整数  
  
        res   = result(chp, num);  
//        printf("res: %s\n", res);  
        temp1 = res + strspn(res, "0");  
        temp2 = &res[strlen(res) - np];     // 定位小数点  
        if ( temp1 >= temp2 && np != 0 )   // 如果结果小于1  
            printf("%c%s\n", '.', temp2);  
        else if ( np == 0 )              // 如果是整数  
            printf("%s\n", temp1 == temp2 ? 0 : temp1);  
        else {  
            tem   = *temp2;         // 将该放小数点位置的源字符保存  
            *temp2++ = 0;           // 这里将源结果字符串断开，块式输出效率高  
            printf("%s%c%c%s\n", temp1,   
                    '.', tem,  
                    *temp2 == 0 ? "" : temp2);  
        }  
  
        free(res);  
    }  
  
    return 0;  
}  
  
char *result(char *s, int n) {  
    char *res, *ch1, *ch2;  
  
    if ( n == 1 )   
        return multi(s, "1");  // 返回统一类型的可被free掉的数据空间  
    else if ( n == 2 )   
        return multi(s, s);  
    else if ( n > 2 ) {  
        ch1 = result(s, n >> 1);  // 二分递归计算  
        if ( n % 2 != 0 ) {  
            ch2 = result(s, n - (n >> 1));  
            res = multi(ch1, ch2);  
            free(ch2);   // result函数返回值得释放掉  
        }  
        else   // 如果n是偶数，可避免重复计算  
            res = multi(ch1, ch1);  
        free(ch1);       
        return res;  
    }  
}  
  
char *multi(char *s1, char *s2) {  
    int  i1, i2;   
    char *ch1, *ch2, *cp1, *cp2, *cp3;  
    char chp[18];  
    int  i, j, num, dis;  
    long long j1, j2, j3; // 加大每次计算量  
  
    i1 = strlen(s1);  
    i2 = strlen(s2);  
  
    ch1 = (char *)malloc(i1 + i2 + 2);  // 1 bit '\0', 1 carry bit(reserved for)  
    if ( strncmp(s2, "1", 1) == 0 && i2 == 1 ) {  
        memcpy(ch1, s1, i1+1);  
        return ch1;  
    }  
    ch2 = (char *)malloc(i1 + i2 + 1);  // 1 bit '\0'  
    memset(ch1, '0', i1 + i2 + 2);  
    ch1[i1+i2+1] = 0;  
  
    i = i2;  
    while ( i > 0 ) {  
        if ( i >= 8 )           // 和j，每次各可处理8位  
            dis = 8;  
        else  
            dis = i;  
        i -= dis;  
        memset(ch2, '0', i1 + i2 + 1);  // ch2每次循环都可能被修改  
        ch2[i1+i2] = 0;  
        cp1 = &s1[i1];  
        cp2 = &s2[i2];  
        cp3 = &ch2[i1 + i];  //  i1+i2-(i2-i)=i1+i, 每次循环往左移动dis位，表示和记录进位  
          
  
        memcpy(chp, cp2 - i2 + i, dis);  
        chp[dis] = 0;  
        j2     = atoi(chp);  
  
        j = i1;  
        while ( j > 0 ) {  
            if ( j >= 8 )     // 最多8位迭代处理与j2相乘  
                num = 8;  
            else   
                num = j;  
            cp1 -= num;  
            memcpy(chp, cp1, num);  
            chp[num] = 0;  
            j1       = atoi(chp);  
  
            memcpy(chp, cp3, dis);  // cp3记录进位，最多有dis位  
            chp[dis] = 0;  
            j3     = atoi(chp);  
  
            snprintf(chp, 18, "%lld", j1 * j2 + j3);  
            j1 = strlen(chp);    
            memcpy(cp3 -j1 + dis, chp, j1);     // 数据向右对齐  
            cp3 -= num;  // 定位到下次计算进位可能占据空间的开头地址  
            j -= num;  
        }  
  
        add(ch1, ch2);   // 将新的计算结果与前面的相加，最后可获得最后结果  
    }  
  
    free(ch2);  
    return ch1;  
}  
  
void add(char *s1, char *s2) {  
    char *cp1, *cp2, *cp3, *ch;  
    char chp[18];  
    int  num, n1, n2;  
    long long i, j, k;   
  
    s2 += strspn(s2, "0");  
    n1  = strlen(s1);       // make sure n1 > n2  
    if ( (n2  = strlen(s2)) == 0 )   
        return;  
  
    ch  = (char *)malloc(n1+1);  
    memset(ch, '0', n1);  
    ch[n1] = 0;  
  
    cp1 = &s1[n1];  
    cp2 = &s2[n2];  
    cp3 = &ch[n1 - 1];  
    while ( n2 > 0 ) {    // must validate enough memory  
        if ( n2 >= 16 )   
            num = 16;  
        else   
            num = n2;  
        cp1 -= num;  
        cp2 -= num;  
        memcpy(chp, cp1, num);  
        chp[num] = 0;  
        i        = atoll(chp);  
  
        memcpy(chp, cp2, num);  
        chp[num] = 0;  
        j        = atoll(chp);  
      
        memcpy(chp, cp3, 1);  
        chp[1] = 0;  
        k      = atoll(chp);  
  
        snprintf(chp, 18, "%lld", i + j + k);  
  
        i = strlen(chp);  
        cp3 -= i - 1;  
        memcpy(cp3, chp, i);  
        cp3 += i - 1 - num;  
  
        n2 -= num;  
    }  
  
    memcpy(s1, ch, n1);  
    free(ch);  
}
