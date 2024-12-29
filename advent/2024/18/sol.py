import sys
from collections import deque

coords = []
for line in sys.stdin:
    l = line.strip().split(',')
    coords.append((int(l[0]), int(l[1])))


l = 0
r = len(coords)

while l != r:
    mid = (l + r) // 2
    print(l, r, mid)

    block = set()
    for i in range(mid):
        block.add(coords[i])

    dists = dict()

    q = deque()
    q.append((0, 0))
    dists[(0, 0)] = 0

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    while q:
        cur = q.popleft()

        for i in range(4):
            newx, newy = cur[0] + dx[i], cur[1] + dy[i]
            if 0 <= newx <= 70 and 0 <= newy <= 70 and (newx, newy) not in block and (newx, newy) not in dists:
                dists[(newx, newy)] = dists[cur] + 1
                q.append((newx, newy))

    if (70, 70) in dists:
        l = mid
    else:
        r = mid - 1

print(f'ans {l} {r}, {coords[l]}')