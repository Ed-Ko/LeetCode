#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int idx1=0;
        int idx2=0;
        int check=0;
        map<int,int> dict;
        for(int i = 0 ; i < nums.size() ; i++){
            if(dict.find(target - nums[i]) != dict.end()){
                idx1 = i;
                idx2 = dict.find(target - nums[i])->second;
                break;
            }
            else
                dict[nums[i]] = i;
        }
        vector<int> result = {idx1,idx2};
        return result;
    }
};