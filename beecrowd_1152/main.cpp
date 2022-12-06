#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

/*
 * Encontra o custo (MST) da árvore geradora mínima.
 * Função adaptada de Edson Alves (https://github.com/edsomjr/TEP/blob/master/Grafos/slides/prim/prim.pdf)
 */
int prim(vector<ii> adj[], int u, int N) {
    set<int> C;
    C.insert(u);

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for (auto [v, w] : adj[u])
        pq.push(ii(w, v));

    int cost = 0;

    while ((int)C.size() < N) {
        int v, w;

        do {
            w = pq.top().first, v = pq.top().second;
            pq.pop();
        } while (C.count(v));

        cost += w;
        C.insert(v);

        for (auto [s, p] : adj[v])
            pq.push(ii(p, s));
    }

    return cost;
}

int main() {
    int m;  // Número de junções de Byteland (Nós)
    int n;  // Múmero de estradas em Byteland (Arestas)

    // Loop até n = m = 0
    while (cin >> m >> n, m != 0 and n != 0) {
        vector<ii> graph[m];
        int total_cost = 0;

        // Salva as arestas do grafo na lista de adjacências
        while (n--) {
            int x, y, m;  // Indica uma estrada de x para y, com m metros
            cin >> x >> y >> m;
            total_cost += m;  // Calcula o custo que o governo gasta atualmente

            // Grafo bidirecional
            graph[x].push_back(ii(y, m));
            graph[y].push_back(ii(x, m));
        }

        // Calcula o menor custo para que exista caminho iluminado entre qualquer vértice
        int cost = prim(graph, 0, m);

        // Imprime o valor que o governo vai economizar
        cout << total_cost - cost << endl;
    }

    return 0;
}