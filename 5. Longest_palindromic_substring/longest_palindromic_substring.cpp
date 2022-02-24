#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
#include<stack>

using namespace std;

int main(){
    
    string s = "abcghhgcbaabcba";
    string sub = "";
    string max_sub = "";

    for(int i = 0 ; i < s.length() ; i++){
        for(int j = i + 1 ; j < s.length() ; j++){
            sub = s.substr(i,j-i+1);
            int head = 0;
            int tail = j-i;
            if(sub.length() % 2 == 0){
                int check = 0;
                while(head < tail){
                    if(sub[head] != sub[tail]){
                        check = 1;
                        break;
                    }
                    head++;
                    tail--;
                }
                if(check == 0){
                    cout << sub << endl;
                    if(max_sub.length() < sub.length())
                        max_sub = sub;
                }
            }
            else{
                int check = 0;
                while(head < tail){
                    if(sub[head] != sub[tail]){
                        check = 1;
                        break;
                    }
                    head++;
                    tail--;
                    
                }
                if(check == 0){
                    cout << sub << endl;
                    if(max_sub.length() < sub.length())
                        max_sub = sub;
                }
            }
        }
    }

    cout << max_sub << endl;

    return 0;
}

