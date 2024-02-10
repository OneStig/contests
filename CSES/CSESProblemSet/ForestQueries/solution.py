# WICS - ACM
# Python Forest Queries
# https://cses.fi/problemset/task/1652

n, q = map(int, input().split())

forest = [[]]
prefix = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

for _ in range(n):
    forest.append([''] + list(map(str, input().split())))

for r in range(1, n + 1):
    for c in range(1, n + 1):
        prefix[r][c] = 1 if forest[r][c] == '*' else 0
        prefix[r][c] += prefix[r - 1][c] + prefix[r][c - 1]
        prefix[r][c] -= prefix[r - 1][c - 1]

answer = ''

for _ in range(q):
    y1, x1, y2, x2 = list(map(int, input().split()))
    
    answer += f'{(prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1])}\n'

print(answer, end='')
