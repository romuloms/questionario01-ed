def searchSmaller(arr):
    smaller = arr[0]
    indexSmaller = 0
    for i in range(1, len(arr)):
        if arr[i] < smaller:
            smaller = arr[i]
            indexSmaller = i
    return indexSmaller

def selectionSort(arr):
    newArr = []
    for i in range(len(arr)):
        smaller = searchSmaller(arr)
        newArr.append(arr.pop(smaller))
    return newArr

print(selectionSort([5, 3, 6, 2, 10]))
