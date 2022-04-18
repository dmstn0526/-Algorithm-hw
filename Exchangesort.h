#include<stdio.h>
#include<stdlib.h> //srand, rand�� ����ϱ� ���� �������
#include<time.h> //time() ����� ���� �������

#define MAX 100000 //�������� ���� max
#define SIZE 10000 //�迭�� ũ��, ��� �������� �������->100, 500, 1000, 5000, 10000��
#define RUN 1 //���� Ƚ��

void Exchangesort(int arr[], int n) {
	int i,k;
	int temp;

	for (i = 0; i < n; i++) {
		for (k = i + 1; k < n; k++) {
			if (arr[i] > arr[k]) {
				temp = arr[i];
				arr[i] = arr[k];
				arr[k] = temp;
			}
		}
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

	Exchangesort(arr, SIZE);

	printf("���� �� �迭 : ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("TIME : %d ms\n", TIME); /* ms ������ ��� */
	printf("\n");

	return 0;

}
