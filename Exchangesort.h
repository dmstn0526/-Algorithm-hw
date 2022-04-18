#include<stdio.h>
#include<stdlib.h> //srand, rand를 사용하기 위한 헤더파일
#include<time.h> //time() 사용을 위한 헤더파일

#define MAX 100000 //랜덤수의 범위 max
#define SIZE 10000 //배열의 크기, 몇개의 랜덤수가 생기는지->100, 500, 1000, 5000, 10000개
#define RUN 1 //실행 횟수

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
	/* 실행 코드 */
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

	srand(time(NULL)); //매번 새로운 랜덤 난수 생성

	for (i = 0; i < SIZE; i++) //SIZE개의 수만큼 랜덤수 생성
		arr[i] = (static_cast<long long>(rand() % MAX) + 1); //1부터 MAX까지 수 정수 중에서 랜덤하게 뽑아냄

	Exchangesort(arr, SIZE);

	printf("정렬 후 배열 : ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("TIME : %d ms\n", TIME); /* ms 단위로 출력 */
	printf("\n");

	return 0;

}
