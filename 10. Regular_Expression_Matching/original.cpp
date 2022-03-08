class Solution {
public:
    bool isMatch(string s, string p) {
        int idx_s = 0;
        int idx_p = 0;
        bool ans = true;

        while(1){

            string sub = "";
            while(p[idx_p] != '*' && idx_p < p.length() && idx_s < s.length()){
                if((idx_p + 1) < p.length()){
                    if(p[idx_p + 1] == '*')
                        break;
                }                    

                if(p[idx_p] != s[idx_s] && p[idx_p] != '.')
                    break;

                idx_s++;
                idx_p++;

            }

            ///cout << "sub(normal) : " << sub << endl;
            ///cout << "ans(normal) :" << ans << endl;
            ///cout << "idx_s : " << idx_s << endl;
            ///cout << "idx_p : " << idx_p << endl;

            if(sub != ""){
                for(int i = 0 ; i < sub.length() ; i++){
                    if(sub[i] == '.')
                        continue;
                    else if(s[idx_s + i] != sub[i])
                        break;

                }
                idx_s += sub.length();
                sub = "";

            }



            if(p[idx_p + 1] == '*'){
                sub += p[idx_p];
                idx_p += 2;
            }

            ///cout << "sub(star) : " << sub << endl;
            ///cout << "idx_s : " << idx_s << endl;
            ///cout << "idx_p : " << idx_p << endl;

            if(sub != ""){
                if(sub == ".")
                    idx_s = s.length();
                while(idx_s < s.length()){
                    if(sub[0] == s[idx_s]){
                        idx_s++;
                    }
                    else
                        break;
                }
                sub = "";
            }

            ///cout << "ans(star) :" << ans << endl;
            ///cout << "idx_s : " << idx_s << endl;
            ///cout << "idx_p : " << idx_p << endl;

            if(idx_s >= s.length() || idx_p >= p.length()){
                if(idx_s >= s.length() && idx_p >= p.length()){
                    ans = true;
                    break;
                }
                else{
                    ans = false;
                    break;
                }
            }


        }
        return ans;
    }
};