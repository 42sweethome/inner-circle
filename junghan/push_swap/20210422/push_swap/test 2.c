#include <stdio.h>

int count = 1;

void    quick_sort(int arr[], int start, int end)
{
    int pivot; //기준이 되는 값
    int i; //left부터 인덱스를 세어줄 변수 (start)
    int j; //right부터 인덱스를 세어줄 변수 (end)
	int k;
    int tmp; //swap을 위한 변수

    if (start >= end) //만약 1일경우 종료 base_condition; 
        return;       //상위목차의 merge와 같음

    pivot = start;    //기준이 되는 피벗값을 start로 정함
    i = start + 1;    //start의 다음 인덱스부터 피벗보다 큰 값을 탐색
    j = end;          //end의 이전 인덱스부터 피벗보다 작은 값을탐색

    while (i <= j) //엇갈릴 때까지 반복
    {
        while(arr[i] <= arr[pivot]) //만약 현재보다 큰값
            i++;
        while (arr[j] >= arr[pivot] && j > start) //만약 작은값이 없다면
            j--;                 //pivot의 위치에서 멈춰야함 
        if (i >= j)
        {
            tmp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = tmp;
        }
        else
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    k = 0;
    while (k < 10)
    {
        printf("%d\n", arr[k]);
        k++;
    }
	printf("1------------\n");

    /* 재귀함수로 탐색해줌 */
    quick_sort(arr, start, j - 1); // 피벗기준 왼쪽탐색
    quick_sort(arr, j + 1, end); //피벗기준 오른쪽탐색
}


int main()
{
    int i;
    int number = 10;
    int arr[10] = {7, 30, 20, 21, 1, 2, 3, 5, 9 ,4 };

    quick_sort(arr, 0 , number - 1);

	printf("-----------\n");
    i = 0;
    while (i < 10)
    {
        printf("%d\n", arr[i]);
        i++;
    }
    
    return (0);
}
