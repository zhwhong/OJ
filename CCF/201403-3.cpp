#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> split(string str,string pattern)
{
        string::size_type pos;
        vector<string> result;
        str+=pattern;
        int size=str.size();
        for(int i=0; i<size; i++)
        {
                pos=str.find(pattern,i);
                if(pos<size)
                {
                        string s=str.substr(i,pos-i);
                        result.push_back(s);
                        i=pos+pattern.size()-1;
                }
        }
        return result;
}
bool isalnumAndMiu(string str){
        bool result;
        for(string::size_type index =0; index!=str.size(); index++) {
                if((islower(str[index]))||(isdigit(str[index]))||(str[index]=='-')) {
                        result=true;
                }else{
                        result = false;
                        break;
                }
        }
        return result;
}
int main(){
        string str;
        string line;
        vector<string> valVec;
        getline(cin,str);
        int lineNum;
        cin>>lineNum;
        cin.ignore();
        for(int i=0; i<lineNum; i++) {
                getline(cin,line);
                valVec.push_back(line);
        }
        for(int i=0; i<lineNum; i++) {
                vector<string> lineSplit = split(valVec[i]," ");
                map<string,string> resultMap;
                typedef map<string,string>::iterator iterType;
                string::size_type pos =0;
                if(lineSplit.size()>1) {
                        for(int j=1; j<lineSplit.size(); ) {
                                if((lineSplit[j].size()==2)&&(lineSplit[j][0]=='-')&&(islower(lineSplit[j][1]))) {
                                        pos=str.find(lineSplit[j][1]);
                                        if(pos!=string::npos) {
                                                if(pos!=str.size()-1) {
                                                        if(str[pos+1]==':') {
                                                                if(isalnumAndMiu(lineSplit[j+1])) {
                                                                        resultMap[lineSplit[j]]=lineSplit[j+1];
                                                                        j+=2;
                                                                }else{
                                                                        break;
                                                                }
                                                        }else{
                                                                resultMap[lineSplit[j]]="";
                                                                j++;
                                                        }
                                                }else{
                                                        resultMap[lineSplit[j]]=""; j++;
                                                }
                                        }else{
                                                break;
                                        }
                                }else{
                                        break;
                                }
                        }
                }
                cout<<"Case "<<i+1<<": ";
                iterType iter=resultMap.begin();
                for(iter; iter!=resultMap.end(); iter++) {
                        cout<<iter->first<<" ";
                        if(iter->second!="") {
                                cout<<iter->second<<" ";
                        }
                }
                cout<<endl;
        }
        return 0;
}
