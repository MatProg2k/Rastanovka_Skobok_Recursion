#include "MatricaMul.h"

MatricaMul::MatricaMul(int count, std::vector<int> size)
{
	this->count = count;
	this->size = size;

	this->resultMatrica = new int*[this->count];

	for (int i = 0; i < this->count; i++)
	{
		this->resultMatrica[i] = new int[this->count];
		for (int j = 0; j < this->count; j++)
		{
			this->resultMatrica[i][j] = 0;
		}
	}
}

int MatricaMul::GenerationRecursion(int start, int end)
{
	int minMult = INT32_MAX;
	int resultTemp = INT32_MAX;

	if ((end - start )>1)
	{
		for (int k = start; k < end; k++)
		{
			minMult = this->GenerationRecursion(start, k) +
				this->GenerationRecursion(k + 1, end) +
				this->size[start - 1] * this->size[k] * this->size[end];

			if (minMult < resultTemp)
			{
				this->resultMatrica[start - 1][end - 1] = k;
				resultTemp = minMult;
			}
		}
	}
	else if ((end-start)==1)
	{
		for (int k = start; k < end; k++)
		{
			minMult = this->size[start - 1] * this->size[start] * this->size[start + 1];
			
				this->resultMatrica[start - 1][end - 1] = k;
				resultTemp = minMult;
			
		}
	}
	else
	{
		return 0;
	}

	return resultTemp;
}

void MatricaMul::ShowResultMatrica()
{
	std::cout << "Результирующая матрица:" << std::endl;
	for (int i = 0; i < this->count; i++)
	{
		for (int j = 0; j < this->count; j++)
		{
			std::cout << this->resultMatrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int MatricaMul::GetIndex(int i, int j)
{
	return (i - 1) * this->count + (j - 1);
}


