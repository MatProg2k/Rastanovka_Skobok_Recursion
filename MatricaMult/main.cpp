#include <iostream>
#include <time.h>
#include "MatricaMul.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");

	std::vector<int> temp;

	for (int i = 0; i < 7; i++)
	{
		temp.push_back(rand() % 95 + 5);
	}

	MatricaMul matricMul(6, temp);
	clock_t start = clock();
	std::cout << "����������� ���������� ��������� = " << matricMul.GenerationRecursion(1, 6) << std::endl;
	clock_t end = clock();
	matricMul.ShowResultMatrica();
	std::cout << "�������� ���������� ������������ ��������� = " << end - start << std::endl;

	system("pause");
	return 0;
}