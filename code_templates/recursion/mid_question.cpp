#include <iostream>
using namespace std;
#define n 8

bool checkLeftDiagonal(int arr[n][n], int kx, int ky, int qx, int qy, int rx, int ry)
{

    if (kx < 0 || kx >= n || ky < 0 || ky >= n)
        return false;

    if ((kx == qx && ky == qy) || (kx == rx && ky == ry))
    {
        return true;
    }

    return checkLeftDiagonal(arr, kx + 1, ky + 1, qx, qy, rx, ry) || checkLeftDiagonal(arr, kx - 1, ky - 1, qx, qy, rx, ry);
}

bool checkRightDiagonal(int arr[n][n], int kx, int ky, int qx, int qy, int rx, int ry)
{

    if (kx < 0 || kx >= n || ky < 0 || ky >= n)
        return false;

    if ((kx == qx && ky == qy) || (kx == rx && ky == ry))
    {
        return true;
    }

    return checkRightDiagonal(arr, kx + 1, ky + 1, qx, qy, rx, ry) || checkRightDiagonal(arr, kx - 1, ky - 1, qx, qy, rx, ry);
}

bool canMove(int arr[n][n], int qx, int qy, int kx, int ky, int rx, int ry)
{
    if (kx == qx || kx == rx) return false; 
    if (ky == qy || ky == ry) return false; 

    if (kx == qx || kx == rx)
    {
        return false;
    }
    if (ky == qy || ky == ry)
    {
        return false;
    }
    if (checkLeftDiagonal(arr, kx, ky, qx, qy, rx, ry))
    {
        return false;
    }
    if (checkRightDiagonal(arr, kx, ky, qx, qy, rx, ry))
    {
        return false;
    }
    return true;
}

int main()
{

    // int arr[n][n] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};

    int board[n][n] = {0};

    int qx, qy, kx, ky, rx, ry;

    cin >> kx >> ky;
    cin >> qx >> qy;
    cin >> rx >> ry;

    if (canMove(board, qx, qy, kx+1, ky, rx, ry))
    {
        cout << "You can move";
    }
    else if (canMove(board, qx, qy, kx-1, ky, rx, ry))
    {
        cout << "You can move";
    }
    else if (canMove(board, qx, qy, kx, ky+1, rx, ry))
    {
        cout << "You can move";
    }
    else if (canMove(board, qx, qy, kx, ky-1, rx, ry))
    {
        cout << "You can move";
    }
    else
    {
        cout << "You cannot move.. checkmate!!";
    }
}

