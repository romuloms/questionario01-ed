import random
from tree import BinarySearchTree

random.seed(77)

values = random.sample(range(1, 1000), 42)

bst = BinarySearchTree()
for v in values:
    bst.insert(v)

bst.inOrderRoute()
print()

items = [1, 3, 981, 510, 1000]
for item in items:
    r = bst.search(item)
    if r is None:
        print(item, "nao encontrado")
    else:
        print(r.root.data, "encontrado")