#include <stdio.h>
 #include <stdlib.h>
 struct node
 {
     char data[50];
     struct node *next;
};

    Traverse   linklist
 void Traverselinklist(struct node *ptr)
 {
     while (ptr != NULL)
     {
        printf("Element is : ");
         puts(ptr->data);
         ptr = ptr->next;
     }
 }

 insert at first
 struct node *insertatfirst(struct node *head, char data[])
 {
     struct node *ptr = (struct node *)malloc(sizeof(struct node));
     ptr->next = head;
     ptr->data[50]= data;
     return ptr;
 }

 insert at position
 struct node *insertatposition(struct node *head, int data, int index)
 {
     struct node *ptr = (struct node *)malloc(sizeof(struct node));
     struct node *p = head;
     int i = 0;
     while (i != index - 1)
     {
         p = p->next;
         i++;
     }
     ptr->data[50] = data;
     ptr->next = p->next;
     p->next = ptr;
     return head;
 }
  insert at end
struct node *insertatend(struct node *head, int data)
 {
     struct node *ptr = (struct node *)malloc(sizeof(struct node));
     struct node *p = head;
     int i = 0;
     while (p->next != NULL)
     {
        p = p->next;
         i++;
     }
     ptr->data[50] = data;
     p->next = ptr;
     ptr->next = NULL;
     return head;
 }
 delete from begin
 struct node *deletefrombegin(struct node *head)
 {
     struct node *ptr = head;
     head = head->next;
     free(ptr);
     return head;
 }
 delete from position
 struct node *deletefromposition(struct node *head, int index)
 {
     struct node *p = head;
     struct node *q = head->next;

     for (int i = 1; i < index - 1; i++)
     {
         p = p->next;
         q = q->next;
     }

     p->next = q->next;
     free(q);
     return head;
 }
 delete from last
 struct node *deletefromlast(struct node *head)
{
     struct node *p = head;
     struct node *q = head->next;

     while (q->next != NULL)
     {
         p = p->next;
         q = q->next;
     }

     p = p->next = NULL;
     free(q);
     return head;
 }
 search in linked list
struct node *search(struct node *head, int value)
 {
    struct node *p = head;
     int present = 0;
     while (p != NULL)
     {
         if (p->data == value)
         {             present = 1;
            printf("%d is present\n", value);
             break;
    }
         p = p->next;
    }
     if (present == 0)
     {
         printf("Not present\n");
     }
 }
 search in linked list
 struct node *isempty(struct node *head)
 {
     struct node *p = head;
    if (p->data == NULL)
     {
         printf("Link list is empty\n");
     }
     else
     {

        printf("Link list is not empty\n");
     }
 }
 int main()
 {
    struct node *head, *second, *third, *fourth, *fifth;
     head = (struct node *)malloc(sizeof(struct node));
     second = (struct node *)malloc(sizeof(struct node));
     third = (struct node *)malloc(sizeof(struct node));
     fourth = (struct node *)malloc(sizeof(struct node));
     fifth = (struct node *)malloc(sizeof(struct node));

     head->data[] = 1;
     head->next = second;

    second->data[50] = 2;
     second->next = third;

     third->data[50] = 3;
     third->next = fourth;

     fourth->data[50] = 4;
     fourth->next = fifth;

     fifth->data[50] = 5;
     fifth->next = NULL;

     while (1)
     {
         printf("1. Display value of linked list \n");
         printf("2. Insert value at begin of linked list \n");
         printf("3. Insert value at position of linked list \n");
         printf("4. Insert value at end of linked list \n");
        printf("5. Delete value from begin of linked list \n");
       printf("6. Delete value from position of linked list \n");
        printf("7. Delete value from end of linked list \n");
        printf("8. Search value in lined list \n");
        printf("9. Check linked list is empty \n");
        printf("10. Check linked list is full \n");

         printf("\nChose a option\n");
        int number;
         scanf("%d", &number);

        switch (number)
         {
        case 1:
             Traverselinklist(head);
             break;

         case 2:
            printf("Enter a string which you insert at first : ");
            char newvalue[50];
            gets(newvalue);

             head = insertatfirst(head, newvalue);
          break;
         case 3:
             printf("Enter position : ");
             int position;
             scanf("%d", &position);

             printf("Enter string : ");
             char newvalue1[50];
             scanf("%d", &newvalue1);

             insertatposition(head, newvalue1, position);
             break;

       case 4:
             printf("Enter a string which you insert at end : ");
             char newvalue2[50];
             scanf("%d", &newvalue2);

             insertatend(head, newvalue2);
          break;
         case 5:
             head = deletefrombegin(head);
            printf("First string deleted");
             break;
        case 6:
             printf("Enter position : ");
             int position2;
             scanf("%d", &position2);
             deletefromposition(head, position2);
             printf("string deleted\n");
             break;
         case 7:
            deletefromlast(head);
            printf("Last string deleted\n");
             break;
         case 8:
             printf("Enter string which you want to search ");
             int newvalue3;
             scanf("%d", &newvalue3);
             search(head, newvalue3);
             break;
         case 9:
             isempty(head);
             break;
         default:
             printf("Enter valid option\n");
             break;
         }
     }

     return 0;
}