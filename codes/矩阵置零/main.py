from typing import List
import numpy as np


def set_zeroes(matrix: List[List[int]]) -> None:
    row_len, col_len = len(matrix), len(matrix[0])
    flag_row0 = False
    flag_col0 = False

    # 首行
    for i in range(col_len):
        if 0 == matrix[0][i]:
            flag_row0 = True
            break
    # 首列
    for j in range(row_len):
        if 0 == matrix[j][0]:
            flag_col0 = True
            break

    # 提取到头
    for i in range(1, row_len):
        for j in range(1, col_len):
            if matrix[i][j] == 0:
                matrix[i][0] = matrix[0][j] = 0

    for i in range(1, row_len):
        if 0 == matrix[i][0]:
            for j in range(1, col_len):
                matrix[i][j] = 0

    for j in range(1, col_len):
        if 0 == matrix[0][j]:
            for i in range(1, row_len):
                matrix[i][j] = 0

    if flag_col0:
        for i in range(row_len):
            matrix[i][0] = 0
    if flag_row0:
        for j in range(col_len):
            matrix[0][j] = 0


if __name__ == '__main__':
    test_matrix1 = [
        [0, 1, 2, 7],
        [3, 4, 0, 2],
        [1, 3, 1, 5]
    ]
    set_zeroes(test_matrix1)
    print(np.array(test_matrix1))

    test_matrix2 = [
        [1, 2, 3, 4],
        [5, 0, 7, 8],
        [0, 10, 11, 12],
        [13, 14, 15, 0]
    ]
    set_zeroes(test_matrix2)
    print(np.array(test_matrix2))
