// Problema de la llamita
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int X[] = {0, 1, 0, -1};
int Y[] = {-1, 0, 1, 0};

int main() {

  int filas, columnas;

  cin>>filas>>columnas;

  vector<vector<char> > mapa(filas, vector<char>(columnas, 'X'));

  int filaLlama = -1, colLlama = -1;
  for (int i = 0; i<filas; i++) {
    for (int j = 0; j<columnas; j++) {
      cin >> mapa[i][j];
      if (mapa[i][j] == 'L') {
        filaLlama = i;
        colLlama = j;
      }
    }
  }

  for (int i = 0; i<filas; i++) {
    for (int j = 0; j<columnas; j++) {
      cout << mapa[i][j] << " ";
    }
    cout << endl;
  }

  // BFS
  queue<pair<int,int> > Q;
  vector<vector<int> > distances(filas, vector<int>(columnas, -1));

  distances[filaLlama][colLlama] = 0;
  Q.push(make_pair(filaLlama, colLlama));

  while(!Q.empty()) {
    pair<int,int> u = Q.front();
    Q.pop();

    for (int i = 0; i<4; i++) {
      int nFila = u.first + X[i];
      int nCol = u.second + Y[i];

      if (0 <= nFila && nFila < filas && 0 <= nCol && nCol < columnas) { // Estoy dentro de mi mapa valido
        if (mapa[nFila][nCol] != 'X' && distances[nFila][nCol] == -1) { //Pared no hago nada
          distances[nFila][nCol] = distances[u.first][u.second] + 1;
          Q.push(make_pair(nFila, nCol));
        }
      }
    }
  }

  int answer = 10000;

  for (int i = 0; i<filas; i++) {
    for (int j = 0; j<columnas; j++) {
      if (mapa[i][j] == 'A') {
        answer = min(answer, distances[i][j]);
      }
    }
  }

  cout << "Me demore " << answer << " segundos para econtrar mi alfalfa!!" << endl;


  return 0;
}