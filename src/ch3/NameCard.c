#include "NameCard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NameCard* MakeNameCard(char* name, char* phone) {
    NameCard* newCard = (NameCard*)malloc(sizeof(NameCard));
    strncpy(newCard->name, name, NAME_LEN); // newCard->name = name 은 이 함수 내의 지역변수 name를 가리킬 뿐이므로, 함수가 끝나는 순간 증발한다. newCard->name 에 직접 써줘야 한다.
    strncpy(newCard->phone, phone, PHONE_LEN);
    return newCard;
}
void ShowNameCardInfo(NameCard* pcard) {
    printf("이름 : %s \n", pcard->name);
    printf("전화번호 : %s \n", pcard->phone);
}
int NameCompare(NameCard* pcard, char* name) {
    return strncmp(pcard->name, name, NAME_LEN);
}
void ChangePhoneNum(NameCard* pcard, char* phone) {
    strncpy(pcard->phone, phone, PHONE_LEN);
}