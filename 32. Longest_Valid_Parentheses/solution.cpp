class Solution {
public:
    int longestValidParentheses(string s) {
        
        if(s == "")
            return 0;
    
        stack<int> st;
        st.push(-1);
        
        int idx = 0;
        int ans = 0;
        while(idx < s.length()){
            
            if(s[idx] == '(')
                st.push(idx);
                
            if(s[idx] == ')'){
                if(!st.empty())
                    st.pop();
                
                if(!st.empty())
                    ans = max(ans, idx - st.top());
                else
                    st.push(idx);
                
            }
            
            idx++;
            
        }
        
        
        return ans;
            
        
        
    }
};