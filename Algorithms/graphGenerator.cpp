/**
 * @author Codex47
 * All the nodes are in range of (0, min(n, MAX_NODES))
 * Run this to generate graphs in the graph.txt file (g++ graphGenerator.cpp -o run)
 * Pass integer arguments: <number_of_testcases> [check_connected_flag (0/1)]
 * Example: ./run 5 1
 * Check the format of graphs in print function of this file.
 * First line is no. of testcases in the output
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_NODES 10
#define MAX_EDGES 10

void print(ofstream &fout, int n, int m, vector<pair<int, int>> edges) {
    fout << n << " " << m << "\n";
    for (auto [u, v] : edges)
        fout << u << " " << v << "\n";
}

/**
 * @brief Checks whether an undirected graph with n nodes (0 … n-1) given by its edge list is connected.
 */
bool isConnected(int n, const vector<pair<int,int>>& edges) {
    if (n == 0)
        return true;

    vector<vector<int>> g(n);
    for (auto [u, v] : edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> visited(n, false);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        for (int &v : g[u])
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
    }
    return count == n;
}

/**
 * @brief Generates a single random graph and writes it to the output stream.
 *
 * If @p checkConnected is true, the function will keep regenerating the graph
 * until a connected one is obtained (the built‑in spanning‑tree guarantee means
 * this never actually loops, but the check is performed for safety).
 */
void generateRandomGraph(mt19937 &gen, ofstream &fout, bool checkConnected) {
    int n, m;
    vector<pair<int,int>> edges;

    do {
        // random number of nodes (1 .. MAX_NODES)
        uniform_int_distribution<int> node_dist(1, MAX_NODES);
        n = node_dist(gen);

        // random number of edges (between min for connectivity and MAX_EDGES)
        int maxEdges = n * (n - 1) / 2;
        int minEdges = (n == 1) ? 0 : n - 1;
        uniform_int_distribution<int> edge_dist(minEdges, min(maxEdges, MAX_EDGES));
        m = edge_dist(gen);

        // build a random spanning tree (guarantees connectivity)
        vector<int> connected = {0};
        vector<int> remaining;
        for (int i = 1; i < n; ++i)
            remaining.push_back(i);
        shuffle(remaining.begin(), remaining.end(), gen);

        set<pair<int,int>> edgeSet;
        edges.clear();

        uniform_int_distribution<int> connect_dist(0, 0);
        for (int node : remaining) {
            connect_dist.param(uniform_int_distribution<int>::param_type(0, connected.size()-1));
            int pick = connected[connect_dist(gen)];
            int u = min(pick, node);
            int v = max(pick, node);
            edgeSet.insert({u, v});
            edges.emplace_back(u, v);
            connected.push_back(node);
        }

        // add extra random edges until we reach m
        vector<pair<int,int>> candidates;
        for (int u = 0; u < n; ++u)
            for (int v = u + 1; v < n; ++v)
                if (edgeSet.find({u, v}) == edgeSet.end())
                    candidates.emplace_back(u, v);

        shuffle(candidates.begin(), candidates.end(), gen);
        int extras = m - static_cast<int>(edges.size());
        for (int i = 0; i < extras && i < static_cast<int>(candidates.size()); ++i)
            edges.push_back(candidates[i]);

        m = edges.size();   // adjust m in case we ran out of candidates
    } while (checkConnected && !isConnected(n, edges));

    print(fout, n, m, edges);
}

int main(int argc, char* argv[]) {
    // Expect 1 or 2 arguments: <number_of_testcases> [check_connected_flag]
    if (argc > 3) {
        cerr << "Usage: " << argv[0] << " <number_of_testcases> [check_connected_flag (0/1)]\n";
        return 1;
    }

    int testcases = 1;
    if (argc >= 2) {
        try {
            testcases = stoi(argv[1]);
        } catch (...) {
            cerr << "Invalid number of testcases. Generating 1 testcase.\n";
            testcases = 1;
        }
    }
    if (testcases <= 0) {
        cerr << "Number of testcases must be positive. Generating 1 testcase.\n";
        testcases = 1;
    }

    int checkFlag = 0;                     // default: do not enforce connectivity check
    if (argc >= 3) {
        try {
            checkFlag = stoi(argv[2]);
        } catch (...) {
            cerr << "Invalid check flag. Defaulting to 0 (no check).\n";
            checkFlag = 0;
        }
    }

    // Open output file
    ofstream fout("graph.txt");
    if (!fout) {
        cerr << "Error opening graph.txt\n";
        return 1;
    }

    // Print Number of testcases
    fout << testcases << "\n";

    // Random engine
    random_device rd;
    mt19937 gen(rd());

    // Generate the requested number of graphs
    while (testcases--) {
        generateRandomGraph(gen, fout, checkFlag == 1);
    }

    fout.close();
    return 0;
}