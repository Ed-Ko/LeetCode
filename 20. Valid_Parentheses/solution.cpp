class Solution {
public:
    bool isValid(string s) {
        stack<int> bracket;
        bool ans = true;
        for(int i = 0 ; i < s.length() ; i++){
            switch(s[i]){
                case ')': 
                    if(bracket.empty() || bracket.top() != '(')
                        return false;
                    else
                        bracket.pop();
                    break;
                case ']': ; 
                    if(bracket.empty() || bracket.top() != '[')
                        return false;
                    else
                        bracket.pop();
                    break;
                case '}': 
                    if(bracket.empty() || bracket.top() != '{')
                        return false;
                    else
                        bracket.pop();
                    break;
                default: bracket.push(s[i]);
            }
        }
        
        if(bracket.empty())
            return true;
        else
            return false;
    }
};