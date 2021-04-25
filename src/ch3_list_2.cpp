#include <iostream>
#include "../ext/Ch03/ArrayListPointStructBase/ArrayList.c"
#include "../ext/Ch03/ArrayListPointStructBase/Point.c"

using namespace std;


/*
 * Chapter 3. (연결)리스트
 */
class Solution {
public:
    // 값 저장을 Point 좌표로 바꾼다.
    int pointListMain() {
        List list;
        Point compPos;
        Point * ppos;

        ListInit(&list);

        // 데이터 4개 저장
        ppos = (Point *) malloc(sizeof(Point));
        SetPointPos(ppos, 2, 1);
        LInsert(&list, ppos);

        ppos = (Point *) malloc(sizeof(Point));
        SetPointPos(ppos, 2, 2);
        LInsert(&list, ppos);

        ppos = (Point *) malloc(sizeof(Point));
        SetPointPos(ppos, 3, 1);
        LInsert(&list, ppos);

        ppos = (Point *) malloc(sizeof(Point));
        SetPointPos(ppos, 3, 2);
        LInsert(&list, ppos);

        // 위에서 저장한 데이터 출력
        printf("저장된 데이터 수 : %d \n", LCount(&list));
        if(LFirst(&list, &ppos)) {
            ShowPointPos(ppos);
            while(LNext(&list, &ppos)) {
                ShowPointPos(ppos);
            }
        }
        printf("\n");

        // xpos좌표rk 2인 모든 데이터 삭제
        compPos.xpos = 2;
        compPos.ypos = 0;

        if(LFirst(&list, &ppos)) {
            if(PointComp(ppos, &compPos)==1) {
                ppos = LRemove(&list);
                free(ppos);
            }
            while(LNext(&list, &ppos)) {
                if(PointComp(ppos, &compPos)==1) {
                    ppos = LRemove(&list);
                    free(ppos);
                }
            }
        }

        // 삭제 후 남은 데이터 출력
        printf("현재 데이터 수 : %d \n", LCount(&list));
        if(LFirst(&list, &ppos)) {
            ShowPointPos(ppos);

            while(LNext(&list, &ppos)) {
                ShowPointPos(ppos);
            }
        }
        printf("\n");

        return 0;
    }
    int dummy() {
        return 123;
    }
};


// Driver code
int main() {
    Solution sol;
    sol.pointListMain();

    return 0;
}