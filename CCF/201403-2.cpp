#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,M;
    typedef vector<int> intList;
    vector<intList> area;
    typedef vector<intList>::iterator iterType;
    int clik[10][2]={0};
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        vector<int> line;
        line.push_back(i+1);
        int pos;
        for(int j=0; j<4; j++) {
            cin>>pos;
            line.push_back(pos);
        }
        area.push_back(line);
    }
    for(int i=0; i<M; i++) {
        for(int j=0; j<2; j++) {
            cin>>clik[i][j];
        }
    }
    for(int i=0; i<M; i++) {
        bool flag = false;
        for(int q=N-1; q>=0; q--) {
            if((clik[i][0]>=area[q][1])&&(clik[i][0]<=area[q][3])&&(clik[i][1]>=area[q][2])&&(clik[i][1]<=area[q][4])) {
                flag = true;
                cout<<area[q][0]<<endl;
                vector<int> temp=area[q];
                iterType p = area.begin()+q;
                area.erase(p);
                area.push_back(temp);
                break;
            }
        }
        if(!flag) {
            cout<<"IGNORED"<<endl;
        }
    }
    return 0;
}
