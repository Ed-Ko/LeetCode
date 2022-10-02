class Solution {
public:
    
    bool validUtf8(vector<int>& data) {
        
        int count = 0;
        
        for(int i = 0 ; i < data.size() ; i++){
            int cur_int = data[i];
            if(count == 0){
                if((cur_int >> 5) == 0b110)
                    count = 1;
                else if((cur_int >> 4) == 0b1110)
                    count = 2;
                else if((cur_int >> 3) == 0b11110)
                    count = 3;
                else if((cur_int >> 7) == 1)
                    return false;
            }
            else{
                if((cur_int >> 6) == 0b10)
                    count--;
                else
                    return false;
            }
        }

        return count == 0;
        
    }
};