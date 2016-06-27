#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    int max, min, t;
    vector<int> num;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        num.push_back(x);
    }
    max = n;
    for(int i = 0; i < n; i++){
        t = 0;
        min = num.at(i);
        for(int j = i; j < n; j++){
            if(num.at(j) < min)
                min = num.at(j);
            t = min * (j-i+1);
            if(t > max)
                max = t;
        }
    }
    cout << max << endl;
    return 0;
}
