#include<stdio.h>
#include<stdlib.h> //srand, rand�� ����ϱ� ���� �������
#include<time.h> //time() ����� ���� �������

#define MAX 100000 //�������� ���� max
#define SIZE 10000 //�迭�� ũ��, ��� �������� �������->100, 500, 1000, 5000, 10000��
#define RUN 1 //���� Ƚ��


void Quicksort(int arr[], int left, int right) {
	int l = left, r = right;
	int temp;
	int pivot = arr[(left + right) / 2]; //�ǹ��� ��ġ�� ������� ����
	while (l <= r) {
		while(arr[l] < pivot) //left���� �����ϸ鼭 pivot�̻��� ���� �˻�
			l++;
		while (arr[r] > pivot) //right���� �����ϸ鼭 pivot���� ���� �˻�
			r--;
		if (l <= r) { //
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++;
			r--;
		}
	}
	if (l < right)
		Quicksort(arr, l, right); //left ��������� �ݺ�
	if (left < r)
		Quicksort(arr, left, r); //right ��������� �ݺ�
}

int main(void) {
	int i;
	int arr[SIZE] = { 0 };

	int TESTCASE = 1000;
	int TIME = 0;
	/* Timer on */
	clock_t start = clock();
	/* ���� �ڵ� */
	for (int tc = 1; tc <= TESTCASE; tc++){
		int a = 1;
		for (int t = 0; t < 100000; t++)
		{
			a += t;
			a %= 100;
		}
	}
	/* Timer off */
	TIME += ((int)clock() - start) / (CLOCKS_PER_SEC / 1000);


	srand(time(NULL)); //�Ź� ���ο� ���� ���� ����

	for (i = 0; i < SIZE; i++) //SIZE���� ����ŭ ������ ����
		arr[i] = (static_cast<long long>(rand() % MAX) + 1); //1���� MAX���� �� ���� �߿��� �����ϰ� �̾Ƴ�

	Quicksort(arr, 0, SIZE - 1);

	printf("���� �� �迭 : ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("TIME : %d ms\n", TIME); /* ms ������ ��� */
	printf("\n");

	return 0;

}