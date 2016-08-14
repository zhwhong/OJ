int lengthOfLongestSubstring(char* s) {
    int flag[256];
    int max = 0;
    int start = 0;
    int i, j;
    for(i = 0; i < 256; i++){
        flag[i] = -1;
    }
    for(i = 0; i < strlen(s); i++){
        if(flag[s[i]] == -1){
            if(max < i-start+1)
                max = i-start+1;
        }
        else{
            if(max < i-start)
                max = i-start;
            for(j = start; j < flag[s[i]]; j++){
                flag[s[j]] = -1;
            }
            start = flag[s[i]] + 1;
        }
        flag[s[i]] = i;
    }
    return max;
}
