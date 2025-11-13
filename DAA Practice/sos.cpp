#include <iostream>
#include <vector>
using namespace std;

void sos(vector<int> &arr,int n,int index,int target,vector<int> &curr){

    if(target == 0){
        cout << "Output: { ";
        for(int i = 0;i<curr.size();i++){
            cout << curr[i] << " ";
        }
        cout << " }" << endl;
        return;
    }

    if(index == n || target < 0){
        return;
    }

    curr.push_back(arr[index]);
    sos(arr,n,index+1,target-arr[index],curr);
    curr.pop_back();
    sos(arr,n,index+1,target,curr);
}


int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    cout << endl;

    int target;
    cout << "Enter target sum: ";
    cin >> target;
    cout << endl;

    vector<int> curr;

    sos(arr,n,0,target,curr);

    return 0;
}