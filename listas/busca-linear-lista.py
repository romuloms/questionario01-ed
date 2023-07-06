def search(list, element):
    """Retorna o índice do elemento se ele estiver na list ou None, caso nao esteja"""
    for i in range(len(list)):
        if list[i] == element:
            return i
    return None

weirdList = [8, "5", 32, 0, "python", 11]
elem = "python"

index = search(weirdList, elem)
if index is not None:
    print("index of element {} is {}".format(elem, index))
else:
    print("the element {} is not on the list".format(elem))
