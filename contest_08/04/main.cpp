#include <iostream>
#include <tuple>

int** new_matrix(int rows, int cols, int value = 0);
std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows, int ccols);
std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols);
std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value = 1);
std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value = 1);
void delete_matrix(int*** matrix, int rows);
void print(int** matrix, int rows, int cols);

int main() {
    int rows_first, cols_first, first_init_val,
        rows_core, cols_core;

    std::cin >> rows_first >> cols_first >> first_init_val;
    int** first = new_matrix(rows_first, cols_first, first_init_val);
    for (int i = 0; i < rows_first; ++i)
        for (int j = 0; j < cols_first; ++j)
            std::cin >> first[i][j];

    std::cin >> rows_core >> cols_core;
    int** core = new_matrix(rows_core, cols_core);
    for (int i = 0; i < rows_core; ++i)
        for (int j = 0; j < cols_core; ++j)
            std::cin >> core[i][j];

    auto [conv, rows_conv, cols_conv] = convolution(first, rows_first, cols_first, core);
    std::tie(rows_conv, cols_conv) = add_row(&conv, rows_conv, cols_conv);
    std::tie(rows_conv, cols_conv) = add_col(&conv, rows_conv, cols_conv);
    std::tie(rows_conv, cols_conv) = add_col(&conv, rows_conv, cols_conv);

    auto [mult, rows_mult, cols_mult] = multiplication(conv, rows_conv, cols_conv, first, rows_first, cols_first);

    print(mult, rows_mult, cols_mult);

    delete_matrix(&first, rows_first);
    delete_matrix(&conv, rows_conv);
    delete_matrix(&mult, rows_mult);

    return 0;
}

int** new_matrix(int rows, int cols, int value) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = value;
        }
    }
    return matrix;
}

std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows, int ccols) {
    int** result = new_matrix(mrows - crows + 1, mcols - ccols + 1);

    for (int i = 0; i < mrows - crows + 1; ++i) {
        for (int j = 0; j < mcols - ccols + 1; ++j) {
            int sum = 0;
            for (int ci = 0; ci < crows; ++ci) {
                for (int cj = 0; cj < ccols; ++cj) {
                    sum += matrix[i + ci][j + cj] * core[ci][cj];
                }
            }
            result[i][j] = sum;
        }
    }

    return std::make_tuple(result, mrows - crows + 1, mcols - ccols + 1);
}

std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols) {
    int** result = new_matrix(arows, bcols);

    for (int i = 0; i < arows; ++i) {
        for (int j = 0; j < bcols; ++j) {
            int sum = 0;
            for (int k = 0; k < acols; ++k) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }

    return std::make_tuple(result, arows, bcols);
}

std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value) {
    int newRows = rows + 1;
    int** newMatrix = new_matrix(newRows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newMatrix[i][j] = (*matrix)[i][j];
        }
    }

    for (int j = 0; j < cols; ++j) {
        newMatrix[rows][j] = value;
    }

    delete_matrix(matrix, rows);
    *matrix = newMatrix;

    return std::make_tuple(newRows, cols);
}

std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value) {
    int newCols = cols + 1;
    int** newMatrix = new_matrix(rows, newCols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newMatrix[i][j] = (*matrix)[i][j];
        }
        newMatrix[i][cols] = value;
    }

    delete_matrix(matrix, rows);
    *matrix = newMatrix;

    return std::make_tuple(rows, newCols);
}

void delete_matrix(int*** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] (*matrix)[i];
    }
    delete[] *matrix;
    *matrix = nullptr;
}

void print(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

