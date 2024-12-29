import sys
import functools

keypad = [
    "789",
    "456",
    "123",
    " 0A"
]

direc = [
    " ^A",
    "<v>"
]

kpd = dict()
dirc = dict()

for i in range(4):
    for j in range(3):
        kpd[keypad[i][j]] = (i, j)

for i in range(2):
    for j in range(3):
        dirc[direc[i][j]] = (i, j)

ans = 0

MX_DEPTH = 25

@functools.cache
def fromtopad(a, b):
    dr, dc = kpd[a]
    dr -= kpd[b][0]
    dc -= kpd[b][1]

    lr = "<" if dc > 0 else ">"
    ud = "^" if dr > 0 else "v"
    lr = lr * abs(dc)
    ud = ud * abs(dr)

    option_a = 'A' + lr + ud + 'A'
    option_b = 'A' + ud + lr + 'A'

    a_cost, b_cost = 0, 0
    for i in range(len(option_a) - 1):
        a_cost += fromtodir(option_a[i], option_a[i + 1], MX_DEPTH)
    for i in range(len(option_b) - 1):
        b_cost += fromtodir(option_b[i], option_b[i + 1], MX_DEPTH)

    if (kpd[a][0], kpd[b][1]) == (3, 0) or (kpd[b][0], kpd[a][1]) == (3, 0):
        if dr > 0:
            return b_cost
        else:
            return a_cost

    return min(a_cost, b_cost)

@functools.cache
def fromtodir(a, b, depth):
    dr, dc = dirc[a]
    dr -= dirc[b][0]
    dc -= dirc[b][1]

    if depth == 0:
        return 1

    lr = "<" if dc > 0 else ">"
    ud = "^" if dr > 0 else "v"
    lr = lr * abs(dc)
    ud = ud * abs(dr)

    option_a = 'A' + lr + ud + 'A'
    option_b = 'A' + ud + lr + 'A'

    a_cost, b_cost = 0, 0
    for i in range(len(option_a) - 1):
        a_cost += fromtodir(option_a[i], option_a[i + 1], depth - 1)
    for i in range(len(option_b) - 1):
        b_cost += fromtodir(option_b[i], option_b[i + 1], depth - 1)

    if (dirc[a][0], dirc[b][1]) == (0, 0) or (dirc[b][0], dirc[a][1]) == (0, 0):
        if dr > 0:
            return a_cost
        else:
            return b_cost

    return min(a_cost, b_cost)

for line in sys.stdin:
    line = line.strip()
    num = int(line[:3])

    cost = 0

    last_c = 'A'
    for c in line:
        move = fromtopad(last_c, c)
        cost += move
        last_c = c

    print(f'cost: {cost}')
    ans += num * cost

print(ans)

print(fromtodir.cache_info())