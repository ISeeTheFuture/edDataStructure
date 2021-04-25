#include <iostream>
#include "../ext/Ch03/ArrayList/ArrayList.c"

using namespace std;


/*
 * Chapter 3. (연결)리스트
 */
class Solution {
public:
    int firstTest() {
        // 책에서 제공한 라이브러리. ext/ArrayList
        List list;
        int data = 0;
        ListInit(&list);

        // 데이터 5개 저장
        LInsert(&list, 11);
        LInsert(&list, 11);
        LInsert(&list, 22);
        LInsert(&list, 22);
        LInsert(&list, 33);

        // 저장된 데이터 출력
        printf("현재 데이터 수 : %d \n", LCount(&list));
        if(LFirst(&list, &data)) {
            printf("%d ", data);

            while(LNext(&list, &data)) {
                printf("%d ", data);
            }
            printf("\n\n");
        }

        // 숫자 22를 탐색 후 삭제
        if(LFirst(&list, &data)) {
            if(data == 22) {
                LRemove(&list);
            }
            while(LNext(&list, &data)) {
                if(data == 22) {
                    LRemove(&list);
                }
            }
        }

        // 삭제 후 남은 데이터 출력
        printf("현재 데이터 수 : %d \n", LCount(&list));
        if(LFirst(&list, &data)) {
            printf("%d ", data);

            while(LNext(&list, &data)) {
                printf("%d ", data);
            }
            printf("\n\n");
        }
        return 0;
    }

    /**
     * 문제 03 - 1, 리스트 라이브러리의 활용
     */
    int qThirdOne() {
        List list;
        int data = 0;
        ListInit(&list);

        // 1) 1 ~ 9 까지 저장.
        for(int i = 1; i <= 9; i++) {
            LInsert(&list, i);
        }

        // 2) 리스트에 저장된 값을 조회하고 그 합을 계산.
        LFirst(&list, &data);
        int sum = data;
        while(LNext(&list, &data)) {
            sum += data;
        }
        printf("리스트 합 : %d\n", sum);

        // 3) 2의 배수, 3의 배수 삭제
        LFirst(&list, &data);
        do {
            if(data % 2 == 0 || data % 3 == 0) {
                LRemove(&list);
            }
        } while(LNext(&list, &data));

        // 4) 리스트 저장된 데이터 출력
        LFirst(&list, &data);
        do {
            printf("리스트 데이터 : %d\n", data);
        } while(LNext(&list, &data));

        return 0;
    }


    int dummy() {
        return 123;
    }
};


// Driver code
int main() {
    Solution sol;
    // sol.firstTest();
    sol.qThirdOne();
    return 0;
}