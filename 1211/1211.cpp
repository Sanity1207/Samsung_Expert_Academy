#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pairii;

vector<vector<int>> arr;
pairii max_pair;
int T;

int ladder(int i){
    
}

int main(){
    freopen("input.txt", "r", stdin);
    for(int test=0;test<T;test++){
        arr.assign(100,vector<int>(100,0));
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                cin>>arr[i][j];
            }
        }

        for(int i=0;i<100;i++){
            int result = ladder(i);
            if(result > max_pair.second){
                max_pair.first=  i;
                max_pair.second = result;
            }
        }
    }
}