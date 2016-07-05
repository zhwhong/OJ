#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

void int2str(const int &int_temp,string &string_temp)
{
	stringstream stream;stream<<int_temp;
	string_temp=stream.str();
}

int main(){
	int n;
	map<string,int> countMap;
	typedef map<string,int>::value_type valType;
	stringstream stream;
	cin>>n;
	typedef vector<int> typeVec;
	vector<typeVec> values(n,vector<int>(4,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			cin>>values[i][j];
		}
		for(int a=values[i][0]+1;a<=values[i][2];a++){
			for(int b =values[i][1]+1;b<=values[i][3];b++){
				string x;
				string y;
				int2str(a,x);
				int2str(b,y);
				string xy =x+"-"+y;
				countMap.insert(valType(xy,1));
			}
		}
	}
	cout<<countMap.size();
	return 0;
}
