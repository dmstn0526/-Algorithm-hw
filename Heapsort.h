#include<stdio.h>
#include<stdlib.h> //srand, rand�� ����ϱ� ���� �������
#include<time.h> //time() ����� ���� �������

#define MAX 100000 //�������� ���� max
#define SIZE 1000 //�迭�� ũ��, ��� �������� �������->100, 500, 1000, 5000, 10000��
#define RUN 1 //���� Ƚ��

void heapify(int arr[], int h, int n) {
	int left = h * 2 + 1;
	int right = h* 2 + 2;
	int k = h;
	int temp;

	if (left<n && arr[left]>arr[k])
		k = left;
	if (right<n && arr[right]>arr[k])
		k = right;
	if (k != h) {
		temp = arr[h];
		arr[h] = arr[k];
		arr[k] = temp;
		heapify(arr, k, n);
	}
}

void buildHeap(int arr[], int n) {
	int i, j;
	for (i = n / 2 - 1; i > -0; i--) {
		heapify(arr, i, n);
	}
}

void Heapsort(int arr[], int n) {
	int tsize;
	int temp;
	buildHeap(arr, n);
	for (tsize = n - 1; tsize >= 0; tsize--) {
		temp = arr[0];
		arr[0] = arr[tsize];
		arr[tsize] = temp;
		heapify(arr, 0, tsize);
	}
}

int main(void) {
	int i;
	int arr[SIZE] = { 0 };

	int TESTCASE = 1000;
	int TIME = 0;
	/* Timer on */
	clock_t start = clock();
	/* ���� �ڵ� */
	for (int tc = 1; tc <= TESTCASE; tc++) {
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

	Heapsort(arr, SIZE);

	printf("���� �� �迭 : ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("TIME : %d ms\n", TIME); /* ms ������ ��� */
	printf("\n");

	return 0;

}