import heapq

class Grafo:
    def __init__(self):
        self.vertices = {}

    def adicionar_vertice(self, valor, coordenada):
        self.vertices[valor] = coordenada

    def adicionar_aresta(self, inicio, fim, peso):
        if inicio not in self.vertices:
            raise ValueError(f"O vértice {inicio} não existe no grafo.")
        if fim not in self.vertices:
            raise ValueError(f"O vértice {fim} não existe no grafo.")
        self.vertices[inicio][fim] = peso

    def a_estrela(self, inicio, fim):
        heap = []
        heapq.heappush(heap, (0, inicio, [inicio]))
        visitados = set()

        while heap:
            custo, vertice_atual, caminho = heapq.heappop(heap)

            if vertice_atual == fim:
                return caminho, custo

            if vertice_atual in visitados:
                continue

            visitados.add(vertice_atual)

            for prox_vertice, peso in self.vertices[vertice_atual].items():
                heapq.heappush(heap, (custo + peso, prox_vertice, caminho + [prox_vertice]))

        return None


grafo = Grafo()
grafo.adicionar_vertice('A', {'B': 1, 'C': 5})
grafo.adicionar_vertice('B', {'A': 1, 'D': 3, 'E': 2})
grafo.adicionar_vertice('C', {'A': 5, 'E': 3})
grafo.adicionar_vertice('D', {'B': 3, 'E': 1, 'F': 5})
grafo.adicionar_vertice('E', {'B': 2, 'C': 3, 'D': 1, 'F': 2})
grafo.adicionar_vertice('F', {'D': 5, 'E': 2})

caminho, custo = grafo.a_estrela('A', 'F')
if caminho:
    print(f"O caminho mais curto é: {caminho}, com custo total: {custo}")
else:
    print("Não foi possível encontrar um caminho entre os vértices especificados.")
