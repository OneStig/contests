import sys

ans = 0
for line in sys.stdin:
    line = line.strip().split(':')
    targ = int(line[0])
    nums = line[1].strip().split(' ')
    print(f'processing: {targ} {nums}')

    def bt(ind, cur):
        if ind == len(nums):
            if cur == targ:
                return targ
            else:
                return None

        tryadd = cur + int(nums[ind])
        addres = bt(ind + 1, tryadd)
        if addres is not None:
            return addres

        trymul = cur * int(nums[ind])
        mulres = bt(ind + 1, trymul)
        if mulres is not None:
            return mulres

        tryconc = int(str(cur) + nums[ind])
        return bt(ind + 1, tryconc)

    res = bt(1, int(nums[0]))

    if res is not None:
        ans += res

print(ans)
        
