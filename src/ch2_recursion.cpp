#include <iostream>

using namespace std;


/*
 * Chapter 2. 재귀
 */
class Solution {
public:

    // 재귀의 기본
    void Recursive(int num) {
        if(num <= 0) { // 종료 조건이 없다면, 무한 루프에 빠진다.
            return;
        }
        printf("Recursive call! %d \n", num);
        Recursive(num-1);
    }

    /**
     * 팩토리얼로 알아보는 재귀 함수
     * n! = n x (n-1) x (n-2) x (n-3) x . . . . x 2 x 1
     */
    int Factorial(int n) {
        if(n == 0) {
            return 1;
        }

        return n * Factorial(n-1);
    }

    /**
     * 피보나치 수열로 알아보는 재귀 함수
     * Dynamic Programming 문제의 가장 기초였던게 기억난다.
     * 
     * 피보나치 수열의 형태
     * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 . . . . => 앞에것 두 개 더해서 현재의 수를 만들어간다.
     *
     * 즉,
     * fibo(n) = fibo(n-1) + fibo(n-2)
     * 이다.
     */
    int Fibo(int n) {
        if(n == 1) {
            return 0;
        } else if(n == 2) {
            return 1;
        }

        return Fibo(n-1) + Fibo(n-2);
    }

    /**
     * 재귀함수로 구현하는 이진 탐색 알고리즘
     * 
     */
    int BSearchRecur(int ar[], int left, int right, int target) {
        int mid;
        if(left > right) { // 왼쪽과 오른쪽이 엇갈리면 실패.
            return -1;
        }
        mid = (left + right) / 2;

        if(ar[mid] == target) { // mid와 target이 같다면
            return mid; // 그게 바로 답
        } else if(target < ar[mid]) { // target이 mid보다 작다면,
            return BSearchRecur(ar, left, mid-1, target); // 왼쪽에서 다시 탐색 시작.
        } else { // target이 mid보다 크다면,
            return BSearchRecur(ar, mid+1, right, target); // 오른쪽에서 다시 탐색 시작.
        }
    }

    int dummy() {
        return 123;
    }
};


// Driver code
int main() {
    Solution sol;
    // cout << "ans = " << sol.dummy();
    
    // sol.Recursive(3);
    
    // printf("1! = %d \n", sol.Factorial(1));
    // printf("2! = %d \n", sol.Factorial(2));
    // printf("3! = %d \n", sol.Factorial(3));
    // printf("4! = %d \n", sol.Factorial(4));
    // printf("9! = %d \n", sol.Factorial(9));
    
    // int i = 1;
    // for(;i < 15; i++) {
    //     printf("%d ", sol.Fibo(i));
    // }

    int arr[] = {1, 3, 5, 7, 9};
    int idx = sol.BSearchRecur(arr, 0, sizeof(arr)/sizeof(int) - 1, 7);
    printf("답 : %d \n", idx);
    
    
    return 0;
}