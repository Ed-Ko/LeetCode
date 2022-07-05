class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(), products.end());
        
        vector<vector<string>> ans;
        
        for(int i = 1 ; i <= searchWord.length() ; i++){
            
            string cur_sub = searchWord.substr(0, i);
            vector<string> tmp;
            
            
            for(int j = 0 ; j < products.size() ; j++){
                
                if(products[j].substr(0, i) == cur_sub && tmp.size() < 3)
                    tmp.push_back(products[j]);
                
                
            }
            
            ans.push_back(tmp);
            
            
        }
        
        return ans;
        
    }
};