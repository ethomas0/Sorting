#include <vector>
using namespace std;

void swap(int *value1, int *value2)
{
	int temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}


void SelectionSort(vector<int> &array, const int &start, const int &stop)
{
	for (int i = start; i <= stop; i++)
	{

		int minIndex = i;
		for (int j = i + 1; j <= stop; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}

		}

		::swap(&array[minIndex], &array[i]);
	}
}


void BubbleSort(vector<int> &array, const int &start, const int &stop)
{

	for (int i = 0; i <= stop; i++)
	{
		for (int j = start; j <= stop - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				::swap(&array[j], &array[j + 1]);
			}
		}
	}

}

void merge(vector <int> &arr, const int &from, const int &mid, const int &to)
{
	int i, j, k;
	int leftHalfIndex = mid - from + 1;
	int rightHalfIndex = to - mid;

	
	vector<int> leftHalf(leftHalfIndex), rightHalf(rightHalfIndex);


	for (i = 0; i < leftHalfIndex; i++)
	{
		leftHalf[i] = arr[from + i];
	}

	for (j = 0; j < rightHalfIndex; j++)
	{
		rightHalf[j] = arr[mid + 1 + j];
	}


	i = 0;
	j = 0;
	k = from;

	while (i < leftHalfIndex && j < rightHalfIndex)
	{
		if (leftHalf[i] <= rightHalf[j])
		{
			arr[k++] = leftHalf[i++];
		}
		else
		{
			arr[k++] = rightHalf[j++];
		}
	}

	while (i < leftHalfIndex)
	{
		arr[k++] = leftHalf[i++];
	}

	while (j < rightHalfIndex)
	{
		arr[k++] = rightHalf[j++];
	}


}
void MergeSort(vector <int> &array, const int &start, const int &stop)
{
	if (start < stop)
	{

		int midValue = start + (stop - start) / 2;

		MergeSort(array, start, midValue);
		MergeSort(array, midValue + 1, stop);

		merge(array, start, midValue, stop);
	}
}

int partition(vector <int> &array, const int &low, const int &high)
{
	int pivotPoint = array[high];
	int minIndex = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivotPoint)
		{
			minIndex++;
			::swap(&array[minIndex], &array[j]);
		}
	}

	swap(&array[minIndex + 1], &array[high]);

	return (minIndex + 1);
}

void QuickSort(vector <int> &array, const int &start, const int &stop)
{
	if (start < stop)
	{
		int partIndex = partition(array, start, stop);

		QuickSort(array, start, partIndex - 1);
		QuickSort(array, partIndex + 1, stop);
	}
}

void ShellSort(vector <int> &array, const int &start, const int &stop)
{
	int size = stop - start;
	int j;

	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i <= size; i += 1)
		{
			int temp = array[i + start];


			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j + start] = array[j + start - gap];
			}

			array[j + start] = temp;
		}
	}
}

void InsertionSort(vector <int> &array, const int &start, const int &stop)
{
	int i, j, tempValue;
	for (i = start; i <= stop; i++)
	{
		tempValue = array[i];
		j = i - 1;

		while (j >= start && array[j] > tempValue)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = tempValue;
	}
}

int min(int x, int y)
{
	return (x < y) ? x : y;
}



void IterativeMergeSort(vector<int> &array, const int &start, const int &stop)
{
	int j = 1;
	int index;
	int size = stop - start;

	for (j; j <= size; j *= 2)
	{
		for (index = start; index < stop; index += 2 * j)
		{
			if ((index + j - 1) < stop)
			{
				if (index + 2 * j - 1 < stop)
				{
					merge(array, index, (index + j - 1), index + 2 * j - 1);
				}
				else
				{
					merge(array, index, (index + j - 1), stop);
				}

			}
		}
	}
}