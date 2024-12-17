from collections import deque
s = input()

ans = 0
stuff = deque()

for i in range(0, len(s), 2):
    stuff.append([False, int(s[i]), i // 2])
    if i + 1 < len(s):
        stuff.append([True, int(s[i + 1], 0)])

pos = 0
while stuff:
    if stuff[-1][0]:
        stuff.pop()
    elif not stuff[0][0]:
        count, xid = stuff[0][1], stuff[0][2]
        print(count, xid)
        stuff.popleft()
        targ = pos + count
        while pos < targ:
            ans += pos * xid
            pos += 1
    elif stuff[0][0]:
        gap = stuff[0][1]
        filler = stuff[-1][1]

        if filler > gap:
            stuff.popleft()
            stuff.appendleft([False, gap, stuff[-1][2]])
            stuff[-1][1] -= gap
        else:
            stuff[0][1] -= filler
            stuff.appendleft([False, filler, stuff[-1][2]])
            stuff.pop()

print(ans)

