#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


/*
 * Chapter 4. (연결)리스트2
 */
class Solution {
public:
    int dummy() {
        return 123;
    }

    typedef struct _node {
        int data;
        struct _node * next;
    } Node;

    int linkedRead() {
        Node* head = NULL;
        Node* tail = NULL;
        Node* cur = NULL;

        Node* newNode = NULL;
        int readData;

        while(1) {
            printf("input number : ");
            scanf("%d", &readData);
            if(readData < 1) {
                break;
            }

            newNode = (Node*)malloc(sizeof(Node));
            newNode->data = readData;
            newNode->next = NULL;

            if(head == NULL) {
                head = newNode;
            } else {
                tail->next = newNode;
            }
            tail = newNode;
        }

        printf("\n");

        printf("----- data ----- \n");
        if(head == NULL) {
            printf("there is nothing. \n");
        } else {
            cur = head;
            printf("%d", cur->data);

            while (cur->next != NULL) {
                cur = cur->next;
                printf("%d ", cur->data);
            }
        }
        printf("\n\n");

        if(head == NULL) {
            return 0;
        } else {
            Node* delNode = head;
            Node* delNextNode = head->next;

            printf("%d is removed. \n", head->data);
            free(delNode);

            while(delNextNode != NULL) {
                delNode = delNextNode;
                delNextNode = delNextNode->next;

                printf("%d is removed. \n", delNode->data);
                free(delNode);
            }
        }
        return 0;
    }
};


// Driver code
int main() {
    Solution sol;
    sol.linkedRead();
    return 0;
}