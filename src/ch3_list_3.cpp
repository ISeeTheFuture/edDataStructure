#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ArrayList.c"
#include "NameCard.h"

using namespace std;


/*
 * Chapter 3. (연결)리스트
 */
class Solution {
public:
    /**
     * 문제 3-2
     * NameCard 구조체를 작성하고, 이를 활용하라
     */
    int qThirdTwo(void) {
        List list;
        NameCard* pCard;
        ListInit(&list);

        // 1) 총 3명의 전화번호 정보를 저장한다
        pCard = MakeNameCard("aaa", "000-0000-0000");
        LInsert(&list, pCard);
        pCard = MakeNameCard("bbb", "111-1111-1111");
        LInsert(&list, pCard);
        pCard = MakeNameCard("ccc", "222-2222-2222");
        LInsert(&list, pCard);

        // 2) bbb의 정보 출력
        if(LFirst(&list, &pCard)) {
            do {
                if(!NameCompare(pCard, "bbb")) {
                   ShowNameCardInfo(pCard);
                   break;
                }
            } while(LNext(&list, &pCard));
        }

        // 3) aaa의 전화번호 변경
        if(LFirst(&list, &pCard)) {
            do {
                if(!NameCompare(pCard, "aaa")) {
                   ChangePhoneNum(pCard, "333-3333-3333");
                   break;
                }
            } while(LNext(&list, &pCard));
        }

        // 4) bbb 정보 삭제
        if(LFirst(&list, &pCard)) {
            do {
                if(!NameCompare(pCard, "bbb")) {
                    pCard = LRemove(&list); // aaa -> ccc 로 연결해준다. 메모리 해제는 안해준다.
                    free(pCard);
                    break;
                }
            } while(LNext(&list, &pCard));
        }

        // 5) 남은 사람의 전화번호 출력
        printf("남은 데이터 수 : %d \n", LCount(&list));
        if(LFirst(&list, &pCard)) {
            do {
                ShowNameCardInfo(pCard);
            } while(LNext(&list, &pCard));
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
    sol.qThirdTwo();

    return 0;
}