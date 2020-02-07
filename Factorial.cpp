#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long int large;
typedef unsigned short us;

large* UtilFactorial(large* arr, us arr_size)
{
	if (arr_size == 1)
		return arr;

	large tmp_size = ceil((double)arr_size / 2),
		* tmp = new large[tmp_size]{ 0 };

	for (us i = 0, j = 0; (i + 1 < arr_size) && (j < tmp_size); i += 2, ++j)
		tmp[j] = arr[i] * arr[i + 1];

	if (arr_size % 2)
		tmp[tmp_size - 1] = arr[arr_size - 1];

	return UtilFactorial(tmp, tmp_size);
}

large Factorial(us n)
{
	if (n == 1)
		return 1;

	us arr_size = n - 1;
	large* arr = new large[arr_size]{ 0 };

	for (us i = 0, j = 2; i < n; arr[i++] = j++);

	return *UtilFactorial(arr, arr_size);
}