#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    vector<int> num;
    int last, t = 0, max = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(), num.end());
    last = num.front();
    for(int i = 0; i < n; i++){
        if(num.at(i) == last)
            t++;
        else
            t = 1;
        if(t > max){
            max = t;
            x = num.at(i);
        }
        last = num.at(i);
    }
    cout << x << endl;
    return 0;
}
