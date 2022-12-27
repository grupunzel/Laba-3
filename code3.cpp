#include <iostream>
#include <Windows.h>
using namespace std;
const int N = 6;

void Snake(int(*A)[N], int *end) {

	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int* p = A[0], i = 0, x = 0, y = 0; p <= end + N - 1; p++, i++, y++) {

		if (i % N == 0 && i != 0) {
			x++;
			y = 0;
			if (x % 2 == 0) {
				p = &A[x][y];
			}
			else {
				p = &A[x][y + N - 1];
			}
		}

		if (x % 2 == 0) {
			destCoord.X = x * 4;
			destCoord.Y = y;
			SetConsoleCursorPosition(hStdout, destCoord);
			*p = 1 + rand() % (N * N);
			cout << *p;
			Sleep(50);
		}

		else {
			destCoord.X = x * 4;
			destCoord.Y = N - y - 1;
			SetConsoleCursorPosition(hStdout, destCoord);
			*(p - y - y) = 1 + rand() % (N * N);
			cout << *(p - y - y);
			Sleep(50);
		}
	}
	cout << "\r";
	for (int i = 0; i < N; i++)
		cout << "\n";

}

void Show(int(*A)[N]) {
	int* end = A[0] + N * N - 1;

	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			destCoord.X = i * 4;
			destCoord.Y = j;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << A[i][j];
		}
}

void SwapA(int(*A)[N]) {
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N; j++) {
			swap(A[i][j], A[i + N / 2][j]);
		}
	}
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			swap(A[i][j], A[i + N / 2][j + N / 2]);
		}
	}
}

void SwapB(int(*A)[N]) {
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < N; j++) {
			if (j < N / 2)
				swap(A[i][j], A[i + N / 2][j + N / 2]);
			else
				swap(A[i][j], A[i + N / 2][j - N / 2]);
		}
}

void SwapC(int(*A)[N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			swap(A[i][j], A[i][j + N / 2]);
		}
	}
}

void SwapD(int(*A)[N]) {
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N; j++) {
			swap(A[i][j], A[i + N / 2][j]);
		}
	}
}

void Sortirovka(int(*A)[N]) {
	int* p = A[0];
	for (int i = 0; i < N * N; i++) {
		for (int j = 0; j < N * N - 1 - i; j++) {
			if (*(p + j) > *(p + j + 1)) {
				swap(*(p + j), *(p + j + 1));
			}
		}
	}
}

void Deistvie(int(*A)[N], int* end) {
	int p;
	string sign;
	cout << "Напишите через пробел любое действие над матрицей из предоставленных: '+'; '-'; '*'; '/', и число\n";
	cin >> sign >> p;
	if (sign == "+") {
		for (int* p2 = A[0]; p2 <= end; p2++) {
			*p2 += p;
		}
	}
	else if (sign == "-") {
		for (int* p2 = A[0]; p2 <= end; p2++) {
			*p2 -= p;
		}
	}
	else if (sign == "*") {
		for (int* p2 = A[0]; p2 <= end; p2++) {
			*p2 *= p;
		}
	}
	else if (sign == "/") {
		for (int* p2 = A[0]; p2 <= end; p2++) {
			*p2 /= p;
		}
	}
}

int main()
{
	setlocale(0, "");
	srand(time(0));
	int A[N][N];
	int* end = A[0] + N * N - 1;
	cout << "Задание 1";
	Sleep(2500);
	system("cls");
	Snake(A, end);
	Sleep(2000);
	system("cls");

	cout << "Задание 2";
	Sleep(2500);

	{
		system("cls");
		cout << "Перестановка блоков а";
		Sleep(2500);
		system("cls");
		Show(A);
		Sleep(1500);
		system("cls");
		SwapA(A);
		Show(A);
		Sleep(1500);

		system("cls");
		cout << "Перестановка блоков b";
		Sleep(2500);
		system("cls");
		Show(A);
		Sleep(1500);
		system("cls");
		SwapB(A);
		Show(A);
		Sleep(1500);

		system("cls");
		cout << "Перестановка блоков c";
		Sleep(2500);
		system("cls");
		Show(A);
		Sleep(1500);
		system("cls");
		SwapC(A);
		Show(A);
		Sleep(1500);

		system("cls");
		cout << "Перестановка блоков d";
		Sleep(2500);
		system("cls");
		Show(A);
		Sleep(1500);
		system("cls");
		SwapD(A);
		Show(A);
		Sleep(1500);
		system("cls");
	}

	cout << "Задание 3";
	Sleep(2500);
	system("cls");
	Show(A);
	Sleep(1500);
	system("cls");
	Sortirovka(A);
	Show(A);
	Sleep(1500);
	system("cls");

	cout << "Задание 4";
	Sleep(1500);
	system("cls");
	Deistvie(A, end);
	system("cls");
	Show(A);
	Sleep(1500);

}

