#include<iostream>
using namespace std;
void output(int** mas, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << mas[i][j] << "\t";
		} cout << endl;
	}

}
void mas_in(int** mas, int x, int y) {
	cout << "заполните матрицу\n";
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> mas[i][j];
		}
	}
	output(mas, x, y);
	cout << endl;
}
void F(int** mas, int x, int y, int** mas1, int x1, int y1, int** mas2) {
	for (int i1 = 0; i1 < x; i1++) {
		for (int j1 = 0; j1 < y; j1++) {
			for (int i2 = 0; i2 < x1; i2++) {
				for (int j2 = 0; j2 < y1; j2++) {
					if (j1 == i2) {
						mas2[i1][j2] += mas[i1][j1] * mas1[i2][j2];
					}
				}
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n, m, c, d, n1, d1;
	cout << " Введите кол-во строк и столбцов матрицы: \n";
	cin >> n >> m;
	cout << " Введите кол-во строк и столбцов второй матрицы: \n";
	cin >> c >> d;
	n1 = n;
	d1 = d;
	if (m != c) {
		cout << "матрицы нельзя перемножить";
		return(0);
	}
	int** mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
	}
	mas_in(mas, n, m);
	int** mas1 = new int* [c];
	for (int i = 0; i < c; i++) {
		mas1[i] = new int[d];
	}
	mas_in(mas1, c, d);
	int** mas2 = new int* [n1];
	for (int i = 0; i < n1; i++) {
		mas2[i] = new int[d1];
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < d1; j++) {
			mas2[i][j] = 0;
		}
	}
	F(mas, n, m, mas1, c, d, mas2);
	cout << "произведение:\n";
	output(mas2, n, d);
	for (int i = 0; i < n; ++i)
		delete[] mas[i];
	delete[] mas;
	for (int i = 0; i < c; ++i)
		delete[] mas1[i];
	delete[] mas1;
	for (int i = 0; i < n1; ++i)
		delete[] mas2[i];
	delete[] mas2;
}


