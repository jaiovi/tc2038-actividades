#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

bool vecinoValido(int **arr, int x, int y, int m, int n) {
  if (x < m && y < n && arr[x][y] == 1) {
    return true;
  }
  return false;
}

bool resLaberinto(int **arr, int x, int y, int m, int n, int **solArr) {

  if (x == m - 1 && y == n - 1) {
    solArr[x][y] = 1;
    return true;
  }

  if (vecinoValido(arr, x, y, m, n)) {
    solArr[x][y] = 1;
    if (resLaberinto(arr, x + 1, y, m, n, solArr)) {
      return true;
    }
    if (resLaberinto(arr, x, y + 1, m, n, solArr)) {
      return true;
    }
    solArr[x][y] = 0;
    return false;
  }
  return false;
}

int main(int argc, char *argv[]) {

  // read .txt File
  string file = argv[1];
  ifstream input(file);
  string line = "";

  getline(input, line);
  const int m = stoi(line);

  getline(input, line);
  const int n = stoi(line);

  int idxM = 0;
  int idxN = 0;
  const char delim = ' ';

  int **arr = new int *[m];

  for (int i = 0; i < m; i++) {
    arr[i] = new int[n];
  }

  for (std::string line; getline(input, line);) {

    stringstream ss(line);
    string s;
    while (std::getline(ss, s, delim)) {
      arr[idxM][idxN] = stoi(s);
      idxN++;
    }

    idxM++;
    idxN = 0;
  }

  int **solArr = new int *[m];
  for (int i = 0; i < m; i++) {
    solArr[i] = new int[m];
    for (int j = 0; j < n; j++) {
      solArr[i][j] = 0;
    }
  }

  if (resLaberinto(arr, 0, 0, m, n, solArr)) {

    // Write sorted array to .out file
    char *p = argv[1];
    string s(p);
    int pos = s.find(".");
    string outFile = s.substr(0, pos);
    outFile = outFile + ".out";
    ofstream MyFile(outFile);
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n; k++) {
        MyFile << solArr[j][k] << " ";
      }
      if (j != m - 1) {
        MyFile << "\n";
      }
    }
  }

  return 0;
}