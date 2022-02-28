class Solution {
public:
    int reverse(int x) {
        int abs_x = abs(x);
        int sum = 0;
        int error = 0;

        if(abs_x == 0)
            return 0;

        if(x > 0){
            while(abs_x % 10 == 0)
                abs_x /= 10;
            while(abs_x > 0 && error == 0){
                ///cout << "abs_x : " << abs_x << endl;

                ///cout << " !!!! " << (INT_MAX - sum) << " " << (abs_x % 10) << endl;
                if((INT_MAX - sum) >= (abs_x % 10)){
                    sum += (abs_x % 10);
                    abs_x /= 10;
                    ///cout << ((INT_MAX - 1) / sum) << " " << 10 << endl;
                    if(abs_x == 0)
                        break;
                    if((INT_MAX / sum) >= 10){
                        sum *= 10;
                        ///cout << " !!!! sum : " << sum << endl;
                    }
                    else
                        error = 1;
                }
                else
                    error = 1;
            }
        }
        else{

            while(abs_x % 10 == 0)
                abs_x /= 10;
            while(abs_x > 0 && error == 0){
                ///cout << "abs_x : " << abs_x << endl;

                ///cout << " !!!! " << (INT_MIN - sum) << " " << ((abs_x % 10) * -1) << endl;
                if((INT_MIN - sum) <= ((abs_x % 10) * -1)){
                    sum -= (abs_x % 10);
                    abs_x /= 10;
                    if(abs_x == 0)
                        break;
                    ///cout << abs(INT_MIN / abs(sum)) << " " << 10 << endl;
                    if((INT_MIN / abs(sum)) <= -10){
                        sum *= 10;
                        ///cout << " !!!! sum : " << sum << endl;
                    }
                    else
                        error = 1;
                }
                else
                    error = 1;
            }

        }

        if(error == 1)
            return 0;
        else if(sum % 10 == 0)
            return sum / 10;
        else
            return sum;
        }
};