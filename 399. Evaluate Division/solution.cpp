class Solution {
public:
    
    map<string,vector<pair<string,double>>> graph;
    
    vector<double> ans;
    
    
    void DFS(string start, string end, double& val, map<string, double>& visit, bool& found){
        
        visit[start] = 1;
        
        if(found == true)
            return;
        
        for(int i = 0 ; i < graph[start].size() ; i++){
            
            string child_now = graph[start][i].first;
            
            if(visit[child_now] != 1){
                
                ///cout << start << " -> " << child_now << " : " << val << endl;
                val *= graph[start][i].second;
                
                if(child_now == end){    
                    found = true;
                    return;
                }
                
                
                DFS(child_now, end, val, visit, found);
                
                
                if(found == true)
                    return;
                else
                    val /= graph[start][i].second;
            }
        }
        
        
        return;    
    }
    
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {    
        
        for(int i = 0 ; i < equations.size() ; i++){
            
            pair<string,double> tmp;
            tmp.first = equations[i][1];
            tmp.second = values[i];
            graph[equations[i][0]].push_back(tmp);
                
            pair<string,double> tmp2;
            tmp2.first = equations[i][0];
            tmp2.second = double(1) / values[i];
            graph[equations[i][1]].push_back(tmp2);
            
        }
        
        /*
        for(map<string,vector<pair<string,double>>>::iterator it = graph.begin() ; it != graph.end() ; it++){
            cout << it->first << " : ";
            cout.precision(5);
            for(int i = 0 ; i < it->second.size() ; i++){
                cout << "(" << it->second[i].first << " " << fixed << it->second[i].second << ")";
            }
            cout << endl;
        }
        
        */
        
        for(int i = 0 ; i < queries.size() ; i++){
            
            if(graph.find(queries[i][0]) == graph.end() ||  graph.find(queries[i][1]) == graph.end())
                ans.push_back(-1);
            else{
                bool found = false;
                map<string, double> visit;
                double val = 1;
                string start = queries[i][0];
                string end = queries[i][1];
                
                if(start == end){
                    ans.push_back(1);
                    found = true;
                    continue;
                }
                    
                DFS(start, end, val, visit, found);
                
                if(found == false)
                    ans.push_back(-1);
                else
                    ans.push_back(val);
            }
        }
        
        return ans;
    }
};