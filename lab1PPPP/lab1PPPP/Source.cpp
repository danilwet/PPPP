#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Разделение матрицы на подматрицы
int** division(int** matrix, int size, int path)


{
	switch (path) {
	case (1):
	{
		int** dividedMatrix = new int* [size / 2];
		for (int i = 0; i < size / 2; i++)
		{
			dividedMatrix[i] = new int[size / 2];
			for (int j = 0; j < size / 2; j++)
				dividedMatrix[i][j] = matrix[i][j];
		}
		return dividedMatrix;
	}
	case (2):
	{
		int** dividedMatrix = new int* [size / 2];
		for (int i = 0; i < size / 2; i++)
		{
			dividedMatrix[i] = new int[size / 2];
			for (int j = 0; j < size / 2; j++)
				dividedMatrix[i][j] = matrix[i][j + size / 2];
		}
		return dividedMatrix;
	}
	case (3):
	{
		int** dividedMatrix = new int* [size / 2];
		for (int i = 0; i < size / 2; i++)
		{
			dividedMatrix[i] = new int[size / 2];
			for (int j = 0; j < size / 2; j++)
				dividedMatrix[i][j] = matrix[i + size / 2][j];
		}
		return dividedMatrix;
	}
	case (4):
	{
		int** dividedMatrix = new int* [size / 2];
		for (int i = 0; i < size / 2; i++)
		{
			dividedMatrix[i] = new int[size / 2];
			for (int j = 0; j < size / 2; j++)
				dividedMatrix[i][j] = matrix[i + size / 2][j + size / 2];
		}
		return dividedMatrix;
	}
	}
}
	
//Создание пустой матрицы
int** createMatrix(int sizeA, int sizeB)
{
	int** Intermediatematrix = new int* [sizeA ];
	for (int i = 0; i < sizeA ; i++)
	{
		Intermediatematrix[i] = new int[sizeB ];
	}
	return Intermediatematrix;
}

//Приведение матриц к нужному размеру
int** reductionMatrix(int redusedSize, int sizeA, int sizeB, int** Matrix)
{
	int** redusedMatrix = new int* [redusedSize];
	for (int i = 0; i < redusedSize; i++)
	{
		redusedMatrix[i] = new int[redusedSize];
		for (int j = 0; j < redusedSize; j++)
			redusedMatrix[i][j] = 0;
	}

	for (int i = 0; i < sizeA; i++)
	{
		for (int j = 0; j < sizeB; j++)
			redusedMatrix[i][j] = Matrix[i][j];
	}
	return redusedMatrix;
}
//Заполнение матриц случайными значениями
int** fillingInRandomValues(int sizeA, int sizeB, int** initialMatrix)
{
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			initialMatrix[i][j] = rand() % 10;
	return initialMatrix;
}
//Заполнение матриц вручную
int** fillingMatrixManually(int sizeA, int sizeB, int** initialMatrix)
{
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			cin >> initialMatrix[i][j];
	return initialMatrix;
}
//Вывод матрицы на экран
void displayingMatrix(int sizeA, int sizeB, int** Matrix)
{
	for (int i = 0; i < sizeA; i++)
	{
		for (int j = 0; j < sizeB; j++)
			cout << Matrix[i][j] << " ";
		cout << endl;
	}
}

void main()
{
	srand(time(NULL));
	int sizeAMatrix1, sizeBMatrix1, sizeAMatrix2, sizeBMatrix2, fillType, redusedSize = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Введите размеры первой матрицы\n";
		cin >> sizeAMatrix1 >> sizeBMatrix1;
	} while (sizeAMatrix1 <= 0 || sizeBMatrix1 <= 0);
	do
	{
		cout << "Введите размеры второй матрицы\n";
		cin >> sizeAMatrix2 >> sizeBMatrix2;
	} while (sizeAMatrix2 <= 0 || sizeBMatrix2 <= 0);

	int** initialMatrix1 = createMatrix(sizeAMatrix1, sizeBMatrix1);
		
	int** initialMatrix2 = createMatrix(sizeAMatrix2, sizeBMatrix2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> fillType;
	} while (fillType < 1 || fillType > 2);
	switch (fillType)
	{
	case 1:
		fillingMatrixManually(sizeAMatrix1, sizeBMatrix1, initialMatrix1);
		fillingMatrixManually(sizeAMatrix2, sizeBMatrix2, initialMatrix2);

		cout << "\nМатрица 1\n\n";
		displayingMatrix(sizeAMatrix1, sizeBMatrix1, initialMatrix1);
		cout << "\nМатрица 2\n\n";
		displayingMatrix(sizeAMatrix2, sizeBMatrix2, initialMatrix2);
		break;
	case 2:
		initialMatrix1 = fillingInRandomValues(sizeAMatrix1, sizeBMatrix1, initialMatrix1);
		initialMatrix2 = fillingInRandomValues(sizeAMatrix2, sizeBMatrix2, initialMatrix2);
		cout << "\nМатрица 1\n\n";
		displayingMatrix(sizeAMatrix1, sizeBMatrix1, initialMatrix1);
		cout << "\nМатрица 2\n\n";
		displayingMatrix(sizeAMatrix2, sizeBMatrix2, initialMatrix2);
		break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (redusedSize < sizeAMatrix1 || redusedSize < sizeAMatrix2 || redusedSize < sizeBMatrix1 || redusedSize < sizeBMatrix2)
		redusedSize *= 2;

	int** reducedMatrix1 = reductionMatrix(redusedSize, sizeAMatrix1, sizeBMatrix1, initialMatrix1);
	int** reducedMatrix2 = reductionMatrix(redusedSize, sizeAMatrix2, sizeBMatrix2, initialMatrix2);
	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	displayingMatrix(redusedSize, redusedSize, reducedMatrix1);
	cout << "\nМатрица 2\n\n";
	displayingMatrix(redusedSize, redusedSize, reducedMatrix2);

	///////////////////////////////////////////////////////////////////////////////
	///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
	///////////////////////////////////////////////////////////////////////////////


	int** submatrix11 = division(reducedMatrix1, redusedSize,1);
	int** submatrix12 = division(reducedMatrix1, redusedSize,2);
	int** submatrix13 = division(reducedMatrix1, redusedSize,3);
	int** submatrix14 = division(reducedMatrix1, redusedSize,4);
	int** submatrix21 = division(reducedMatrix2, redusedSize,1);
	int** submatrix22 = division(reducedMatrix2, redusedSize,2);
	int** submatrix23 = division(reducedMatrix2, redusedSize,3);
	int** submatrix24 = division(reducedMatrix2, redusedSize,4);


	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Создание промежуточных матриц//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** intermediateMatrix1 = createMatrix(redusedSize / 2, redusedSize / 2);
	int** intermediateMatrix2 = createMatrix(redusedSize / 2, redusedSize / 2);
	int** intermediateMatrix3 = createMatrix(redusedSize / 2, redusedSize / 2);
	int** intermediateMatrix4 = createMatrix(redusedSize / 2, redusedSize / 2);
	int** intermediateMatrix5 = createMatrix(redusedSize / 2, redusedSize / 2);
	int** intermediateMatrix6 = createMatrix(redusedSize / 2, redusedSize / 2);
	int** intermediateMatrix7 = createMatrix(redusedSize / 2, redusedSize / 2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Вычисление значений промежуточных матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < redusedSize / 2; i++)
	{
		for (int j = 0; j < redusedSize / 2; j++)
		{
			intermediateMatrix1[i][j] = 0;
			for (int z = 0; z < redusedSize / 2; z++)
			{
				intermediateMatrix1[i][j] += (submatrix11[i][z] + submatrix14[i][z]) * (submatrix21[z][j] + submatrix24[z][j]);
			}

			intermediateMatrix2[i][j] = 0;
			for (int z = 0; z < redusedSize / 2; z++)
			{
				intermediateMatrix2[i][j] += (submatrix13[i][z] + submatrix14[i][z]) * submatrix21[z][j];
			}

			intermediateMatrix3[i][j] = 0;
			for (int z = 0; z < redusedSize / 2; z++)
			{
				intermediateMatrix3[i][j] += submatrix11[i][z] * (submatrix22[z][j] - submatrix24[z][j]);
			}

			intermediateMatrix4[i][j] = 0;
			for (int z = 0; z < redusedSize / 2; z++)
			{
				intermediateMatrix4[i][j] += submatrix14[i][z] * (submatrix23[z][j] - submatrix21[z][j]);
			}

			intermediateMatrix5[i][j] = 0;
			for (int z = 0; z < redusedSize / 2; z++)
			{
				intermediateMatrix5[i][j] += (submatrix11[i][z] + submatrix12[i][z]) * submatrix24[z][j];
			}

			intermediateMatrix6[i][j] = 0;
			for (int z = 0; z < redusedSize / 2; z++)
			{
				intermediateMatrix6[i][j] += (submatrix13[i][z] - submatrix11[i][z]) * (submatrix21[z][j] + submatrix22[z][j]);
			}

			intermediateMatrix7[i][j] = 0;
			for (int z = 0; z < redusedSize / 2; z++)
			{
				intermediateMatrix7[i][j] += (submatrix12[i][z] - submatrix14[i][z]) * (submatrix23[z][j] + submatrix24[z][j]);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Создание вспомогательных матриц/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** auxiliaryMatrix1 = createMatrix(redusedSize/2, redusedSize/2);
	int** auxiliaryMatrix2 = createMatrix(redusedSize/2, redusedSize/2);
	int** auxiliaryMatrix3 = createMatrix(redusedSize/2, redusedSize/2);
	int** auxiliaryMatrix4 = createMatrix(redusedSize/2, redusedSize/2);

	///////////////////////////////////////////////////////////////////////////////
	////////////Подсчет значений вспомогательных матриц из промежуточных///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < redusedSize / 2; i++)
	{
		for (int j = 0; j < redusedSize / 2; j++)
		{
			auxiliaryMatrix1[i][j] = intermediateMatrix1[i][j] + intermediateMatrix4[i][j] - intermediateMatrix5[i][j] + intermediateMatrix7[i][j];
			auxiliaryMatrix2[i][j] = intermediateMatrix3[i][j] + intermediateMatrix5[i][j];
			auxiliaryMatrix3[i][j] = intermediateMatrix2[i][j] + intermediateMatrix4[i][j];
			auxiliaryMatrix4[i][j] = intermediateMatrix1[i][j] - intermediateMatrix2[i][j] + intermediateMatrix3[i][j] + intermediateMatrix6[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** resultMatrix = createMatrix(redusedSize, redusedSize);

	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < redusedSize / 2; i++)
	{
		for (int j = 0; j < redusedSize / 2; j++)
		{
			resultMatrix[i][j] = auxiliaryMatrix1[i][j];
			resultMatrix[i][j + redusedSize / 2] = auxiliaryMatrix2[i][j];
			resultMatrix[i + redusedSize / 2][j] = auxiliaryMatrix3[i][j];
			resultMatrix[i + redusedSize / 2][j + redusedSize / 2] = auxiliaryMatrix4[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////
	int significantElements = 0, firstNullLineA = 100, firstNullLineB = 100;
	for (int i = 0; i < redusedSize; i++)
	{
		significantElements = 0;
		for (int j = 0; j < redusedSize; j++)
		{
			if (resultMatrix[i][j] != 0)
			{
				significantElements++;
				firstNullLineA = 100;
			}
		}
		if (significantElements == 0 && i < firstNullLineA)
		{
			firstNullLineA = i;
		}
	}
	for (int i = 0; i < redusedSize; i++)
	{
		significantElements = 0;
		for (int j = 0; j < redusedSize; j++)
		{
			if (resultMatrix[j][i] != 0)
			{
				significantElements++;
				firstNullLineB = 100;
			}
		}
		if (significantElements == 0 && i < firstNullLineB)
		{
			firstNullLineB = i;
		}
	}

	int** redusedResultMatrix = new int* [firstNullLineA];
	for (int i = 0; i < firstNullLineA; i++)
	{
		redusedResultMatrix[i] = new int[firstNullLineB];
		for (int j = 0; j < firstNullLineB; j++)
			redusedResultMatrix[i][j] = resultMatrix[i][j];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\nРезультирующая матрица\n\n";
	displayingMatrix(firstNullLineA, firstNullLineB, redusedResultMatrix);
	
	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < sizeAMatrix1; i++)
		delete[] initialMatrix1[i];
	for (int i = 0; i < sizeAMatrix2; i++)
		delete[] initialMatrix2[i];
	for (int i = 0; i < redusedSize; i++)
	{
		delete[] reducedMatrix1[i];
		delete[] reducedMatrix2[i];
		delete[] resultMatrix[i];
	}
	for (int i = 0; i < firstNullLineA; i++)
		delete[] redusedResultMatrix[i];
	for (int i = 0; i < redusedSize / 2; i++)
	{
		delete[] submatrix11[i];
		delete[] submatrix12[i];
		delete[] submatrix13[i];
		delete[] submatrix14[i];
		delete[] submatrix21[i];
		delete[] submatrix22[i];
		delete[] submatrix23[i];
		delete[] submatrix24[i];
		delete[] auxiliaryMatrix1[i];
		delete[] auxiliaryMatrix2[i];
		delete[] auxiliaryMatrix3[i];
		delete[] auxiliaryMatrix4[i];
		delete[] intermediateMatrix1[i];
		delete[] intermediateMatrix2[i];
		delete[] intermediateMatrix3[i];
		delete[] intermediateMatrix4[i];
		delete[] intermediateMatrix5[i];
		delete[] intermediateMatrix6[i];
		delete[] intermediateMatrix7[i];
	}
	delete[] initialMatrix1, initialMatrix2, reducedMatrix1, reducedMatrix2, resultMatrix, redusedResultMatrix;
	delete[] submatrix11, submatrix12, submatrix13, submatrix14, submatrix21, submatrix22, submatrix23, submatrix24, auxiliaryMatrix1, auxiliaryMatrix2, auxiliaryMatrix3, auxiliaryMatrix4;
	delete[] intermediateMatrix1, intermediateMatrix2, intermediateMatrix3, intermediateMatrix4, intermediateMatrix5, intermediateMatrix6, intermediateMatrix7;
}