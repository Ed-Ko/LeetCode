class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int x = 0;
        int y = 0;
        
        int dir = 0;
        
        vector<int> ans;
        
        while(x < mat.size() && y < mat[0].size()){
            switch(dir){
                case 0 : 
                    ans.push_back(mat[x][y]);
                    if(x - 1 < 0 || y + 1 >= mat[0].size()){
                        if(x - 1 < 0 && y + 1 >= mat[0].size())
                            x++;
                        else if(x - 1 < 0)
                            y++;
                        else
                            x++;
                        dir = 1;
                    }
                    else{
                        x--;
                        y++;
                    }
                break;
                case 1 : 
                    ans.push_back(mat[x][y]);
                    if(x + 1 >= mat.size() || y - 1 < 0){
                        if(x + 1 >= mat.size() && y - 1 < 0)
                            y++;
                        else if(y - 1 < 0)
                            x++;
                        else
                            y++;
                        dir = 0;
                    }
                    else{
                        x++;
                        y--;
                    }
                break;    
                    
            }
        }
        
        return ans;
        
    }
};