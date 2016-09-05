#include <stdio.h>  
  
struct posdata{  
    int time;  
    int newtime;  
    int dmin;  
    int dmax;  
};  
typedef struct posdata posdata;  
  
posdata data[100+1][100+1];//[0][0] not used;  
  
int m,n,t;  
int r,c,a,b;  
  
#define isDanger(a,b,t) (data[a][b].dmin<=t&&data[a][b].dmax>=t)  

int main(void)  
{  
    int i,j;  
    int ntime;  
    scanf("%d%d%d",&n,&m,&t);  
    //init  
    for(i=1;i<n+1;++i)  
        for(j=1;j<m+1;++j)  
            data[i][j]=(posdata){-1,-1,-1,-1};  
    //input  
    for(i=0;i<t;++i){  
        scanf("%d%d%d%d",&r,&c,&a,&b);  
        data[r][c]=(posdata){-1,-1,a,b};  
    }  
    data[1][1].time = 0;  
    //1000 is a max num  
    for(ntime=0;ntime<1000;++ntime){  
        for(i=1;i<n+1;++i)  
            for(j=1;j<m+1;++j)  
                if(data[i][j].time==ntime){  
                    if(i!=n&&!isDanger(i+1,j,ntime+1))  
                        data[i+1][j].newtime = ntime+1;  
                    if(j!=m&&!isDanger(i,j+1,ntime+1))  
                        data[i][j+1].newtime = ntime+1;  
                    if(i!=1&&!isDanger(i-1,j,ntime+1))  
                        data[i-1][j].newtime = ntime+1;  
                    if(j!=1&&!isDanger(i,j-1,ntime+1))  
                        data[i][j-1].newtime = ntime+1;  
                }  
        for(i=1;i<n+1;++i)  
            for(j=1;j<m+1;++j)  
                data[i][j].time = data[i][j].newtime;  
        if(data[n][m].time!=-1)  
            break;  
    }  
    printf("%d",ntime+1);  
  
    return 0;  
} 
