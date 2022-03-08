class Solution {
public:
        
    bool isMatch(string s, string p) {
        
        bool dp_mat[s.length() + 1][p.length() + 1];
        dp_mat[0][0] = true;

        /// p is empty but s is not empty, the answer is false 
        for(int i = 1 ; i <= s.length() ; i++)
            dp_mat[i][0] = false;

        /// s is empty but p is not empty, the answer depends
        for(int i = 1 ; i <= p.length() ; i++){

            /// if p[i-1] == '*', the result will inherit the previous result 
            if(p[i-1] == '*') 
                dp_mat[0][i] = dp_mat[0][i-2];

            /// if p[i-1] != '*', the result should be false
            else
                dp_mat[0][i] = false;
        }

        /// iterate all the element in 2-d matrix to finish DP
        for(int i = 1 ; i <= s.length() ; i++){
            for(int j = 1 ; j <= p.length() ; j++){

                if(p[j-1] != '*'){    

                    /// p[j] == s[i] or p[j] != s[i], 0 <= i <= s.length() , 0 <= j <= p.length()
                    /// result of dp_mat[i][j] equals dp_mat[i-1][j-1]
                    /// temporarily assign result, another case will be considered later
                    dp_mat[i][j] = dp_mat[i-1][j-1]; 

                    /// simply s[i-1] does not equal to p[j-1]
                    /// the result is false
                    if(p[j-1] != '.' && (s[i-1] != p[j-1]))
                        dp_mat[i][j] = false;
                }
                else {

                    /// p[j-1] is '*' and is not considered a character, so result of comparing
                    /// dp_mat[i][j-2] will be assigned temporarily to dp_mat[i][j]
                    dp_mat[i][j] = dp_mat[i][j-2];

                    /// 
                    if((p[j-2] == s[i-1]) || p[j-2] == '.')
                        dp_mat[i][j] = dp_mat[i][j] || dp_mat[i-1][j];


                }

            }
        }
        
        
        
        
        return dp_mat[s.length()][p.length()];
    }
};