def resolver_labirinto(labirinto):
    if not labirinto:
        return []
    
    n = len(labirinto)
    m = len(labirinto[0])
    
    def busca(x, y, caminho):
        if x < 0 or x >= n or y < 0 or y >= m or labirinto[x][y] == 1 or labirinto[x][y] == 2:
            return False

        caminho.append((x, y))
        
        if x == n - 1 and y == m - 1:
            return True

        labirinto[x][y] = 2

        if busca(x + 1, y, caminho) or busca(x - 1, y, caminho) or busca(x, y + 1, caminho) or busca(x, y - 1, caminho):
            return True

        caminho.pop()
        return False

    caminho = []
    if busca(0, 0, caminho):
        return caminho
    else:
        return []


labirinto = [
    [0, 1, 0, 0, 0],
    [0, 0, 0, 1, 0],
    [1, 1, 0, 1, 0],
    [1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0]
]

caminho = resolver_labirinto(labirinto)
if caminho:
    print("Caminho encontrado:")
    for i, j in caminho:
        print(f"({i}, {j})")
else:
    print("Não há caminho para a saída.")
