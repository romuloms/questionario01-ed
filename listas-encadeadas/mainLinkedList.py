from linkedlist import LinkedList


linkedList = LinkedList()


linkedList.append(1)

print(linkedList.get(0))
linkedList.set(0, 3)
print(linkedList.get(0))
linkedList.append(1)
linkedList.append(4)
linkedList.append(5)
linkedList.length()

linkedList.printList()
linkedList.removeElement(3)
linkedList.printList()
linkedList.length()
