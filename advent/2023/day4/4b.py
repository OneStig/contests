cards = [1] * 220

for i in range(220):
    card = input().split(':')[1].strip()
    hits = set(card.split(' | ')[1].strip().split(' '))
    nums = card.split(' | ')[0].strip().split(' ')

    matches = 0

    for n in nums:
        if n != '' and n in hits:
            matches += 1
    
    for k in range(i + 1, i + 1 + matches):
        cards[k] += cards[i]

print(sum(cards))
