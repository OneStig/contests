sum = 0

for _ in range(220):
    card = input().split(':')[1].strip()
    hits = set(card.split(' | ')[1].strip().split(' '))
    nums = card.split(' | ')[0].strip().split(' ')

    points = 1
    for n in nums:
        if n != '' and n in hits:
            points *= 2

    if points != 1:
        sum += points / 2

print(sum)
