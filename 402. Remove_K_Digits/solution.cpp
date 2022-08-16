class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.length() <= k)
            return "0";
        
        stack<int> st;
        st.push(num[0]);
        for(int i = 1 ; i < num.length() ; i++){
            
            while(k > 0 && !st.empty() && num[i] < st.top()){
                k--;
                st.pop();
            }
            
            st.push(num[i]);
            
            if(st.size() == 1 && num[i] == '0')
                st.pop();
        }
        
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }
        
        string ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        if(ans.length() != 0)
            return ans;
        return "0";
    }
};