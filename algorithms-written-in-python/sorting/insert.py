def insert(A, n):
    i = 1

    while i <= n:
        loc = i - 1
        item = A[i]

        while loc >= 0 and item < A[loc]:
            A[loc + 1] = A[loc]
            loc -= 1
        
        A[loc + 1] = item
        i += 1

A = input().split()
A = list(map(int, A))

insert(A, len(A) - 1)
print(A)