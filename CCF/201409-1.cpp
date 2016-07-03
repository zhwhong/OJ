#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> valueVec;
    int value;
    int count=0; cin>>n;
    for(int i=0; i<n; i++) {
        cin>>value;
        valueVec.push_back(value);
    }
    sort(valueVec.begin(),valueVec.end());
    for(int i=0; i<valueVec.size()-1; i++) {
        if((valueVec[i+1]-valueVec[i])==1) {
            count++;
        }
    }
    cout<<count;
    return 0;
}
