class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        if((num / 1000) >= 1){
            for(int i = 0 ; i < (num / 1000) ; i++)
                ans += "M";
        }

        num = num % 1000;

        if((num / 100) >= 1){
            if((num / 100) == 4)
                ans += "CD";
            else if((num / 100) == 9)
                ans += "CM";
            else{

                if((num / 100) >= 5){
                    ans += "D";
                    for(int i = 0 ; i < ((num / 100) - 5) ; i++)
                        ans += "C";
                }
                else{
                    for(int i = 0 ; i < (num / 100) ; i++)
                        ans += "C";
                }
            }
        }

        num = num % 100;

        if((num / 10) >= 1){
            if((num / 10) == 4)
                ans += "XL";
            else if((num / 10) == 9)
                ans += "XC";
            else{

                if((num / 10) >= 5){
                    ans += "L";
                    for(int i = 0 ; i < ((num / 10) - 5) ; i++)
                        ans += "X";
                }
                else{
                    for(int i = 0 ; i < (num / 10) ; i++)
                        ans += "X";
                }

            }
        }

        num = num % 10;

        if(num >= 1){
            if(num == 4)
                ans += "IV";
            else if(num == 9)
                ans += "IX";
            else{

                if(num >= 5){
                    ans += "V";
                    for(int i = 0 ; i < (num - 5) ; i++)
                        ans += "I";
                }
                else{
                    for(int i = 0 ; i < num; i++)
                        ans += "I";
                }

            }
        }

        return ans;
    }
};