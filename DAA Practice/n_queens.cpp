#include <iostream>
#include <vector>
using namespace std;

void display_chessboard(vector<vector<int>> &chessboard,int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(chessboard[i][j] == 0){
                cout << "-" << " ";
            }else{
                cout << chessboard[i][j] << " ";
            }
        }
        cout<< endl;
    }
    cout << endl;
}

bool check(int row,int col,int n,vector<vector<int>> &chessboard){
    for(int i = 0;i<row;i++){
        if(chessboard[i][0]){
            return false;
        }
    }

    for(int i = row-1,j=col-1;i >=0 && j>=0;i--,j--){
        if(chessboard[i][j]){
            return false;
        }
    }

    for(int i = row-1,j=col+1;i>=0&& j<n;i--,j++){
        if(chessboard[i][j]){
            return false;
        }
    }

    return true;
}

bool nqueens(vector<vector<int>> &chessboard, int n , int row,int col ,bool display){

    if (row == n){
        cout << "Final Chessboard: " << endl;
        display_chessboard(chessboard,n);
        return true;
    }else{
        for(int i = 0;i<n;i++){
            if (check(row,i,n,chessboard)){

                chessboard[row][i] = i+ 1;

                if(display){
                    cout << endl;
                    cout << "Placing Q" << row+1 << "at positon (" << row << " , " << i << " )" << endl; //imp
                    display_chessboard(chessboard,n);
                }

                if (nqueens(chessboard,n,row+1,i,display)){
                    return true;
                }

                chessboard[row][i] = 0;

                if(display){
                    cout << endl;
                    cout << "Backtracking removing Q" << row+1 << "from positon (" << row << " , " << i << " )" << endl; //imp
                    display_chessboard(chessboard,n);
                } 
            }
        }

        if(display){
            cout << endl;
            cout << "Unable to place Q" << row+1 << "in row" << row << " -- backtracking...." << endl; //imp
            display_chessboard(chessboard,n);
        } 

        return false;

    }
}



int main(){

    int n;
    
    cout << "Enter n:";
    cin >> n;
    cout << endl;

    if (n < 4){
        cout << " n value should > 4" << endl;
        return 0;
    }

    vector<vector<int>> chessboard(n,vector<int>(n,0));

    bool display = false;

    if (n > 8){
        nqueens(chessboard,n,0,0,display);
    }else{
        display = true;
        nqueens(chessboard,n,0,0,display);
    }

    return 0;
}