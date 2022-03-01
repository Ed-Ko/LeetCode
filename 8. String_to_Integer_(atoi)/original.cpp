class Solution {
public:
    int myAtoi(string s) {
        int sign = 0;
        int overflow = 0;

        while(s[0] == ' ')
            s.erase(s.begin());

        if(s[0] == '-' || s[0] == '+'){
            if(s.length() == 1)
                cout << "only sign exist" << endl;
            else if(s[0] == '-')
                sign = 1;
            s.erase(s.begin());
        }

        int num = 0;

        while(s[0] - '0' <= 9 && s[0] - '0' >= 0 && s.length() != 0){
            if(num == 0 && (s[0] - '0' == 0)){
                s.erase(s.begin());
                continue;
            }

            if(sign == 0){
                if((INT_MAX - num) >= (s[0] - '0')){
                    num = num + (s[0] - '0');
                    s.erase(s.begin());
                    if(s[0] - '0' <= 9 && s[0] - '0' >= 0 && s.length() != 0){
                        if((INT_MAX / num) >= 10)
                            num *= 10;
                        else
                            overflow = 1;
                    }
                }
                else
                    overflow = 1;
            }
            else{
                if((INT_MIN - num) <= ((s[0] - '0') * -1)){
                    num = num - (s[0] - '0');
                    s.erase(s.begin());
                    if(s[0] - '0' <= 9 && s[0] - '0' >= 0 && s.length() != 0){
                        if((INT_MIN / abs(num)) <= -10){
                            num *= 10;
                        }
                        else
                            overflow = 1;
                    }
                }
                else
                    overflow = 1;
            }

            if(overflow == 1)
                break;

        }

        if(overflow == 1){
            if(sign == 0)
                return INT_MAX;
            else
                return INT_MIN;
        }
        else
            return num;

    }
};