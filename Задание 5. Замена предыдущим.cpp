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
			mas[i][j] = rand() % 200 - 100;
		}
	}
	output(mas, x, y);
	cout << endl;
}
void swap_max(int** mas, int x, int y) {
	int max, min;
	int a, b, a1, b1, a2, b2;
	for (int i = 0; i < x; i++) {
		max = mas[i][0];
		min = mas[i][0];
		a = i; a1 = i;
		b = 0; b1 = 0;
		for (int j = 0; j < y; j++) {
			if (mas[i][j] > max) {
				max = mas[i][j];
				a = i;
				b = j;
			}
			if (mas[i][j] < min) {
				min = mas[i][j];
				a1 = i;
				b1 = j;
			}
		}
		if (i > 0) {
			mas[a1][b1] = mas[a2][b2];
		}
		a2 = a;
		b2 = b;
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n, m;
		cout << " Введите кол-во строк и столбцов таблицы: \n";
	cin >> n >> m;
		int** mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
	}
	mas_random(mas, n,m);
	swap_max(mas, n,m);
	output(mas, n ,m);
	return(0);
	for (int i = 0; i < n; ++i)
		delete[] mas[i];
	delete[] mas;
}