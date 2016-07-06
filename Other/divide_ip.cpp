#include <iostream>
#include <cstdlib>

using namespace std;

int ip_count(string str);

int main()
{
    string line;
    int n = 0;
    getline(cin, line);
    n = ip_count(line);
    cout << "一共划分ip数目：" << n << endl;
    return 0;
}

int ip_count(string str){
    int count = 0;
    int n = str.length();
    if(n < 4 || n > 12){
        return 0;
    }
    cout << n << endl;
    for(int i = 0; i < n-3; i++){
        if(i > 2)
            break;
        string s1 = str.substr(0, i+1);
        if(atoi(s1.c_str()) > 255)
            break;
        if(s1.length() > 1 && s1[0] == '0')
            break;
        for(int j = i+1; j < n-2; j++){
            if(j-i > 3)
                break;
            string s2 = str.substr(i+1, j-i);
            if(atoi(s2.c_str()) > 255)
                break;
            if(s2.length() > 1 && s2[0] == '0')
                break;
            for(int k = j+1; k < n-1; k++){
                if(k-j > 3)
                    break;
                string s3 = str.substr(j+1, k-j);
                if(atoi(s3.c_str()) > 255)
                    break;
                if(s3.length() > 1 && s3[0] == '0')
                    break;
                if(n-k-1 > 3)
                    continue;
                string s4 = str.substr(k+1);
                if(atoi(s4.c_str()) > 255)
                    continue;
                if(s4.length() > 1 && s4[0] == '0')
                    continue;
                cout << s1 << '.' << s2 << '.' << s3 << '.' << s4 << endl;
                count++;
            }
        }
    }
    return count;
}
