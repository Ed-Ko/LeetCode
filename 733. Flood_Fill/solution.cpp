class Solution {
public:
    
    void BFS(vector<vector<int>>& image, int sr, int sc, int color){
        
        queue<pair<int,int>> cq;
        
        int row_len = image.size();
        int col_len = image[0].size();
        int ori_color = image[sr][sc];
        
        cq.push(make_pair(sr,sc));
        
        while(!cq.empty()){
            vector<pair<int,int>> cvec;
            while(!cq.empty()){
                cvec.push_back(cq.front());
                cq.pop();
            }
            
            for(int i = 0 ; i < cvec.size() ; i++){
                
                int cur_row = cvec[i].first;
                int cur_col = cvec[i].second;
                
                cout << " === " << cur_row << " " << cur_col << endl;
                
                
                if(cur_row - 1 >= 0 && (cur_row - 1 != sr || cur_col != sc) && image[cur_row - 1][cur_col] == ori_color && image[cur_row - 1][cur_col] != color){
                    cout << cur_row - 1 << " " << cur_col << endl;
                    image[cur_row - 1][cur_col] = color;
                    cq.push(make_pair(cur_row - 1, cur_col));
                }
                
                if(cur_row + 1 < row_len && (cur_row + 1 != sr || cur_col != sc) && image[cur_row + 1][cur_col] == ori_color && image[cur_row + 1][cur_col] != color){
                    cout << cur_row + 1 << " " << cur_col << endl;
                    image[cur_row + 1][cur_col] = color;
                    cq.push(make_pair(cur_row + 1, cur_col));
                }
               
                if(cur_col - 1 >= 0 && (cur_row != sr || cur_col - 1 != sc) && image[cur_row][cur_col - 1] == ori_color && image[cur_row][cur_col - 1] != color){
                    cout << cur_row << " " << cur_col - 1 << endl;
                    image[cur_row][cur_col - 1] = color;
                    cq.push(make_pair(cur_row, cur_col - 1));
                }
                /*
                if(cur_row == 1 && cur_col + 1 == 2){
                    cout << "image[cur_row][cur_col + 1] : " << image[cur_row][cur_col + 1] << endl;
                    cout << "image[sc][sr] : " << image[sc][sr] << endl;
                    cout << "color : " << color << endl;
                }
                */
                if(cur_col + 1 < col_len && (cur_row != sr || cur_col + 1 != sc) && image[cur_row][cur_col + 1] == ori_color && image[cur_row][cur_col + 1] != color){
                    cout << cur_row << " " << cur_col + 1 << endl;
                    image[cur_row][cur_col + 1] = color;
                    cq.push(make_pair(cur_row, cur_col + 1));
                }
                    
                
            }
            cout << " =========== " << endl;
            
        }
        
        image[sr][sc] = color;
        
        return;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        BFS(image, sr, sc, color);
        return image;
    }
};