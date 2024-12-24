def check_safe(l):
    is_decreasing = True if l[0] > l[1] else False
    if is_decreasing:
        if ((l[0] - l[1]) > 3) or ((l[0]-l[1]) < 1):
            return False, 0
    elif (l[1] - l[0]) > 3 or ((l[1]-l[0]) < 1):
        return False, 0
    for i in range(1,len(l)-1):
        if is_decreasing:
            diff = l[i] - l[i+1]
            if diff < 1 or diff > 3:
                return False, i
        else:
            diff = l[i+1] - l[i]
            if diff < 1 or diff > 3:
                return False, i
    return True, 0

f = open("input.txt")
safe_count = 0
for line in f:
    l = list(map(int, line.split()))
    print(f"{l=}")
    safe, index = check_safe(l)
    if safe:
        print("l is safe")
        safe_count+=1
        continue
    else: 
        l2 = l.copy()
        del l[index]
        safe, _ = check_safe(l)
        if not safe:
            del l2[index+1]
            safe , _ = check_safe(l2)
        if safe:
            print(f"with {index=} removed, {l=} or {l2=} is safe")
            safe_count +=1
        else:
            print(l, l2)

print(safe_count)

