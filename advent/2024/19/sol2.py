import sys
from functools import cache

avail = []
proc = []
for line in sys.stdin:
    if ',' in line:
        avail = [x.strip() for x in line.split(',')]
    else:
        line = line.strip()
        if line:
            proc.append(line)

ans2 = 0

@cache
def can_make(s):
    if s == '':
        return 1

    cur_sum = 0
    for a in avail:
        if len(s) >= len(a) and s[:len(a)] == a:
            cur_sum += can_make(s[len(a):])

    return cur_sum

for cand in proc:
    ans2 += can_make(cand)

print(ans2)