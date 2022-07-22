class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans;
        ans.push_back(1);
        
        for(int i = 0 ; i < rowIndex ; i++){
            vector<int> tmp;
            if(i == 0)
                tmp.insert(tmp.begin(), {1, 1});
            else{
                for(int j = 0 ; j <= ans.size() ; j++){
                    int sum = 0;
                    if(j - 1 >= 0)
                        sum += ans[j - 1];
                    if(j < ans.size())
                        sum += ans[j];
                    tmp.push_back(sum);
                }
                
            }
            ans = tmp;
        }
        return ans;
    }
};