#include <bits/stdc++.h>
#define oo 1000000010

using namespace std;
using ii = pair<int, int>;

/*
 * Computa a distância mínima entre todos os pares de vértices do grafo.
 * Função adaptada de Edson Alves (https://github.com/edsomjr/TEP/blob/master/Grafos/slides/floyd-warshall/floyd-warshall.pdf)
 */
vector<vector<int>> floyd_warshall(vector<ii> adj[], int N) {
    //
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, oo));

    // A distância (horas gastas) entre um nó e ele mesmo é 0
    for (int x = 1; x <= N; x++)
        dist[x][x] = 0;

    // Atualiza a distância dos nós com aresta direta
    for (int x = 1; x <= N; x++)
        for (auto [y, h] : adj[x])
            dist[x][y] = h;

    // Calcula a menor distância entre todos os pares de vértices e salva em dist
    for (int k = 1; k <= N; k++)
        for (int x = 1; x <= N; x++)
            for (int y = 1; y <= N; y++)
                if (dist[x][k] < oo and dist[k][y] < oo)
                    dist[x][y] = min(dist[x][y], dist[x][k] + dist[k][y]);

    return dist;
}

int main() {
    int N;  // Número de cidades (Nós)
    int E;  // Número de acordos de envios de mensagens (Arestas)

    // Loop enquanto N e E != 0
    while (cin >> N >> E && (N || E)) {
        vector<ii> graph[N + 1];  // Grafo de agências e acordos de envio de cartas
        int X, Y, H;

        while (E--) {
            cin >> X >> Y >> H;

            // Checa se as agências estão na mesma cidade (Existe caminho de X -> Y e Y -> X)
            vector<ii>::iterator it = find_if(graph[Y].begin(), graph[Y].end(),
                                              [&X](const ii p) { return p.first == X; });
            if (it != graph[Y].end()) {
                // Se as agências estão na mesma cidade, o tempo gasto (custo) para envio da carta é 0
                (*it).second = 0;
                graph[X].push_back(make_pair(Y, 0));
            } else {
                graph[X].push_back(make_pair(Y, H));
            }
        }

        vector<vector<int>> dist = floyd_warshall(graph, N);

        int K;     // Número de consultas
        int O, D;  // Origem e destino das consultas

        cin >> K;
        while (K--) {
            cin >> O >> D;

            if (dist[O][D] != oo)
                cout << dist[O][D] << endl;
            else
                cout << "Nao e possivel entregar a carta\n";
        }

        cout << endl;
    }

    return 0;
}