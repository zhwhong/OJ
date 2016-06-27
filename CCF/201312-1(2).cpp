#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int,int> count;
    int n;
    int max = 0;
    int maxNum=0;
    int num;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>num;
        count[num]++;
        if(count[num]>max) {
            max = count[num];
            maxNum=num;
        }else if(count[num]==max) {
            if(num<maxNum) {
                maxNum=num;
            }
        }
    }
    cout<<maxNum;
    return 0;
}
