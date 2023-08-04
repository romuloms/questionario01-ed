from linkedlist import LinkedList


linkedList = LinkedList()

print(len(linkedList))
linkedList.append(1)
print(len(linkedList))
print(linkedList.get(0))
linkedList.set(0, 3)
print(linkedList.get(0))
linkedList.append(1)
linkedList.append(4)
linkedList.append(5)
print(len(linkedList))

linkedList.printList()