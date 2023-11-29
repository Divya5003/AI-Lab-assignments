#include <bits/stdc++.h>
using namespace std;

bool isBoardFull(vector<vector<char>> &board)
{
    for (auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == '_')
                return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> mat(3, vector<char>(3, '_'));
    char player = 'X';
    int flag = 0;
    while (flag == 0)
    {
        int row;
        int col;
        cout << "Player " << player << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && mat[row][col] == '_')
        {
            mat[row][col] = player;
            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }
        else
        {
            cout << "Invalid move. Try again!" << endl;
            continue;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        if (isBoardFull(mat))
        {
            cout << "It's a draw!" << endl;
            break;
        }
        for (int i = 0; i < 3; i++)
        {
            flag = 0;
            if (mat[i][0] == 'X' && mat[i][1] == 'X' && mat[i][2] == 'X')
            {
                cout << "Player X wins" << endl;
                flag = 1;
                break;
            }
            if (mat[i][0] == 'O' && mat[i][1] == 'O' && mat[i][2] == 'O')
            {
                cout << "Player O wins" << endl;
                flag = 1;
                break;
            }
            if (mat[0][i] == 'X' && mat[1][i] == 'X' && mat[2][i] == 'X')
            {
                cout << "Player X wins" << endl;
                flag = 1;
                break;
            }
            if (mat[0][i] == 'O' && mat[1][i] == 'O' && mat[2][i] == 'O')
            {
                cout << "Player O wins" << endl;
                flag = 1;
                break;
            }
        }
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j && mat[i][j] == 'X')
                {
                    count++;
                }
            }
        }
        if (count == 3)
        {
            cout << "Player X wins" << endl;
            flag = 1;
            break;
        }
        count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j && mat[i][j] == 'O')
                {
                    count++;
                }
            }
        }
        if (count == 3)
        {
            cout << "Player O wins" << endl;
            flag = 1;
            break;
        }
        count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == (3 - i + 1) && mat[i][j] == 'X')
                {
                    count++;
                }
            }
        }
        if (count == 3)
        {
            cout << "Player X wins" << endl;
            flag = 1;
            break;
        }
        count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == (3 - i + 1) && mat[i][j] == 'O')
                {
                    count++;
                }
            }
        }
        if (count == 3)
        {
            cout << "Player O wins" << endl;
            flag = 1;
            break;
        }
    }
    return 0;
}