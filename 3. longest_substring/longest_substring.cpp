#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,vector<int>> dict;
        dict[s[0]].push_back(0);
        dict[s[1]].push_back(1);
        int len = 1;
        int head = 0;
        int tail = 1;
        if(s.length() <= 0)
            len = 0;
        else{
            while(tail < s.length()){
                //cout << "==== " << head << " > " << tail << endl;
                if(dict[s[tail]].size() >= 2){
                    if(tail - head > len){
                        if(tail == head + 1)
                            len = 1;
                        else
                            len = tail - head;
                    }

                    head = dict[s[tail]][0] + 1;
                    map<char,vector<int>>::iterator it;
                    for(it = dict.begin() ; it != dict.end() ; it++){
                        vector<int>::iterator it2;
                        for(it2 = it->second.begin() ; it2 != it->second.end() ; ){
                            if(*it2 < head)
                                it->second.erase(it2);
                            else
                                it2++;

                        }

                    }
                }
                tail++;
                dict[s[tail]].push_back(tail);
                //cout << " " << head << " > " << tail << endl;
            }
            if(len < tail - head)
                len = tail - head;
        }
        return len;
    }
};

