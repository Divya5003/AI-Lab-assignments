#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>> &board)
{
    for (auto row : board)
    {
        for (auto i : row)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;
    while (y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }
    return true;
}

void nQueens(int col, vector<vector<int>> &board, int n, bool &flag)
{
    if (col == n)
    {
        flag = true;
        printBoard(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            nQueens(col + 1, board, n, flag);
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    bool flag = false;

    vector<vector<int>> board(n, vector<int>(n, 0));
    nQueens(0, board, n, flag);

    if (!flag)
        cout << "No solution found" << endl;
    return 0;
}
