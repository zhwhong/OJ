#include <iostream>
#include <map>
using namespace std;
int main(){
        int n,count=0;
        map<int,int> pluMap;
        map<int,int> miuMap;
        typedef map<int,int>::value_type valType;
        cin>>n;
        for(int i=0; i<n; i++) {
                int value;
                cin>>value;
                if(value>0) {
                        pluMap.insert(valType(value,1));
                }else{
                        miuMap.insert(valType(value,1));
                }
        }
        map<int,int>::iterator iter=pluMap.begin();
        map<int,int>::iterator minIter=miuMap.begin();
        int size = pluMap.size()-miuMap.size();
        if(size>0) {
                while(minIter!=miuMap.end()) {
                        int s = minIter->first;
                        if(pluMap.count(~(s - 1))) {count++; }
                        ++minIter;
                }
        }else{
                while(iter!=pluMap.end()) {
                        int s = iter->first;
                        if(miuMap.count(~s +1)) {
                                count++;
                        }
                        ++iter;
                }
        }
        cout<<count<<endl;
        return 0;
}
