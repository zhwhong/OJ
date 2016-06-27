#include <iostream>
#include <string>

using namespace std;

int main(){
    string isbn;
    int count=0;
    getline(cin,isbn);
    count=isbn[0]*1+isbn[2]*2+isbn[3]*3+isbn[4]*4+isbn[6]*5+isbn[7]*6+isbn[8]*7+isbn[9]*8+isbn[10]*9-48*45;
    int result = count%11;
    if(result==10) {
        result =40;
    }
    if((isbn[12]-48)==result) {
        cout<<"Right" << endl;
    }else{
        isbn[12]=result+48;
        cout<<isbn;
    }
    return 0;
}
