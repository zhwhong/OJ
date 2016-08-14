class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> flag(256,-1);
        int max = 0;
        int start = 0;
        for(int i = 0; i < s.length(); i++){
            if(flag[s[i]] == -1){
                if(max < i-start+1)
                    max = i-start+1;
            }
            else{
                if(max < i-start)
                    max = i-start;
                for(int j = start; j < flag[s[i]]; j++){
                    flag[s[j]] = -1;
                }
                start = flag[s[i]] + 1;
            }
            flag[s[i]] = i;
        }
        return max;
    }
};
