def nested_sum(arr):
    if not arr:
        return 0
    elif not (isinstance(arr[0], list)):
        return arr[0] + nested_sum(arr[1:])
    else:
        return nested_sum(arr[0]) + nested_sum(arr[1:])

arr = [1,2,3,4,[4,[2,2]]]
print(nested_sum(arr))  
