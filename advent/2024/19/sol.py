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

ans1 = 0

@cache
def can_make(s):
    if s == '':
        return True

    for a in avail:
        if len(s) >= len(a) and s[:len(a)] == a:
            if can_make(s[len(a):]):
                return True

    return False

for cand in proc:
    if can_make(cand):
        ans1 += 1

print(ans1)