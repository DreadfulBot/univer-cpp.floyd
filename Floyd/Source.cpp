#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

const double infty = INT_MAX;

typedef vector<vector<double>> AdjM;

void readGraph (char* fileName, AdjM &A) {
	int n, a, b;
	double w;
	ifstream fs(fileName);
	fs >> n;
	A = AdjM(n, vector<double>(n, infty));
	while (!fs.eof()){
		fs >> a >> b >> w;
		A[a][b] = w;
		cout << a << " " << b << " " << w << endl;
	}
}

void floyd (AdjM &A, AdjM &res) {
	int n = A.size();
	AdjM C = A, B = A;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (C[i][k] == infty || C[k][j] == infty) {
					B[i][j] = C[i][j];
				} else {
					B[i][j] = min(C[i][j], C[i][k] + C[k][j]);
				}
			}
		}
		swap(B, C);
	}
	swap(C, res);  
}


int main (void) {
	AdjM A;
	readGraph(
	return 0;
}