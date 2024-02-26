#include <iostream>
using namespace std;
const int N = 8; // Размер доски

// Функция для проверки, безопасно ли разместить ферзя на данной позиции
bool isSafe(int board[N][N], int row, int col) {
    // Проверяем вертикали вверх
    for (int i = 0; i < row; ++i)
        if (board[i][col])
            return false;

    // Проверяем левую диагональ вверх
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Проверяем правую диагональ вверх
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j)
        if (board[i][j])
            return false;

    return true;
}

// Рекурсивная функция для размещения ферзей
bool solveNQueensUtil(int board[N][N], int row) {
    // Базовый случай: все ферзи успешно размещены
    if (row == N)
        return true;

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            // Рекурсивный вызов для размещения остальных ферзей
            if (solveNQueensUtil(board, row + 1))
                return true;

            // Если размещение в текущей позиции не приводит к решению, отменяем размещение
            board[row][col] = 0;
        }
    }

    // Если нельзя разместить ферзя в текущей строке, возвращаем false
    return false;
}

// Функция для решения задачи о восьми ферзях
void solveNQueens() {
    int board[N][N] = { 0 }; // Создаем и заполняем нулями доску размером NxN

    // Вызываем рекурсивную функцию для размещения ферзей
    if (solveNQueensUtil(board, 0)) {
        // Выводим результат на экран
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Решение не найдено" << endl;
    }
}

int main() {
    solveNQueens(); // Решение задачи о восьми ферзях
    return 0;
}
