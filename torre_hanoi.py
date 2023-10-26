passos = 0

def torre_hanoi(n, origem, destino, auxiliar):
    global passos
    if n == 1:
        print(f'Mova o disco 1 de {origem} para {destino}')
        passos += 1
        return
    torre_hanoi(n-1, origem, auxiliar, destino)
    print(f'Mova o disco {n} de {origem} para {destino}')
    passos +=1
    torre_hanoi(n-1, auxiliar, destino, origem)

# Obs: a torre já vem com os discos em ordem crescente de diâmetro por conta de
# sua propriedade, ou seja, o algoritmo já considera os diâmetros
# Teste do programa com 3 discos
n = 3
torre_hanoi(n, 'A', 'C', 'B')
print(f"passos:{passos}")