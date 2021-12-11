#include<iostream>
using namespace std;
void output(int** mas, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << mas[i][j] << "\t";
		} cout << endl;
	}

}
void mas_random(int** mas, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			mas[i][j] = rand() % 100;
		}
	}
	output(mas, x, y);
	cout << endl;
}
void min(int** mas, int x, int y, int* a, int* b) {
	int min = mas[0][0];
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (mas[i][j] < min) {
				min = mas[i][j];
				*a = i;
				*b = j;
			}
		}
	}
	cout << "минимальный элемент: " << min << endl;
}
void min_delete(int** mas, int n, int m, int** mas1, int n1, int m1, int a, int b) {
	int a1 = 0, b1 = 0;
	for (int i = 0; i < n; i++) {
		if (i == a) {
			continue;
		}
		for (int j = 0; j < m; j++) {
			if (j == b) {
				continue;
			}
			mas1[a1][b1] = mas[i][j];
			b1++;
		}
		b1 = 0;
		a1++;

	}
}
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n, m, c, d;
	cout << " Введите кол-во строк и столбцов матрицы: \n";
	cin >> n >> m;
	c = n - 1; d = m - 1;
	int** mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
	}
	int** mas1 = new int* [c];
	for (int i = 0; i < c; i++) {
		mas1[i] = new int[d];
	}
	mas_random(mas, n, m);
	int i = 0, j = 0;
	min(mas, n, m, &i, &j);
	min_delete(mas, n, m, mas1, c, d, i, j);
	for (int i = 0; i < n; ++i)
		delete[] mas[i];
	delete[] mas;
	mas = mas1;
	mas1 = NULL;
	output(mas, c, d);
	for (int i = 0; i < c; ++i)
		delete[] mas[i];
	delete[] mas;
}
