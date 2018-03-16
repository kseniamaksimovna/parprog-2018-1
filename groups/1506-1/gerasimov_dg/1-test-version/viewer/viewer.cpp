// viewer.cpp �������� �� ���� ��� ����� � ����������� ��� ���������� �� ��������� ���� � ���������

#include <cstdio> 
#include <omp.h> 
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char * argv[])
{
	setlocale(0, "RUS");
	ofstream fout;	// ���� ��� ������ � ���� ������
	fout.open("matr.txt");

	int N;
	double *C;

	FILE *stream;
	char* name = new char[20];
	if (argc > 1) {
		name = argv[1];
		cout << name << endl;
		errno_t err;
		err = freopen_s(&stream, name, "rb", stdin);
		if (err != 0)
		{
			cout << "���� �� ������!" << endl;
			return 0;
		}
	}
	else {
		freopen_s(&stream, "matr.out", "rb", stdin);
	}

	// ��������� ����� ����������
	double time;
	fread(&time, sizeof(time), 1, stdin);
	cout << time << endl;
	// ��������� ������ �������
	fread(&N, sizeof(N), 1, stdin);
	cout << N << endl;
	cout << fixed << setprecision(4);
	C = new double[N * N];
	//��������� �������������� �������
	fread(C, sizeof(*C), N * N, stdin);
	if (N < 11) {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				std::cout << C[i*N + j] << " ";
			}
			std::cout << endl;
		}
	}
	// ���������� ����� ���������� � txt ����
	fout << time << endl;
	// ���������� ������ ������� � txt ����
	fout << N << endl;
	// ���������� ������� � txt ����
	fout << fixed << setprecision(4);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fout << C[i*N + j] << " ";
		}
		fout << endl;
	}
	fout.close();
	return 0;
}