// url: https://codeforces.com/gym/382080/problem/B
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9; 

vector<int> dijkstra(int n, int source, vector<vector<pair<int,int> > > AdjList) {
  vector<int> dist(n, INF);
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; pq.push(make_pair(0, source));
  dist[source] = 0;

  while (!pq.empty()) {
    pair<int,int> node = pq.top(); pq.pop();

    int d = node.first;
    int u = node.second;

    if (d > dist[u]) continue;

    for (int i = 0; i<AdjList[u].size(); i++) {
      pair<int,int> next_node = AdjList[u][i];

      int v = next_node.first;
      int w = next_node.second;

      if (dist[u]+w < dist[v]) {
        dist[v] = dist[u]+w; 
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  return dist;
}


int main() {
  int n, m, source;

  cin >> n >> m >> source;

  vector<vector<pair<int,int> > > AdjList(n, vector<pair<int,int> > ());

  for (int i = 0; i<m; i++) {
    int u, v, weight;

    cin >> u >> v >> weight;
    AdjList[u].push_back(make_pair(v, weight));
  }

  vector<int> answer = dijkstra(n, source, AdjList);

  for (int i = 0; i<n; i++) {
    if (answer[i] == INF)
      cout << "INF" << endl;
    else 
      cout << answer[i] << endl;
  }
}