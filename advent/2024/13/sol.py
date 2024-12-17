import sys

probs = []
for line in sys.stdin:
    line = line.strip()

    if line != '':
        probs.append(line)

ans = 0
n = len(probs) // 3

for i in range(n):
    cost = 1e18

    ay = int(probs[i * 3].split('+')[2])
    ax = int(probs[i * 3].split(',')[0].split('+')[1])
    
    by = int(probs[i * 3 + 1].split('+')[2])
    bx = int(probs[i * 3 + 1].split(',')[0].split('+')[1])

    ty = int(probs[i * 3 + 2].split('=')[2])
    tx = int(probs[i * 3 + 2].split(',')[0].split('=')[1])

    print(ax, ay, bx, by, tx, ty)

    for a in range(min(tx // ax, ty // ay)):
        if a * ax > tx or a * ay > ty:
            break

        xneed = tx - a * ax
        yneed = ty - a * ay

        if xneed % bx != 0 or yneed % by != 0 or xneed // bx != yneed // by:
            continue

        cost = min(cost, 3 * a + xneed // bx)

    if cost != 1e18:
        ans += cost

print(ans)

# a * ax + b * bx = tx
# a * ay + b * by = ty
