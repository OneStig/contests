import sys

ans = 0
enabled = True
for line in sys.stdin:
    for i in range(len(line) - 8):
        if line[i:i+4] == 'do()':
            enabled = True
        elif line[i:i+7] == 'don\'t()':
            enabled = False
        elif line[i:i+4] == 'mul(' and enabled:
            cur = ''

            j = i + 4
            while j < len(line) and j - i <= 11:
                cur += line[j]
                if line[j] == ')':
                    break
                j += 1

            if cur[-1] != ')':
                continue
            print(i, cur)
            cur = cur[:len(cur) - 1]
            nums = cur.split(',')
            print(nums)
            if len(nums) == 2 and nums[0].isdigit() and nums[1].isdigit() and 1 <= len(nums[0]) <= 3 and 1 <= len(nums[1]) <= 3:
                ans += int(nums[0]) * int(nums[1])

print(ans)
