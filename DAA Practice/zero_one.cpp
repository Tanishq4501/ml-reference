#include <iostream>
#include <vector>
using namespace std;

void display_dp(vector<vector<int>> &dp){
    cout << "DP Table: " << endl;
    for(int i = 0;i<dp.size();i++){
        for(int j = 0;j<dp[0].size();j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int zero_one(vector<int> &profit,vector<int> &weight,int c,int n){

    vector<vector<int>> dp (n+1,vector<int>(c+1,0));

    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=c;j++){
            if(weight[i-1] <= j){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i-1]]+ profit[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    display_dp(dp);

    int j = c;
    
    for(int i = n;i> 0 && j> 0;i--){
        if(dp[i-1][j] != dp[i][j]){
            cout << "Item: " << "(" << "Weight: " << weight[i-1] << " , " << "Profit: "<<profit[i-1] << ")" << endl;
            j = j - weight[i-1];
        }
    }

    return dp[n][c];
}

int main(){

    int n;
    cout << "Enter no of elements: ";
    cin >> n;
    cout << endl;

    vector<int> profit,weight;

    cout << "Enter Profit: ";
    for(int i = 0;i<n;i++){
        cin >> profit[i];
    }
    cout << endl;
    cout << "Enter Weight: ";
    for(int i = 0;i<n;i++){
        cin >> weight[i];
    }
    cout << endl;

    int c;
    cout << "Enter capacity: ";
    cin >> c;
    cout << endl;

    int mx = zero_one(profit,weight,c,n);

    cout << "Total Maximum Profit: " << mx << endl;

    return 0;
}