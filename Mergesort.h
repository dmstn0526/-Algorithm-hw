#include<stdio.h>
#include<stdlib.h> //srand, rand�� ����ϱ� ���� �������
#include<time.h> //time() ����� ���� �������

#define MAX 100000 //�������� ���� max
#define SIZE 10000 //�迭�� ũ��, ��� �������� �������->100, 500, 1000, 5000, 10000��
#define RUN 1 //���� Ƚ��

int temp[SIZE];
void Merge(int arr[], int left, int mid, int right) { //����
	int l = left;
	int m = mid + 1;
	int k = left;

	while (l <= mid && m <= right) {
		if (arr[l] <= arr[m]) {
			temp[k] = arr[l];
			l++;
		}
		else {
			temp[k] = arr[m];
			m++;
		}
		k++;
	}
	if (l > mid) {
		for (int j = m; j <= right; j++) {
			temp[k] = arr[j];
			k++;
		}
	}
	else {
		for (int j = l; j <= mid; j++) {
			temp[k] = arr[j];
			k++;
		}
	}

	for (int j = left; j <= right; j++) { //���ĵ� �迭 ����
		arr[j] = temp[j];
	}
}

void Mergesort(int arr[], int left, int right) { //����
	int mid = (left + right) / 2;
	if (left < right) {
		Mergesort(arr, left, mid); //���� �迭 ��������
		Mergesort(arr, mid + 1, right); //������ �迭 ��������
		Merge(arr, left, mid, right); //���� �� ���� �Լ��� �Ѿ
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

	Mergesort(arr, 0, SIZE - 1);

	printf("���� �� �迭 : ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("TIME : %d ms\n", TIME); /* ms ������ ��� */
	printf("\n");

	return 0;

}