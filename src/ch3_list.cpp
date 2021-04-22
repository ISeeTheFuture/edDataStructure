#include <iostream>
#include "ArrayList.h"

using namespace std;


/*
 * Chapter 3. (연결)리스트
 */
class Solution {
public:
    int firstTest() {
        // 책에서 제공한 라이브러리. ext/ArrayList
        List list;
        int data;
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

    int dummy() {
        return 123;
    }
};


// Driver code
int main() {
    Solution sol;
    sol.firstTest();
    return 0;
}