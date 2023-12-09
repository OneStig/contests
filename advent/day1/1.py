lines = open('input', 'r').read().splitlines()

sum = 0

digits = [
        'one',
        'two',
        'three',
        'four',
        'five',
        'six',
        'seven',
        'eight',
        'nine',
        ]

for line in lines:
    first = -1
    last = -1
    for c in line:
        if c.isdigit():
            if first == -1:
                first = int(c)

            last = int(c)

    sum += first * 10 + last

print(sum)

