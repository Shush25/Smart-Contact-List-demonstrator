# include<stdio.h>
# include<conio.h>
# include<string.h>
# include<stdlib.h>
FILE *fp;
void menu();
void adddetails();
void searchdetails();
void modifydetails();
void deletedetails();
void display();
struct contact {
  char lastname[20], firstname[20], mob_no[15];//Defining our Linked List//
  struct contact * next;
};
typedef struct contact node;
node * head, * newnode;
void menu() {
  int choice;

  printf("\nPHONEBOOK\n");

  printf(" ------------------\n");

  printf(" 1. Add\n");

  printf(" 2. Search\n");

  printf(" 3. Modify\n");

  printf(" 4. Delete\n");

  printf(" 5. Display\n");

  printf(" 6. EXIT\n ");

  printf(" Enter your choice(1-6):");

  scanf("%d", & choice);
  switch (choice) {
  case 1:
    adddetails();
    break;
  case 2:
    searchdetails();
    break;
  case 3:
    modifydetails();
    break;
  case 4:
    deletedetails();
    break;
  case 5:
    display();
    break;
  case 6:
    exit(0);
    break;
  default:
    printf("Enter valid input only!");

  }
}
void adddetails() {
  node * ptr, * previous;
  newnode = (node * ) malloc(sizeof(node));
  printf("First name: ");
  scanf("%s", newnode -> firstname);
  printf("Last name:");
  scanf("%s", newnode -> lastname);//Taking details as input from user.//
  printf("Telephone No.: ");
  scanf("%s", newnode -> mob_no);
  newnode -> next = NULL;
  if (head == NULL) {
    head = newnode;//If there is no linked list then add the details to the head//
  } else {
    previous = ptr = head;
    //This loop sorts out the Contact in ascending order.//
    while (strcmp(newnode -> firstname, ptr -> firstname) > 0) {
	  previous = ptr;
      ptr = ptr -> next; //The loops breaks if it is at the end of the linked list or //
      if (ptr == NULL) break;//If the character of the new node is less than the character of the new node ascii.//
    }
    if (ptr == previous) {
      newnode -> next = head;//Insert at the 1st positon.//
      head = newnode;
    } else if (ptr == NULL) {
      previous -> next = newnode;//Insert in the last position//
    } else {
      newnode -> next = ptr;
      previous -> next = newnode;//Insert in the middle//
    }
  }
  getch();
  menu();
}
void searchdetails() {
  node * ptr;
  char string[20];
  if (head == NULL) {
    printf("\n\t\t\t Phonebook is Empty....\n");
    getch();
    return;
  }
  printf("First Name to Find : ");
  scanf("%s", string);
  ptr = head;
  while (strcmp(ptr -> firstname, string) != 0) { //If the Item is present it will break before ptr=null//
    ptr = ptr -> next;
    if (ptr == NULL) break;
  }
  if (ptr != NULL) {
    printf("First Name : %s\n", ptr -> firstname); 
    printf("Last Name : %s\n", ptr -> lastname);
    printf("Phone Number : %s\n", ptr -> mob_no);
  } else {
    printf("No such record Found .......\n");
  }
  getch();
  menu();
}
void modifydetails() {
  node * ptr;
  char string[20];
  if (head == NULL) {
    printf("\n\t\t\tPhonebook is Empty....\n");
    getch();
    return;
  }
  printf("First Name to Edit : ");
  scanf("%s", string);
  ptr = head;
  while (strcmp(ptr -> firstname, string) != 0) {
    ptr = ptr -> next;
    if (ptr == NULL) break;
  }
  if (ptr != NULL) {
    printf("First Name : %s", ptr -> firstname);

    scanf("%s", ptr -> firstname);
    printf("Last Name : %s", ptr -> lastname);

    scanf("%s", ptr -> lastname);
    printf("Phone Number : %s", ptr -> mob_no);

    scanf("%s", ptr -> mob_no);
  } else {
    printf("No such record Found .......\n");
  }
  getch();
  menu();
}
void deletedetails() {
  node * ptr, * previous, * newnode;
  char string[20];
  if (head == NULL) {
    printf("\n\t\t\tPhonebook is Empty....\n");
    getch();
    menu();
  }
  printf("First Name to Delete : ");
  scanf("%s", string);
  previous = ptr = head;
  while (strcmp(ptr -> firstname, string) != 0) {
    previous = ptr;
    ptr = ptr -> next;
    if (ptr == NULL) break;
  }
  if (ptr != NULL) {
    printf("\n\n---------------------------------------------------------");
    printf("\nFirst Name : %s\n", ptr -> firstname);
    printf("Last Name : %s\n", ptr -> lastname);
    printf("Phone Number : %s\n", ptr -> mob_no);
    printf("---------------------------------------------------------");

    if (ptr == head) {
      newnode = head -> next;//Copying the 2nd node to the newnode.//
      free(head); //removing the node in the head.//
      head = newnode; //Assigning the head node with the newnode which is the 2nd node.//
    } else {
      newnode = ptr -> next; //Removing the node in the middle of the linked list.//
      free(ptr);
      previous -> next = newnode;
    }
    printf("\n\nThe Record has been Deleted....");

  } else {
    printf("\nNo such record Found .......");
  }
  getch();
  menu();
}
void display() {
  node * ptr;
  if (head == NULL) {
    printf("\n\t\t\tTelephone Directory is Empty....\n");
    getch();
    menu();
  }

  printf("\t\t------------------------------\n");
  for (ptr = head; ptr != NULL; ptr = ptr -> next) {
    printf("\t\tFirst name: %s", ptr -> firstname);
    printf("\n\t\tLast name:%s", ptr -> lastname);
    printf("\n\t\tTelephone No.: %s", ptr -> mob_no);
    printf("\n\t\t------------------------------\n");
  }
  getch();
  menu();
}
int main() {

  head = (node * ) malloc(sizeof(node));
  head = NULL;
  menu();
  return 0;

}
