#include <iostream>

using namespace std;

struct ttime{
    int begin;
    int end;
    bool secure;
    int cur_time;
    int next_time;
};

int main(){
    int n, m, t;
    int n_time = 0;
    cin >> n >> m >> t;
    struct ttime block[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            block[i][j].secure = true;
            block[i][j].begin = -1;
            block[i][j].end = -1;
            block[i][j].cur_time = -1;
            block[i][j].next_time = -1;
        }
    }
    for(int i = 0; i < t; i++){
        int r,c,a,b;
        cin >> r >> c >> a >> b;
        block[r-1][c-1].secure = false;
        block[r-1][c-1].begin = a;
        block[r-1][c-1].end = b;
    }

    block[0][0].cur_time = 0;

    while(1){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(block[i][j].cur_time == n_time){
                    if(i < n-1 && (block[i+1][j].secure == true || n_time+1 < block[i+1][j].begin || n_time+1 > block[i+1][j].end))
                        block[i+1][j].next_time = n_time+1;
                    if(j < m-1 && (block[i][j+1].secure == true || n_time+1 < block[i][j+1].begin || n_time+1 > block[i][j+1].end))
                        block[i][j+1].next_time = n_time+1;
                    if(i > 0 && (block[i-1][j].secure == true || n_time+1 < block[i-1][j].begin || n_time+1 > block[i-1][j].end))
                        block[i-1][j].next_time = n_time+1;
                    if(j > 0 && (block[i][j-1].secure == true || n_time+1 < block[i][j-1].begin || n_time+1 > block[i][j-1].end))
                        block[i][j-1].next_time = n_time+1;
                }
            }
        }
        n_time++;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                block[i][j].cur_time = block[i][j].next_time;
        if(block[n-1][m-1].cur_time != -1)
            break;
    }
    cout << n_time << endl;
    return 0;
}
