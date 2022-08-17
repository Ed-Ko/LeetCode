class Solution {
    public boolean backspaceCompare(String s, String t) {
        
        Stack<Character> st = new Stack<Character>();
        Stack<Character> st2 = new Stack<Character>();
        
        for(int i = 0 ; i < s.length() ; i++){
            if(s.charAt(i) == '#'){
                if(!st.empty())
                    st.pop();
            }
                
            else{
                st.push(s.charAt(i));
            }
        }
        
        for(int i = 0 ; i < t.length() ; i++){
            if(t.charAt(i) == '#'){
                if(!st2.empty())
                    st2.pop();
            }
                
            else{
                st2.push(t.charAt(i));
            }
            
        }
        
        while(!st.empty() && !st2.empty()){
            if(st.peek() == st2.peek()){
                st.pop();
                st2.pop();
            }
            else
                break;
        }
        
        if(!st.empty() || !st2.empty())
            return false;
        return true;
        
    }
}