// url: https://codeforces.com/gym/382080/problem/A
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int n, int start, vector<vector<int> > AdjList) {
  queue<int> Q;
  vector<int> distance(n, -1);

  Q.push(start);
  distance[start] = 0;

  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();

    for (int i = 0; i<AdjList[u].size(); i++) {
      int v = AdjList[u][i];
      if (distance[v] == -1) {
        distance[v] = distance[u] + 1;
        Q.push(v);
      }
    }
  }
  return distance;
}

int main() {
  int n;

  cin>>n;
  vector<vector<int> > AdjList(n, vector<int>());
  for (int i = 0; i<n; i++) {
    int node, k;
    cin >> node >> k;

    for (int j = 0; j<k; j++) {
      int v;
      cin >> v;
      AdjList[node-1].push_back(v-1);
    }
  }

  vector<int> answer = bfs(n, 0, AdjList);

  for (int i = 0; i<n;i++) {
    cout << i+1 << " " << answer[i] << endl;
  }


}