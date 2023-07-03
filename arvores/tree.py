

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def __str__(self):
        return str(self.data)

class BinaryTree:
    def __init__(self, data=None):
        if data:
            node = Node(data)
            self.root = node
        else:
            self.root = None

    # percurso em ordem simetrica
    def symmetricalRoute(self, node=None):
        # os parenteses sao especificos para esse exemplo
        if node is None:
            node = self.root
        if node.left:
            print('(', end='')
            self.symmetricalRoute(node.left)
        print(node, end='')
        if node.right:
            self.symmetricalRoute(node.right)
            print(')', end='')

    def postOrderRoute(self, node=None):
        if node is None:
            node = self.root
        if node.left:
            self.postOrderRoute(node.left)
        if node.right:
            self.postOrderRoute(node.right)
        print(node)

    def height(self, node=None):
        if node is None:
            node = self.root
        hleft = 0
        hright = 0
        if node.left:
            hleft = self.height(node.left)
        if node.right:
            hright = self.height(node.right)
        if hright > hleft:
            return hright + 1
        return hleft + 1
    
class BinarySearchTree(BinaryTree):
    def insert(self, value):
        parent = None
        aux = self.root
        while(aux):
            parent = aux
            if value < aux.data:
                aux = aux.left
            else:
                aux = aux.right
        if parent is None:
            self.root = Node(value)
        elif value < parent.data:
            parent.left = Node(value)
        else:
            parent.right = Node(value)
    
def postOrderExampleTree():
    tree = BinaryTree()
    n1 = Node('I')
    n2 = Node('N')
    n3 = Node('S')
    n4 = Node('C')
    n5 = Node('R')
    n6 = Node('E')
    n7 = Node('V')
    n8 = Node('A')
    n9 = Node('5')
    n10 = Node('3')

    n10.left = n6
    n10.right = n9
    n6.left = n1
    n6.right = n5
    n5.left = n2
    n5.right = n4
    n4.right = n3
    n9.left = n8
    n8.right = n7

    tree.root = n10
    return tree

if __name__ == "__main__":
    tree = postOrderExampleTree()
    print("Percurso em pós ordem:")
    tree.postOrderRoute()
    print("Altura: ", tree.height())
