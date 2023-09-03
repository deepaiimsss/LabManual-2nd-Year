//Design, Develop and Implement a menu driven program in C for the following operations on
//STACK of integers (Array implementation of stack with maximum size MAX)
//a. Push an element on to stack
//b. Pop an element from stack.
//c. Demonstrate how stack can be used to check palindrome.
//d. Demonstrate Overflow and Underflow situations on stack.
//e. Display the status of stack.
//f. Exit.
//Support the program with appropriate functions for each of the above operations.

#include <stdio.h>
#include <stdlib.h>

int s[5], top = -1;
void push()
{
    if (top == 4)
        printf("\n Stack overflow!!!");
    else
    {
        printf("\n Enter element to insert: ");
        scanf("%d", &s[++top]);
    }
}
void pop()
{
    if (top == -1)
        printf("\n Stack Underflow!!!");
    else
        printf("\n Element popped is: %d", s[top--]);
}
void disp()
{
    int t = top;
    if (t == -1)
        printf("\n Stack Empty");
    else
        printf("\n Stack Elements are: \n");
    while (t >= 0)
        printf("%d", s[t--]);
}
void pali()
{
    int num[5], rev[5], i, t;
    for (i = 0, t = top; t >= 0; i++, t--)
        num[i] = rev[t] = s[t];
    for (i = 0; i <= top; i++)
        if (num[i] != rev[i])
            break;
    if (i == top + 1)
        printf("\n It is a palindrome");
    else
        printf("\n It is not a palindrome");
}
int main()
{
    int ch;
    do
    {
        printf("\n ... Stack Operations...\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. Palindrome\n");
        printf("4. Display\n");
        printf("5. Exit\n___________\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:pali();break;
            case 4:disp();break;
            case 5:exit(0);
            default:printf("\n Invalid Choice");
        }
    }
    while(1);
    return 0;
}
