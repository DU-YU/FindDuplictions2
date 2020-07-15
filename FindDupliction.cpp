#include <stdio.h>
#include <iostream>

using namespace std;

/*
	函数：bool FindDuplication（）
	参数：
		int *array ：输入一个整形数组
		int length：输入整形数组的长度
		int *duplication：要查找的数组
	返回值：
		true：找到数组
		false：没有找到数组
*/

bool FindDuplication(int *array, int length, int *duplication)
{
	if (array == nullptr || length < 0)
	{
		return false;
	}
	
	for(int i = 0; i < length; i++)
	{
		if (array[i] < 0 || array[i] > length - 1)
		{
			return false;
		}
	}
	for (int i = 0; i < length; i++)
	{

		while (array[i] != i)
		{
			/*
				如果数组下标对应的元素 == 以数组元素为下标对应的元素。则找到重复数字
				否则。交换两个元素的位置继续比较
			*/
			if (array[i] == array[array[i]])
			{
				*duplication = array[i];
				return true;
			}
			//交换 array[i]和array[array[i]]
			int temp = array[i];
			array[i] = array[temp];
			array[temp] = temp;
		}

	}

	return false;
}



//==========================测试代码=================================

void test(const char* testname, int *array, int length, int *duplication, int duplinationlength, bool expected)
{
	if (testname != nullptr)
	{
		printf("%s is begin!\n", testname);
	}

	bool result = FindDuplication(array, length, duplication);

	if (expected == result)
	{
		printf("PASSED!\n");
	}
	else
	{
		printf("FAILED\n");
	}
}

void test1()
{
	int numbers[] = { 2,3,1,0,2,5,3 };
	int duplinations[] = { 2,3 };
	test("test1", numbers, sizeof(numbers) / sizeof(int), duplinations, sizeof(duplinations) / sizeof(int), true);
}

int main()
{
	test1();
}
