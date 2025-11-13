#include <iostream>
#include <vector>
using namespace std;

int partition (vector<vector<int>> &arr,int low,int high){
    int pivot = arr[low][2];
    int i = low + 1;
    int j = high;

    while(i<=j){
        if (i<=j && arr[i][2] >= pivot){
            i++;
        }
        if(i<=j && arr[j][2] <= pivot){
            j--;
        }
        if (i < j){
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[low],arr[j]);
    return j;
}

void quick_sort(vector<vector<int>> &arr,int low,int high){
    if (low<high){
        int p = partition(arr,low,high);
        quick_sort(arr,low,p-1);
        quick_sort(arr,p+1,high);
    }
}

void fractional_knapsack(vector<int> &profit,vector<int> &weight,int c){
    int n = weight.size();
    int rc = c;

    vector<vector<int>> ratio(n,vector<int>(3));
    vector<string> selection(n,"0");

    cout << "P/W Ratio: ";
    for(int i =0;i<n;i++){
        ratio[i][0] = profit[i];
        ratio[i][1] = weight[i];
        ratio[i][2] = (1.0*profit[i])/weight[i];
        cout << ratio[i][2] << " ";
    }

    cout << endl;

    double ans = 0.0;

    quick_sort(ratio,0,n-1);

    for(int i =0;i<n;i++){
        if(ratio[i][1] <= rc){
            ans += ratio[i][0];
            rc -= ratio[i][1];
            selection[i] = "1";
        }else{
            ans += (1.0*ratio[i][2])*rc;
            selection[i] = to_string((double)ratio[i][1]/rc);
            break;
        }
    }

    cout << "Items: ";
    for(int i = 0;i<n;i++){
        cout << "i" << i+1 << " ";
    }
    cout << endl;

    cout << "Selected: ";
    for(int i = 0;i<n;i++){
        cout << selection[i] << " ";
    }
    cout << endl;

    cout << "Total Maximum Profit: " << ans << endl;

}

int main(){
    int n;

    cout << "Enter no of elements: ";
    cin >> n;

    vector<int> profit,weight;

    cout << "Enter profit: ";
    for(int i = 0 ;i<n;i++){
        cin >> profit[i];
    }

    cout << "Enter weight: ";
    for(int i = 0;i<n;i++){
        cin >> weight[i];
    }

    int c;
    cout << "Enter capacity: ";
    cin >> c;

    cout << "Profit: ";
    for(int i = 0;i<n;i++){
        cout << profit[i] << " ";
    }
    cout << endl;

    cout << "Weight: ";
    for(int i =0;i<n;i++){
        cout << weight[i] << " ";
    }
    cout << endl;

    fractional_knapsack(profit,weight,c);
    return 0;
}