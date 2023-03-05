def insertion_sort(a):
    for index in range(2, len(a)):
        key = a[index]
        i = index - 1
        while i > 0 and a[i] > key:
            a[i + 1] = a[i]
            i = i - 1
        a[i + 1] = key
    return a;
            
n = int(input("nums\n"));
a = [0]

while n > 0:
    a.append(int(input()))    
    n = n - 1
            
print(insertion_sort(a))
