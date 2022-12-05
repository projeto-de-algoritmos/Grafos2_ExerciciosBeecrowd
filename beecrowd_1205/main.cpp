#include <bits/stdc++.h>
#define oo 1000000010

using namespace std;
using ii = pair<int, int>;

/*
 * Computa a distância mínima entre os vértices de um grafo a um dado nó s.
 * Função adaptada de Edson Alves (https://github.com/edsomjr/TEP/blob/master/Grafos/slides/dijkstra/dijkstra.pdf)
 */
vector<int> dijkstra(vector<int> adj[], vector<int> c, int s, int N) {
    vector<int> dist(N + 1, oo);
    dist[s] = c[s];  // O custo na origem é a quantidade de atiradores naquele ponto.

    set<ii> U;  // Conjunto para identificação do vértice mais próximo de s.
    U.emplace(c[s], s);

    // Calcula a menor distância partindo do vértice s
    while (not U.empty()) {
        auto [d, u] = *U.begin();  // Distância/Custo (d) e vértice (v)
        U.erase(U.begin());

        for (int v : adj[u]) {
            if (dist[v] > d + c[v]) {
                if (U.count(ii(dist[v], v)))
                    U.erase(ii(dist[v], v));

                // Custo acumulado + quantidade de atiradores naquele ponto
                dist[v] = d + c[v];
                U.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int main() {
    int N;     // Número de pontos estratégicos (Nós)
    int M;     // Estradas ligando pontos estratégicos (Arestas)
    int K;     // Balas carregadas pelo soldado
    double P;  // Probabilidade do soldado matar um atirador

    // Loop enquanto != EOF
    while (cin >> N >> M >> K >> P) {
        int A;                           // Número de atiradores
        int O, D;                        // Origem e Destino do soldado, respectivamente
        int i, j;                        // Pares de estradas
        vector<int> graph[N + 1];        // Grafo de pontos estratégicos
        vector<int> shooters(N + 1, 0);  // Vetor guardando a quantidade de atiradores em cada ponto
        double ans = 0.0;

        // Salva as arestas do grafo na lista de adjacências
        while (M--) {
            cin >> i >> j;

            // Grafo bidirecional
            graph[i].push_back(j);
            graph[j].push_back(i);
        }

        cin >> A;
        int aux;

        // Salva a posição dos atiradores
        for (int i = 0; i < A; i++) {
            cin >> aux;
            shooters[aux]++;
        }

        cin >> O >> D;

        // Computa o vetor de distância com Dijkstra
        vector<int> dist = dijkstra(graph, shooters, O, N);

        // Calcula a probabilidade se o caminho existe e o soldado possui balas suficientes
        if (dist[D] <= K and dist[D] != oo) {
            ans = pow(P, dist[D]);
        }
        printf("%0.3f\n", ans);
    }

    return 0;
}