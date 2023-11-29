#include <bits/stdc++.h>
using namespace std;

struct Move
{
    int row;
    int col;
};

bool isBoardFull(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (const char cell : row)
        {
            if (cell == '_')
                return false;
        }
    }
    return true;
}
char checkWinner(const vector<vector<char>> &board)
{

    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] != '_' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }
    for (int i = 0; i < 3; ++i)
    {
        if (board[0][i] != '_' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    if (board[0][0] != '_' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != '_' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return '_';
}

int evaluateBoard(const vector<vector<char>> &board)
{
    char winner = checkWinner(board);
    if (winner == 'X')
        return 1;
    else if (winner == 'O')
        return -1;
    else
        return 0;
}

Move findBestMove(vector<vector<char>> &board, char currentPlayer)
{
    int bestScore = currentPlayer == 'X' ? -1000 : 1000;
    Move bestMove;
    Move result;
    if (isBoardFull(board) || checkWinner(board) != '_')
    {
        int score = evaluateBoard(board);
        result.row = score;
        result.col = bestMove.col;
        return result;
    }
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            if (board[row][col] == '_')
            {
                board[row][col] = currentPlayer;
                if (currentPlayer == 'X')
                {
                    int score = findBestMove(board, 'O').row;
                    if (score > bestScore)
                    {
                        bestScore = score;
                        bestMove.row = row;
                        bestMove.col = col;
                    }
                }
                else
                {
                    int score = findBestMove(board, 'X').row;
                    if (score < bestScore)
                    {
                        bestScore = score;
                        bestMove.row = row;
                        bestMove.col = col;
                    }
                }
                board[row][col] = '_';
            }
        }
    }
    result.row = bestScore;
    result.col = bestMove.col;
    return result;
}

void printBoard(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (const char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> board(3, vector<char>(3, '_'));
    char currentPlayer = 'X';
    while (true)
    {
        printBoard(board);
        if (checkWinner(board) != '_')
        {
            char winner = checkWinner(board);
            if (winner == 'X')
                cout << "Player X wins!" << endl;
            else
                cout << "Player O wins!" << endl;
            break;
        }
        else if (isBoardFull(board))
        {
            cout << "It's a draw!" << endl;
            break;
        }
        if (currentPlayer == 'X')
        {
            cout << "Player X's turn. Enter row and column (0-2): ";
            int row, col;
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '_')
            {
                board[row][col] = 'X';
                currentPlayer = 'O';
            }
            else
            {
                cout << "Invalid move. Try again!" << endl;
            }
        }
        else
        {
            cout << "Player O's turn" << endl;
            Move bestMove = findBestMove(board, 'O');
            board[bestMove.row][bestMove.col] = 'O';
            currentPlayer = 'X';
        }
    }
    printBoard(board);
    return 0;
}
