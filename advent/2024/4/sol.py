import sys

g = []
for line in sys.stdin:
    g.append(line.strip())

ans = 0
for r in range(len(g)):
    for c in range(len(g[r])):
        tests = []
        if c < len(g[r]) - 3:
            tests.append(g[r][c:c+4])

        if r < len(g) - 3:
            tests.append(g[r][c] + g[r + 1][c] + g[r + 2][c] + g[r + 3][c])

        if c < len(g[r]) - 3 and r < len(g) - 3:
            tests.append(g[r][c] + g[r + 1][c + 1] + g[r + 2][c + 2] + g[r + 3][c + 3])

        if c > 2 and r < len(g) - 3:
            tests.append(g[r][c] + g[r + 1][c - 1] + g[r + 2][c - 2] + g[r + 3][c - 3])

        cur = 0
        for t in tests:
            if t == 'XMAS' or t == 'SAMX':
                cur += 1

        ans += cur

print(ans)

ans = 0

for r in range(len(g)):
    for c in range(len(g[r])):
        if r != 0 and c != 0 and r != len(g) - 1 and c != len(g[r]) - 1 and g[r][c] == 'A':
            a = g[r - 1][c - 1] + g[r][c] + g[r + 1][c + 1]
            b = g[r - 1][c + 1] + g[r][c] + g[r + 1][c - 1]

            if (a == 'MAS' or a == 'SAM') and (b =='MAS' or b =='SAM'):
                ans += 1

print(ans)

