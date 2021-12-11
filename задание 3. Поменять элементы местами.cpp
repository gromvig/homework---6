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
void F(int** mas, int x, int y) {
	cout << "результат:\n";
	for (int i = 0; i < x - 1; i++) {
		for (int j = 0; j < y - i - 1; j++) {
			swap(mas[i][j], mas[x - j - 1][y - i - 1]);

		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n;
	cout << " Введите размерность  матрицы: \n";
	cin >> n;
	int** mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];
	}
	mas_random(mas, n,n);
	F(mas, n,n);
	output(mas, n, n);
	for (int i = 0; i < n; ++i)
		delete[] mas[i];
	delete[] mas;
}