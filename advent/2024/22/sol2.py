import sys
from collections import defaultdict

MOD = 16777216

def nxt(num):
    first = num * 64
    num = num ^ first
    num = num % MOD

    second = num // 32
    num = num ^ second
    num = num % MOD

    third = num * 2048
    num = num ^ third
    num = num % MOD

    return num

seq = defaultdict(int)

def nnxt(num, x):
    seen = set()
    prev = [num]
    p = [num % 10]
    for _ in range(x):
        prev.append(nxt(prev[-1]))
        p.append(prev[-1] % 10)

        if len(prev) > 4:
            delta = (p[-4] - p[-5], p[-3] - p[-4], p[-2] - p[-3], p[-1] - p[-2])
            if delta not in seen:
                seen.add(delta)
                seq[delta] += p[-1]


ans = 0
for line in sys.stdin:
    x = int(line.strip())
    cur = nnxt(x, 2000)

for x in seq:
    ans = max(ans, seq[x])

print(ans)