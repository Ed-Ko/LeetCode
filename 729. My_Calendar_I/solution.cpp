class MyCalendar {
public:
    
    vector<pair<int,int>> record;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        int check = 1;
        for(int i = 0 ; i < record.size() ; i++){
            if( !((end <= record[i].first) || (start >= record[i].second)) ){
                check = 0;
                break;
            }
                
        }
        if(check){
            record.push_back(make_pair(start,end));
            return true;
        }
        return false;        
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */