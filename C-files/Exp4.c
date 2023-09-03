//Design, Develop and Implement a menu driven Program in C for the following operations on
//Singly Linked List (SLL) of Student Data with the fields: USN, Name, Branch, Sem, PhNo
//a. Create a SLL of N Students Data by using front insertion.
//b. Display the status of SLL and count the number of nodes in it
//c. Perform Insertion and Deletion at End of SLL
//d. Perform Insertion and Deletion at Front of SLL
//e. Demonstrate how this SLL can be used as STACK and QUEUE
//f. Exit

#include <stdio.h>
#include <stdlib.h>
#define MAX 4
struct student {
char usn[10];
char name[30];
char branch[5];
int sem;
char phno[10];
struct student *next;
};
typedef struct student NODE;
int countnodes(NODE *head) {
NODE *p = head;
int count = 0;
while (p != NULL) {
p = p->next;
count++;
}
return count;
}
NODE* getnode() {
NODE *newnode = (NODE*)malloc(sizeof(NODE));
printf("\nEnter USN, Name, Branch, Sem, Ph.No\n");
scanf("%s", newnode->usn);
scanf("%s", newnode->name);
scanf("%s", newnode->branch);
scanf("%d", &(newnode->sem));
scanf("%s", newnode->phno);
newnode->next = NULL;
return newnode;
}
NODE* display(NODE *head) {
NODE *p = head;
if (p == NULL) {
printf("\nNo student data\n");
} else {
printf("\n----STUDENT DATA----\n");
printf("\nUSN\tNAME\t\tBRANCH\tSEM\tPh.NO.");
while (p != NULL) {
printf("\n%s\t%s\t\t%s\t%d\t%s", p->usn, p->name, p->branch, p->sem,
p->phno);
p = p->next;
}
printf("\nThe no. of nodes in list is: %d", countnodes(head));
}
return head;
}
NODE* insert_front(NODE *head) {
if (countnodes(head) == MAX) {
printf("\nList is Full / Overflow!!");
} else {
NODE *newnode = getnode();
newnode->next = head;
head = newnode;
}
return head;
}
NODE* insert_rear(NODE *head) {
if (countnodes(head) == MAX) {
printf("\nList is Full(QUEUE)!!");
} else {
NODE *newnode = getnode();
if (head == NULL) {
head = newnode;
} else {
NODE *p = head;
while (p->next != NULL) {
p = p->next;
}
p->next = newnode;
}
}
return head;
}
NODE* insert(NODE *head) {
int ch;
do {
printf("\n1.Insert at Front(First)\t2.Insert at End(Rear/Last)\t3.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: head = insert_front(head); break;
case 2: head = insert_rear(head); break;
case 3: break;
}
head = display(head);
} while (ch != 3);
return head;
}
NODE* delete_front(NODE *head) {
if (head == NULL) {
printf("\nList is Empty/Underflow (STACK/QUEUE)");
} else {
NODE *p = head;
head = head->next;
free(p);
printf("\nFront(first) node is deleted");
}
return head;
}
NODE* delete_rear(NODE *head) {
if (head == NULL) {
printf("\nList is Empty/Underflow (STACK/QUEUE)");
} else {
NODE *p = head;
NODE *q = NULL;
while (p->next != NULL) {
q = p;
p = p->next;
}
if (q != NULL) {
q->next = NULL;
} else {
head = NULL;
}
free(p);
printf("\nLast(end) entry is deleted");
}
return head;
}
NODE* del(NODE *head) {
int ch;
do {
printf("\n1.Delete from Front(First)\t2. Delete from
End(Rear/Last)\t3.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: head = delete_front(head); break;
case 2: head = delete_rear(head); break;
case 3: break;
}
head = display(head);
} while (ch != 3);
return head;
}
NODE* stack(NODE *head) {
int ch;
do {
printf("\nSSL used as Stack...");
printf("\n 1.Insert at Front(PUSH) \t 2.Delete from Front(POP) \t
3.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: head = insert_front(head); break;
case 2: head = delete_front(head); break;
case 3: break;
}
head = display(head);
} while (ch != 3);
return head;
}
NODE* queue(NODE *head) {
int ch;
do {
printf("\nSSL used as Queue...");
printf("\n 1.Insert at Rear(INSERT) \t 2.Delete from Front(DELETE) \t
3.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: head = insert_rear(head); break;
case 2: head = delete_front(head); break;
case 3: break;
}
head = display(head);
} while (ch != 3);
return head;
}
int main() {
int ch, i, n;
NODE *head = NULL;
printf("\n*----------Student Database-----------*");
do {
printf("\n 1.Create\t 2.Display\t 3.Insert\t 4.Delete\t 5.Stack\t
6.Queue\t 7.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1:
printf("\nHow many student data you want to create: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
head = insert_front(head);
}
break;
case 2:
head = display(head);
break;
case 3:
head = insert(head);
break;
case 4:
head = del(head);
break;
case 5:
head = stack(head);
break;
case 6:
head = queue(head);
break;
case 7:
exit(0);
}
} while (ch != 7);
return 0;
}
