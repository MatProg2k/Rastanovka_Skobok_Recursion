#pragma once
#include <iostream>
#include <vector>

class MatricaMul
{
public:
	MatricaMul(int count, std::vector<int> size);
	int GenerationRecursion(int start, int end);
	void ShowResultMatrica();
	int GetIndex(int i, int j);

private:
	int **resultMatrica;
	std::vector<int> resultForDinamic;
	std::vector<int> size;
	int count = 0;	
};