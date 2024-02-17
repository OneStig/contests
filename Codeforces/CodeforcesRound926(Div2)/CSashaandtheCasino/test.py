import math
def pc(k,x,a):
    curr_loss = 1
    for _ in range(2,x+2):
        curr_loss += math.ceil((curr_loss+1)/(k-1))
        if curr_loss > a:
            return 'NO'
    return 'YES'
 
num_tests = int(input())
for _ in range(num_tests):
    k,x,a = list(map(int, input().split()))
    print(pc(k,x,a))
