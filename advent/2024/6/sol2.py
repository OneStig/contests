import sys

g = []
for line in sys.stdin:
    line = line.strip()
    g.append(line)

sr, sc = 0, 0
for r in range(len(g)):
    for c in range(len(g[r])):
        if g[r][c] == '^':
            sr = r
            sc = c

goto = 0
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

ans = 0
for br in range(len(g)):
    for bc in range(len(g[br])):
        print(br, bc)
        if g[br][bc] == '.':
            r, c = sr, sc
            goto = 0

            vis = set()

            good = 0
            while 0 <= r < len(g) and 0 <= c < len(g[0]):
                if (r, c, goto) in vis:
                    good = 1
                    break

                vis.add((r, c, goto))

                nr = r + dr[goto]
                nc = c + dc[goto]

                while 0 <= nr < len(g) and 0 <= nc < len(g[0]) and (g[nr][nc] == '#' or (nr == br and nc == bc)):
                    goto = (goto + 1) % 4
                    nr = r + dr[goto]
                    nc = c + dc[goto]

                r = nr
                c = nc

            ans += good

print(ans)
