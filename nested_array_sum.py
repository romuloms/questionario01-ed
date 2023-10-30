def soma_aninhado(arr):
    if not arr:
        return 0
    elif not (isinstance(arr[0], list)):
        return arr[0] + soma_aninhado(arr[1:])
    else:
        return soma_aninhado(arr[0]) + soma_aninhado(arr[1:])

arr = [1,2,3,4,[4,[2,2]]]
print(soma_aninhado(arr))  
