class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans;
        
        int a_idx = a.length() - 1;
        int b_idx = b.length() - 1;
        int cur_sum;
        int carry = 0x0;
        while(a_idx >= 0 || b_idx >= 0){
            
            int cur_a;
            if(a_idx >= 0)
                cur_a = a[a_idx] == '1' ? 0x1 : 0x0;
            
            int cur_b;
            if(b_idx >= 0)
                cur_b = b[b_idx] == '1' ? 0x1 : 0x0;
            
            if(a_idx < 0){
                while(b_idx >= 0){
                    string tmp;
                    cur_b = b[b_idx] == '1' ? 0x1 : 0x0;
                    cout << (cur_b ^ carry) << endl;
                    if((cur_b ^ carry))
                        ans.insert(0, "1");
                    else
                        ans.insert(0, "0");
                    carry = (cur_b && carry);
                    b_idx--;
                    
                }                
            }
            else if(b_idx < 0){
                while(a_idx >= 0){
                    string tmp;
                    cur_a = a[a_idx] == '1' ? 0x1 : 0x0;
                    if((cur_a ^ carry))
                        ans.insert(0, "1");
                    else
                        ans.insert(0, "0");
                    carry = (cur_a && carry);
                    a_idx--;
                    
                }                
            }
            else{
                
                string tmp;
                if((cur_a ^ cur_b ^ carry))            
                    ans.insert(0, "1");
                else
                    ans.insert(0, "0");
                
                carry = cur_a + cur_b + carry >= 2 ? 0x1 : 0x0;
                
                a_idx--;
                b_idx--;
                
            }
                
        }
        if(carry)
            ans.insert(0, to_string(carry));
        return ans;
        
    }
};