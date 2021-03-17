# 递归超时
# def numDistinct(s: str, t: str) -> int:
#     if s == t or 0 == len(t):
#         return 1
#     count = 0
#     for i in range(len(s) - len(t) + 1):
#         if s[i] != t[0]:
#             continue
#         count += numDistinct(s[i+1:], t[1:])
#     return count


def numDistinct(s: str, t: str) -> int:
    m, n = len(s), len(t)
    if m < n:
        return 0

    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        dp[i][n] = 1

    for i in range(m - 1, -1, -1):
        for j in range(n - 1, -1, -1):
            if s[i] == t[j]:
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j]
            else:
                dp[i][j] = dp[i + 1][j]
    return dp[0][0]


if __name__ == '__main__':
    print(
        "result",
        numDistinct("rabbbit", "rabbit")
    )
    print(
        "result",
        numDistinct("babgbag", "bag")
    )
