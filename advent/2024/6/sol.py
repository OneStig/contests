import sys

g = []
for line in sys.stdin:
    line = line.strip()
    g.append(line)

ans = set()

sr, sc = 0, 0
for r in range(len(g)):
    for c in range(len(g[r])):
        if g[r][c] == '^':
            sr = r
            sc = c

goto = 0
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

while 0 <= sr < len(g) and 0 <= sc < len(g[0]):
    ans.add((sr, sc))
    nr = sr + dr[goto]
    nc = sc + dc[goto]

    while 0 <= nr < len(g) and 0 <= nc < len(g[0]) and g[nr][nc] == '#':
        goto = (goto + 1) % 4
        nr = sr + dr[goto]
        nc = sc + dc[goto]
    sr = nr
    sc = nc


print(len(ans))

