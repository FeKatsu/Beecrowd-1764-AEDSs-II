# 🎄 Itinerário do Papai Noel - Árvore Geradora Mínima (Beecrowd 1764)
<img src="https://www.cefet-rj.br/attachments/article/431/vert_azul.png" alt="Logo do Projeto" width="200" style="display: block; margin: auto;"/>

- [Felipe Katsumoto](https://github.com/FeKatsu)

Curso de Engenharia de Computação - CEFET/RJ Uned Petrópolis.

Disciplina AEDs II - Professora Laura Assis

[Relatório completo](./Relatório_AEDS_II_2.pdf)

---

Este repositório contém a implementação da solução para o problema 1764 - Itinerário do Papai Noel, proposto na plataforma Beecrowd e passado como segundo trabalho da disciplina de Algoritmos e Estrutura de Dados II.

O problema consiste em encontrar a Árvore Geradora Mínima (AGM) de um grafo não-direcionado e ponderado, representando cidades e rotas que Papai Noel deve percorrer. O objetivo é garantir que todas as cidades sejam alcançáveis com o menor custo total possível.

## 🚀 Tecnologias e Algoritmos Utilizados

**Linguagem**: C
* **Algoritmo Principal**: Kruskal

* **Estrutura Auxiliar**: Union-Find (com Union by Rank e Path Compression)

* **Ordenação de Arestas**: MergeSort (complexidade _O(n log n)_)

## 📋 Descrição da Solução

1. Leitura do número de vértices e arestas do grafo.

2. Ordenação das arestas por peso (MergeSort).

3. Aplicação do algoritmo de Kruskal para selecionar arestas que não formem ciclos.

4. Uso da estrutura Union-Find para gerenciar os conjuntos disjuntos.

5. Cálculo da soma dos pesos que compõem a AGM, que é a resposta final.
