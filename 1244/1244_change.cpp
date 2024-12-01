#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <thread>
#include <chrono>
#include <unordered_set>

using namespace std;
string num_to_str(int num){
    return to_string(num);
}

int str_to_num(string str){
    int res = 0;
    for(char c : str){
        res = res*10 + (c - '0');
    }
    return res;
}

string change(string str, int i, int j){
    string ret = str;
    swap(ret[i],ret[j]);
    return ret;
}

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    for(int test = 1;test<=T;test++){
        int k,n;
        cin>>k>>n;
        queue<string> q;
        vector<int8_t> visited(1000000,0);
        q.push(to_string(k));
        for(int stage = 1;stage <= n; stage++){
            int sz = q.size();
            while(sz-- >0){
                string cur = q.front();q.pop();
                for(int front = 0;front < cur.size();front++){
                    for(int back = front+1;back<cur.size();back++){
                        string next = change(cur,front,back);
                        int next_num = str_to_num(next);
                        if(visited[next_num] != stage){
                            q.push(next);
                            visited[next_num] = stage;
                        }
                    }
                }
            }
        }
        for(int i=999999;i>=0;i--){
            if(visited[i] == n){
                cout<<"#"<<test<<" "<<i<<endl;
                break;
            } 
            
        }
    }
}