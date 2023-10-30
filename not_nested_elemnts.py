def indef(x):
    return type(x) == type(None)

def unravel(arr):
    if len(arr) == 0:
        return []
    else:
        x, *xs = arr
        if indef(x):
            return []
        elif isinstance(x, list):
            return unravel(x + xs)
        elif isinstance(xs, list):
            return [x] + unravel(xs)

def myLength(arr):
    return len(unravel(arr))

lista = [[[[[1,[[2]]]]]],[3,4], [5,[[[[[[[[[6,[[[[7,8,9,[10]]]]]]]]]]]]]]]]

print(myLength(lista))
print(unravel(lista))
