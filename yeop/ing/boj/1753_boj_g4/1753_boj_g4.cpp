#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> cost;

void dijkstra(int point) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, point}); 

    while (!pq.empty()) {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_cost > cost[current_node]) {
            continue;
        }
        // 더 비싸지 않으면 ~ 
        for (auto& edge : graph[current_node]) { // 그거랑 연결된 요소들 찾아서
            int next_node = edge.first;
            int next_cost = edge.second;

            if (current_cost + next_cost < cost[next_node]) {
                cost[next_node] = cost[current_node] + next_cost;
                pq.push({cost[next_node], next_node});
            }
        }
    }
}

int main() {
    int v, e, stp;
    cin >> v >> e >> stp;
    graph.resize(v);
    cost.resize(v);
    
    for (int i = 0; i < v; i++) {
        cost[i] = 1e9;
    }
    cost[stp - 1] = 0;

    int st, ed, co;
    for (int i = 0; i < e; i++) {
        cin >> st >> ed >> co;
        st--;
        ed--;
        graph[st].push_back({ed, co}); 
    }

    dijkstra(stp - 1);

    for (int i = 0; i < v; i++) {
        if (cost[i] == 1e9) {
            cout << "INF\n";
        } else {
            cout << cost[i] << "\n"; 
        }
    }
    return 0;
}
