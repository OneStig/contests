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

    tx += 10000000000000
    ty += 10000000000000

    det = ax * by - ay * bx

    if det == 0:
        continue

    a_num = tx * by - ty * bx
    b_num = ty * ax - tx * ay

    if a_num % det != 0 or b_num % det != 0:
        continue

    a = a_num // det
    b = b_num // det

    if a >= 0 or b >= 0:
        ans += a * 3 + b

print(ans)

# a * ax + b * bx = tx
# a * ay + b * by = ty
