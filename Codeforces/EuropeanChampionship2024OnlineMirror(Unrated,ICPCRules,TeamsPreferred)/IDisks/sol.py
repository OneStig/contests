from collections import defaultdict
def solve(n,circles):
    adj = defaultdict(lambda: [])

    for i in range(n):
        x1 = circles[i][0]
        y1 = circles[i][1]
        r1 = circles[i][2]
        for j in range(i, n):
            x2 = circles[j][0]
            y2 = circles[j][1]
            r2 = circles[j][2]
            if (r1+r2) ** 2 == (abs(x1-x2) ** 2) + (abs(y1-y2) ** 2):
                adj[i].append(j)
                adj[j].append(i)


    print(adj);

    count1 = 0
    count2 = 0
    colors = [0] * n
    for i in range(n):
        if adj[i] == []:
            return "YES"
        if colors[i] == 0:
            print(f'hit {i}')
            colors[i] = 1
            count1 = 1
            stack = [(i,2)] # (curr, color to color neighbors)
            while stack:
                top = stack.pop()
                curr = top[0]
                color = top[1]
                print(f'colored {curr} as {color}')
                print(f'nb ad[i]')
                for neighbor in adj[curr]:
                    print(f'{neighbor} is nb of {i} with {colors[neighbor]}')
                    if colors[neighbor] == 0:
                        colors[neighbor] = color
                        if color == 1:
                            count1 += 1
                        elif color == 2:
                            count2 += 1
                        new_color = 1 if color == 2 else 2
                        stack.append((neighbor, new_color))
                    elif colors[neighbor] != color:
                        count1 = 0
                        count2 = 0
                        break
                    elif colors[neighbor] == color:
                        continue
            if count1 != count2:
                return "YES"

        count1 = 0
        count2 = 0

    return "NO"



    

n = int(input())
circles = []
for _ in range(n):
    x,y,r = list(map(int, input().split()))
    circles.append((x,y,r))
print(solve(n,circles))
