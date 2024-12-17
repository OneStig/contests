s = input().strip()

ans = 0
stuff = []

for i in range(0, len(s), 2):
    stuff.append([False, int(s[i]), i // 2])
    if i + 1 < len(s):
        stuff.append([True, int(s[i + 1]), i // 2])

for i in range(len(stuff) - 1, -1, -1):
    if not stuff[i][]

print(len)
print(ans)

