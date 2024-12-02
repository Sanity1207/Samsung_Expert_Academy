#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pairii;

vector<vector<int>> arr;

int ladder(int i){
    pairii prev = {-1,-1};
    pairii cur = {0,i};
    int cnt = 0;
    bool overflag = false;
    while(cur.first <= 99){
        //사다리를 하나 탄다.
        cnt++;
        if(cur.second<99 && arr[cur.first][cur.second+1] == 1 && prev.second != cur.second+1){
            prev = {cur.first,cur.second};
            cur.second++;
        }else if(cur.second>0 && arr[cur.first][cur.second-1] == 1 && prev.second != cur.second-1){
            prev = {cur.first,cur.second};
            cur.second--;
        }else if (cur.first <= 98 && arr[cur.first+1][cur.second] == 1){
            prev = {cur.first,cur.second};
            cur.first++;
        }else {//at the end.
            break;
        }
    }

    if(cur.first == 99){
        return cnt;
    }else{
        return 1000001;
    }
    
}

int main(){
    freopen("input.txt", "r", stdin);
    for(int test=1;test<=10;test++){
        int temp;
        cin>>temp;
        pairii max_pair = {1000001,1000001};
        arr.assign(100,vector<int>(100,0));
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                cin>>arr[i][j];
            }
        }

        for(int i=0;i<100;i++){
            int result = ladder(i);
            if(result <= max_pair.second){
                max_pair.first=  i;
                max_pair.second = result;
            }
        }

        cout<<"#"<<test<<" "<<max_pair.first<<endl;
    }
}