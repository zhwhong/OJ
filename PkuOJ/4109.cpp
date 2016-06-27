#include <iostream>

using namespace std;

int main()
{
    int c;
    int n, m, k;
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> n >> m >> k;
        bool matrix[n][n];
        int a, b;
        for(int s = 0; s < n; s++){
            for(int t = 0; t < n; t++){
                if(s == t)
                    matrix[s][t] = true;
                else
                    matrix[s][t] = false;
            }
        }
        for(int j = 0; j < m; j++){
            cin >> a >> b;
            matrix[a-1][b-1] = true;
            matrix[b-1][a-1] = true;
        }
        cout << "Case " << i+1 << ":" << endl;
        for(int j = 0; j < k; j++){
            cin >> a >> b;
            int count = 0;
            for(int s = 0; s < n; s++){
                if(s == a-1 || s == b-1)
                    continue;
                if(matrix[s][a-1] && matrix[s][b-1])
                    count++;
            }
            cout << count << endl;
        }
    }
    return 0;
}
