import sys

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

def nnxt(num, x):
    for _ in range(x):
        num = nxt(num)
    return num

print(nxt(123))
print(nxt(15887950))

ans = 0
for line in sys.stdin:
    x = int(line.strip())
    cur = nnxt(x, 2000)
    print(x, cur)
    ans += cur
print(ans)