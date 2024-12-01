#include <iostream>
#include <vector>

using namespace std;
vector<int> arr;
int n;
int total_view;

void add_view(int i);
int main(){
    for(int T = 1;T<=10;T++){
        cin>>n;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }

        for(int i=0;i<n;i++){
            if(arr[i] != 0)add_view(i);
        }
        cout<<"#"<<T<<" "<<total_view<<"\n";
        total_view = 0;
        arr.clear();
    }

}

void add_view(int i){
    int m1 = max(arr[i-1],arr[i-2]);
    int m2 = max(arr[i+1], arr[i+2]);

    int mfinal = max(m1,m2);
    if(mfinal < arr[i]) total_view += arr[i] - mfinal;
}