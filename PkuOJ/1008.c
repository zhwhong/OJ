#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HAAB_DAYS (18 * 20 + 5)
#define TZOLKIN_DAYS (13 * 20)

char *Haab_mon[19] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
                        "yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

char *Tzolkin_mon[20] = {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk",
                     "ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

int GetSub(char *str);
void convert(int day, char *month, int year, char *str);

int main()
{
    int n, i;
    int day, year;
    char month[10];
    scanf("%d",&n);
    char result[n][30];
    for(i = 0; i < n; i++){
        scanf("%d.%s%d", &day, month, &year);
        convert(day, month, year, result[i]);
    }
    printf("%d\n",n);
    for(i = 0; i < n; i++){
        printf("%s\n",result[i]);
    }
    return 0;
}

int GetSub(char *str)
{
    int i;
    for(i = 0; i < 19; i++){
        if(strcmp(str, Haab_mon[i]) == 0){
            return i;
        }
    }
    return -1;
}

void convert(int day, char *month, int year, char *str)
{
    int tag, y, a, b;
    int sum = 0;
    sum += year * HAAB_DAYS;
    tag = GetSub(month);
    sum += 20 * tag;
    sum += day;
    y = sum / TZOLKIN_DAYS;
    sum %= TZOLKIN_DAYS;
    a = sum % 13 + 1;
    b = sum % 20;
    sprintf(str, "%d %s %d", a, Tzolkin_mon[b], y);
}
