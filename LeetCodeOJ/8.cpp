long long StrToInt(char *digit, int minus){
    long long num = 0;
    while(*digit != '\0'){
        if(*digit >= '0' && *digit <= '9'){
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0');
            if(!minus && num > 0x7FFFFFFF){
                num = 0x7FFFFFFF;
                break;
            }
            else if(minus && num < (signed int)0x80000000){
                num = 0x80000000;
                break;
            }
            digit++;
        }
        else{
            break;
        }
    }
    return num;
}

int myAtoi(char* str) {
    long long num = 0;
    int minus = 0;
    if(str != NULL && *str != '\0'){
        char *digit = str;
        int flag = 0;
        
        while(*digit != '\0'){
            if(*digit == ' '){
                if(flag == 0){
                    digit++;
                }
                else{
                    break;
                }
            }
            else if(*digit == '+'){
                if(flag == 0){
                    flag = 1;
                    digit++;
                }
                else{
                    break;
                }
            }
            else if(*digit == '-'){
                if(flag == 0){
                    minus = 1;
                    flag = 1;
                    digit++;
                }
                else{
                    break;
                }
            }
            else if(*digit >= '0' && *digit <= '9'){
                num = StrToInt(digit, minus);
                break;
            }
            else{
                break;
            }
        }
    }
    return (int)num;
}
