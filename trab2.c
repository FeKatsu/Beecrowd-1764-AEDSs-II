#include <stdio.h>
#include <stdlib.h>

typedef struct vert {
    int dado;
    int rank;
    struct vert* pai;
} Vert;

typedef struct aresta {
    int peso;
    Vert* u;
    Vert* v;
} Aresta;

void merge(Aresta* A, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    Aresta* L = (Aresta*)malloc(n1 * sizeof(Aresta));
    Aresta* R = (Aresta*)malloc(n2 * sizeof(Aresta));
    for (int i = 0; i < n1; i++) L[i] = A[inicio + i];
    for (int j = 0; j < n2; j++) R[j] = A[meio + 1 + j];
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i].peso <= R[j].peso)
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];
    free(L);
    free(R);
}

void mergeSort(Aresta* A, int inicio, int fim) {
    if (inicio >= fim) return;
    int meio = (inicio + fim) / 2;
    mergeSort(A, inicio, meio);
    mergeSort(A, meio + 1, fim);
    merge(A, inicio, meio, fim);
}

Vert* criaVert(int dado) {
    Vert* novo = (Vert*)malloc(sizeof(Vert));
    novo->dado = dado;
    novo->pai = novo;
    novo->rank = 0;
    return novo;
}

Vert* find(Vert* i) {
    if (i != i->pai) {
        i->pai = find(i->pai);
    }
    return i->pai;
}

void unionSets(Vert* x, Vert* y) {
    Vert* sx = find(x);
    Vert* sy = find(y);
    if (sx->rank > sy->rank) {
        sy->pai = sx;
    } else {
        sx->pai = sy;
        if (sx->rank == sy->rank) {
            sy->rank++;
        }
    }
}

int kruskal(int n, int m, Aresta* A) {
    mergeSort(A, 0, m - 1);
    int somaArestas = 0, arestasInc = 0;
    for (int i = 0; i < m; i++) {
        if (find(A[i].u) != find(A[i].v)) {
            somaArestas += A[i].peso;
            unionSets(A[i].u, A[i].v);
            arestasInc++;
            if (arestasInc == n - 1) break;
        }
    }
    return somaArestas;
}

int main() {
    int m, n;
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;
        Aresta* A = (Aresta*)malloc(n * sizeof(Aresta));
        
        Vert** vertices = (Vert**)malloc(m * sizeof(Vert*));
        for (int i = 0; i < m; i++) {
            vertices[i] = criaVert(i);
        }

        for (int i = 0; i < n; i++) {
            int u, v, peso;
            scanf("%d %d %d", &u, &v, &peso);
            A[i].u = vertices[u];
            A[i].v = vertices[v];
            A[i].peso = peso;
        }

        printf("%d\n", kruskal(m, n, A));

        free(A);
        free(vertices);
    }
    return 0;
}
