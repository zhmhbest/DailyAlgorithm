from typing import List


def spiralOrder(matrix: List[List[int]]) -> List[int]:
    # (0,0)
    #      ...→row
    #      ...
    #      ...
    #      ↓  (m, n)
    #     col
    m = len(matrix)
    n = len(matrix[0])
    # print(m, n)

    def get_pos():
        nonlocal matrix, pos
        val = matrix[pos[0]][pos[1]]
        matrix[pos[0]][pos[1]] = None
        return val

    def try_move():
        nonlocal pos, vec, m, n
        test_next_pos = (
            pos[0] + vectors[vec][0],
            pos[1] + vectors[vec][1]
        )
        if (
                test_next_pos[0] < m and
                test_next_pos[1] < n and
                matrix[test_next_pos[0]][test_next_pos[1]] is not None
        ):
            return test_next_pos
        else:
            return None

    vectors = {
        '→': (0, 1),
        '↓': (1, 0),
        '←': (0, -1),
        '↑': (-1, 0)
    }
    holder = []
    pos = (0, 0)
    vec = '→'
    for i in range(m * n):
        holder.append(get_pos())
        next_pos = try_move()
        if next_pos is not None:
            pos = next_pos
        else:
            if '→' == vec:
                vec = '↓'
            elif '↓' == vec:
                vec = '←'
            elif '←' == vec:
                vec = '↑'
            elif '↑' == vec:
                vec = '→'
            next_pos = try_move()
            if next_pos is not None:
                pos = next_pos
            else:
                break
    return holder


if __name__ == '__main__':
    print(
        spiralOrder([
            [1, 2, 3, 4],
            [10, 11, 12, 5],
            [9, 8, 7, 6]
        ])
    )

    print(
        spiralOrder([[2, 5], [8, 4], [0, -1]])
    )

