f = open("input.txt")
safe_count = 0
for line in f:
    l = list(map(int, line.split()))
    is_decreasing = True if l[0] > l[1] else False
    if is_decreasing:
        if ((l[0] - l[1]) > 3) or ((l[0]-l[1]) < 1):
            continue
    elif (l[1] - l[0]) > 3 or ((l[1]-l[0]) < 1):
        continue
    safe = True
    for i in range(1,len(l)-1):
        if is_decreasing:
            diff = l[i] - l[i+1]
            if diff < 1 or diff > 3:
                safe = False
                break
        else:
            diff = l[i+1] - l[i]
            if diff < 1 or diff > 3:
                safe = False
                break
    if safe:
        print(f"safe : {l}")
        safe_count+=1
print(safe_count)
