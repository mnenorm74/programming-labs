void CheckData(int firstLinesCount, int firstColumnsCount, int secondLinesCount, int secondColumnsCount);
int** CreateMatrix(int linesCount, int columnsCount);
void FillMatrix(int linesCount, int columnsCount, int **matrix);
int** CalculateResult(int** firstMatrix, int** secondMatrix, int firstLinesCount, int firstColumnsCount, int secondColumnsCount);
void PrintMatrix(int linesCount, int columnsCount, int** matrix);
void PrintResults(int firstLinesCount, int firstColumnsCount, int** firstMatrix,
	int secondLinesCount, int secondColumnsCount, int** secondMatrix, int** resultMatrix);
void DeleteMatrix(int linesCount, int** matrix);
void task3();