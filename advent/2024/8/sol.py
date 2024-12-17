import sys
from collections import defaultdict

grid = []
for line in sys.stdin:
    grid.append(line.strip())

r, c = len(grid), len(grid[0])

freq = defaultdict(set)

for i in range(r):
    for j in range(c):
        if grid[i][j] != '.':
            freq[grid[i][j]].add((i, j))
        

an = set()
an2 = set()

for f in freq:
    fl = list(freq[f])
    print(f, fl)
    for a in fl:
        an2.add(a)
        for b in fl:
            if a != b:
                dx, dy = b[0] - a[0], b[1] - a[1]
                nx, ny = (b[0] + dx, b[1] + dy)

                if 0 <= nx < r and 0 <= ny < c:
                    an.add((nx, ny))

                while 0 <= nx < r and 0 <= ny < c:
                    an2.add((nx, ny))
                    nx += dx
                    ny += dy

print(len(an))
print(len(an2))
