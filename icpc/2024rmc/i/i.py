w,h,n = [int(i) for i in input().split()]
lst = [int(i) for i in input().split()]
while len(lst) < 100:
    lst.append(0)
a = w
b = h
ans = 0
good = True
for bit in range(60):
    abit =  (a & (1 << bit)) > 0
    bbit =  (b & (1 << bit)) > 0
    area = 0
    if (abit):
        area += (1 << bit) *b
    if (bbit) :
        area += (1 << bit) * a
    if (abit and bbit):
        area -= (1 << bit) * (1 << bit)

    for s in range(bit,-1,-1):
        sa = (1 << s)* (1 << s)
        if (area // sa > lst[s]):
            area -= sa * lst[s]
            ans += lst[s]
            lst[s] = 0
        else:
            c = area//sa
            area -= sa * c
            ans += c
            lst[s] -= c
    if (area != 0):
        good = False
        break
    if (abit):
        a = a ^ (1 << bit)
    if (bbit):
        b = b ^ (1 << bit)
if (not good):
    print(-1)
else:
    print(ans)