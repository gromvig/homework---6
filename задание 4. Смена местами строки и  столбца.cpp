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
void min(int** mas, int x, int y, int* a, int* b) {
	int min = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (mas[i][j] > 0 && min == 0) {
				min = mas[i][j];
				*a = i;
				*b = j;
			}
			if (mas[i][j] > 0 && mas[i][j] < min) {
				min = mas[i][j];
				*a = i;
				*b = j;
			}
		}
	}
	cout << "минимальный из положительных элементов: " << min << endl;
}
void min_swap(int** mas, int x, int y, int a, int  b) {
	int j = 0;
	for (int i = 0; i < x; i++) {
		if (i == a) {
			continue;
		}
		if (j == b) {
			j++;
		}
		swap(mas[a][j], mas[i][b]);
		j++;
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n;
	cout << " Введите размерность  таблицы: \n";
	cin >> n;
	int** mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];
	}
	int a = -1;
	int b = -1;
	mas_random(mas, n, n);
	min(mas, n, n, &a, &b);
	if (a >= 0 || b >= 0) {
		min_swap(mas, n, n, a, b);
	}
	output(mas, n, n);
	for (int i = 0; i < n; ++i)
		delete[] mas[i];
	delete[] mas;
}