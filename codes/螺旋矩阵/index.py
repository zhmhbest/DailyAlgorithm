from typing import List


def generateMatrix(n: int) -> List[List[int]]:
    # (0,0)
    #      ...→row
    #      ...
    #      ...
    #      ↓  (n-1, n-1)
    #     col
    def set_pos(val):
        nonlocal holder, pos
        holder[pos[0]][pos[1]] = val

    def try_move():
        nonlocal pos, vec
        test_next_pos = (
            pos[0] + vectors[vec][0],
            pos[1] + vectors[vec][1]
        )
        if (
                test_next_pos[0] < n and
                test_next_pos[1] < n and
                -1 == holder[test_next_pos[0]][test_next_pos[1]]
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
    holder = list([[-1 for _ in range(n)] for _ in range(n)])
    pos = (0, 0)
    vec = '→'
    for i in range(n ** 2):
        set_pos(i)
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
    def print_format(lol):
        for rows in lol:
            for item in rows:
                print(item, end=' ')
            print('')
        print('\n')

    print_format(generateMatrix(3))
    print_format(generateMatrix(4))
    print_format(generateMatrix(5))
