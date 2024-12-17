from functools import cache

nums = [int(x) for x in input().strip().split()]

stones = 0

@cache
def calc(s, n):
    if n == 0:
        return 1

    if s == 0:
        return calc(1, n - 1)

    if len(str(s)) % 2 == 0:
        ss = str(s)
        mp = len(ss) // 2
        a = int(ss[:mp])
        b = int(ss[mp:])

        return calc(a, n - 1) + calc(b, n - 1)
    return calc(s * 2024, n - 1)

for x in nums:
    print(f'handling {x}')
    stones += calc(x, 75)

print(stones)

