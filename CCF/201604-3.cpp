#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    char root[1005],each[2005];
    string root1,each1;
    int n;
    scanf("%d",&n);
    getchar();
    //gets(root);
    getline(cin,root1);
    strcpy(root,root1.c_str());
    while(n--)
    {
        char ans[2005] = {0};
        //gets(each);
        getline(cin,each1);
        strcpy(each,each1.c_str());
        char *p1,*p2;
        if(each[0] != '/')
        {
            strcpy(ans,root);
            p1 = ans;
            while(*p1 != 0)     p1++;
            *p1 = '/';
            p2 = each;
        }
        else
        {
            p1 = ans;
            *p1 = '/';
            p2 = each;
        }
        while(*p2 != 0)
        {

            if(*p1 == '/' && *p2 == '.' && *(p2+1) =='.' && (*(p2+2) == '/' || *(p2+2) == 0))
            {
                if(p1 == ans)    {}
                else    while(*--p1 != '/');
                p2 += 2;
            }
            else if(*p1 == '/' && *p2 == '/')    p2++;
            else if(*p1 == '/' && *p2 == '.'  && (*(p2+1) == '/' || *(p2+1) == 0))    p2++;
            else    *++p1 = *p2++;
        }
        if(*p1 == '/' && p1 != ans)  *p1 = 0;
        else *(p1+1) = 0;
        puts(ans);
    }
    return 0;
}
