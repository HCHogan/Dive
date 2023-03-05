a = []
def merge_sort1(i, j):
    if i >= j:
        return

    temp = []
    l = i
    mid = (i + j) // 2
    r = mid + 1

    merge_sort1(i, mid)
    merge_sort1(mid + 1, j)

    while l <= mid and r <= j:
        if a[l] <= a[r]:
            temp.append(a[l])
            l = l + 1
        else:
            temp.append(a[r])
            r = r + 1

    while(l <= mid):
        temp.append(a[l])
        l = l + 1

    while(r <= j):
        temp.append(a[r])
        r = r + 1

    for elem in temp:
        a[i] = elem
        i = i + 1

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)

def merge(left, right):
    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]
    return result

n = int(input("nums"))

while n > 0:
    n = n - 1
    a.append(int(input()))    

merge_sort1(0, len(a) - 1)
print(a)
