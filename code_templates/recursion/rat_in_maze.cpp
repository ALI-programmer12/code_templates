#include <iostream>
#include <vector>
using namespace std;
#define n 4


bool canMove(int arr[n][n], int i, int j, int visited[n][n]){

    if ((i >=0 && i<n) && (j >= 0 && j<n) && visited[i][j] == 0 && arr[i][j] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isReached(int arr[n][n], int i, int j, int visited[n][n]){

    if (i == 2 && j == 0) //base case
    {
        visited[i][j] = 1;
        return true;
    }

    visited[i][j] = 1;
    if (canMove(arr, i+1, j, visited))
    {
        return isReached(arr, i+1, j, visited);
    }
    if (canMove(arr, i, j+1, visited))
    {
        return isReached(arr, i, j+1, visited);
    }
    if (canMove(arr, i-1, j, visited))
    {
        return isReached(arr, i-1, j, visited);
    }
    if (canMove(arr, i, j-1, visited))
    {
        return isReached(arr, i, j-1, visited);
    }

    visited[i][j] = 0;
    return false;
}   



int main(){
    int maze[4][4] = {
    {1, 1, 1, 1},
    {0, 0, 0, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1}
};
    int visited[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

    if (isReached(maze, 0, 0, visited))
    {
        cout<<"Successfully arrived"<<endl;
    }
    else
    {
         cout<<"Not arrived!!"<<endl;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<visited[i][j] <<" ";
        }
        cout<<endl;
    }
    
    


}