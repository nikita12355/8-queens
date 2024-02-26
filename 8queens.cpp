#include <iostream>
using namespace std;
const int N = 8; // ������ �����

// ������� ��� ��������, ��������� �� ���������� ����� �� ������ �������
bool isSafe(int board[N][N], int row, int col) {
    // ��������� ��������� �����
    for (int i = 0; i < row; ++i)
        if (board[i][col])
            return false;

    // ��������� ����� ��������� �����
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // ��������� ������ ��������� �����
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j)
        if (board[i][j])
            return false;

    return true;
}

// ����������� ������� ��� ���������� ������
bool solveNQueensUtil(int board[N][N], int row) {
    // ������� ������: ��� ����� ������� ���������
    if (row == N)
        return true;

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            // ����������� ����� ��� ���������� ��������� ������
            if (solveNQueensUtil(board, row + 1))
                return true;

            // ���� ���������� � ������� ������� �� �������� � �������, �������� ����������
            board[row][col] = 0;
        }
    }

    // ���� ������ ���������� ����� � ������� ������, ���������� false
    return false;
}

// ������� ��� ������� ������ � ������ ������
void solveNQueens() {
    int board[N][N] = { 0 }; // ������� � ��������� ������ ����� �������� NxN

    // �������� ����������� ������� ��� ���������� ������
    if (solveNQueensUtil(board, 0)) {
        // ������� ��������� �� �����
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "������� �� �������" << endl;
    }
}

int main() {
    solveNQueens(); // ������� ������ � ������ ������
    return 0;
}
