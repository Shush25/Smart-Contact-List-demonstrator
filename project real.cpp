# include<stdio.h>
# include<conio.h>
# include<string.h>
# include<stdlib.h>
# include<time.h>
void menu();
void adddetails();
void searchdetails();
void modifydetails();
void deletedetails();
void display();
void call();
void smartsortfunc();
void load_data();
void update_file();
void sort();
void old_record();
struct contact {
  char lastname[20], firstname[20], mob_no[15];//Defining our Linked List//
  int count;
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

  printf(" 6. Call\n");
  
  printf(" 7. Smart Sort\n");

  printf(" 8. EXIT\n ");

  printf(" Enter your choice(1-8):");

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
    call();
    break;
  case 7:
  	smartsortfunc();
  	break;
  case 8:
  	update_file();
  	exit(0);
  	break;
  default:
    printf("Enter valid input only!");

  }
}
void adddetails() {
  FILE *fp;
  fp=fopen("contact_list.csv","a+");
  if(fp==NULL)
  {
  	printf("contact_list.csv file failed to open");
  	exit(1);
  }
  node * ptr, * previous;
  newnode = (node * ) malloc(sizeof(node));
  printf("First name: ");
  scanf("%s", newnode -> firstname);
  printf("Last name:");
  scanf("%s", newnode -> lastname);//Taking details as input from user.//
  printf("Telephone No.: ");
  scanf("%s", newnode -> mob_no);
  fprintf(fp,newnode -> firstname);
  fprintf(fp,",");
  fprintf(fp,newnode -> lastname);
  fprintf(fp,",");
  fprintf(fp,newnode -> mob_no);
  fprintf(fp,"\n");
  newnode->count=0;
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
  fclose(fp);
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
	printf("\nEnter the new First Name: ");
    scanf("%s", ptr -> firstname);
    printf("Last Name : %s", ptr -> lastname);
	printf("\nEnter the new Last Name: ");
    scanf("%s", ptr -> lastname);
    printf("Phone Number : %s", ptr -> mob_no);
	printf("\nEnter the new PhoneNumber: ");
    scanf("%s", ptr -> mob_no);
    printf("\n\nExit the program properly to save changes in file");
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
    printf("\n\nExit the program properly to save changes in file");

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
void call()
{
	node * ptr;
	char string[20];
	if (head == NULL) {
    	printf("\n\t\t\t Phonebook is Empty....\n");
    	getch();
    	return;
  	}
  	printf("First Name of the contact to call : ");
  	scanf("%s", string);
  	ptr = head;
  	while (strcmp(ptr -> firstname, string) != 0) { //If the Item is present it will break before ptr=null//
    	ptr = ptr -> next;
    	if (ptr == NULL) break;
  	}
  	if (ptr != NULL) {
  		time_t t= time(NULL);
  		FILE *fp;
  		fp=fopen("call_log.csv","a+");
  		struct tm tm = *localtime(&t);
  		fprintf(fp,ptr -> firstname);
  		fprintf(fp,",");
  		int year = tm.tm_year+1900;
  		int month = tm.tm_mon + 1;
  		int date = tm.tm_mday;
  		int hour = tm.tm_hour;
  		int min = tm.tm_min;
  		int sec= tm.tm_sec;
  		fprintf(fp,"%d,%d,%d,%d,%d,%d\n",year,month,date,hour,min,sec);
    	printf("Called %s %s \n", ptr -> firstname,ptr -> lastname);
		printf("Called on: %d-%02d-%02d %02d:%02d:%02d\n", year, month, date, hour, min, sec);
		fclose(fp);
  	} else {
    	printf("No such record Found .......\n");
  	}
	getch();
	menu();
}
void load_data()
{
	FILE *fp;
	fp = fopen("contact_list.csv","r");
	if(fp == NULL)
	{
		printf("contact_list.csv file failed to open");
		exit(1);
	}
	char line[200];
	while(fgets(line,sizeof(line), fp))
	{
		node * ptr, * previous, * newnode;
		newnode = (node * ) malloc(sizeof(node));
		char *token;
		token = strtok(line, ",");
		for(int i=0;token!=NULL;i++)
		{
			if(i==0)
			{
				strcpy(newnode -> firstname, token);
			}
			if(i==1)
			{
				strcpy(newnode -> lastname, token);
			}
			if(i==2)
			{
				int len = strlen(token)-1;
				token[len] = '\0';
				strcpy(newnode -> mob_no, token);
				newnode->count=0;
			}
			token = strtok(NULL,",");
		}
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
	}
	fclose(fp);
}
void old_record()
{
	FILE *fp,*np;
	fp=fopen("call_log.csv","r");
	np=fopen("call_log1.csv","wb+");
	time_t t= time(NULL);
	struct tm tm = *localtime(&t);
	int cur_year = tm.tm_year+1900;
  	int cur_month = tm.tm_mon + 1;
	if(fp==NULL)
	{
		printf("Failed to open file call_log.csv");
		exit(1);
	}
	char line[200];
	while(fgets(line,sizeof(line), fp))
	{
		char *token;
		char name[30];
		int year,month,date,min,sec,r_year,r_month,hour;
		token = strtok(line, ",");
		for(int i=0; token!=NULL; i++)
		{
			if(i==0)
			{
				strcpy(name, token);
			}
			if(i==1)
			{
				r_year=atoi(token);
			}
			if(i==2)
			{
				r_month=atoi(token);
			}
			if(i==3)
			{
				date = atoi(token);
			}
			if(i==4)
			{
				hour=atoi(token);
			}
			if(i==5)
			{
				min=atoi(token);
			}
			if(i==6)
			{
				sec=atoi(token);
			}
			token = strtok(NULL,",");
		}
		year= r_year;
		month= r_month;
		if(cur_year == year && month< cur_month-6)
		{
			continue;
		}
		if(year < cur_year){
			month = month +6;
			if(month > 12)
			{
				year =year +1;
				month = month -12;
			}
			if(year<cur_year || (cur_year == year && month< cur_month)){
				continue;
			}
		}
		fprintf(np,"%s,%d,%d,%d,%d,%d,%d\n",name,r_year,r_month,date,hour,min,sec);
	}
	fclose(fp);
	fclose(np);
	remove("call_log.csv");
	rename("call_log1.csv","call_log.csv");
}
void update_file()
{
	FILE *fp;
  	fp=fopen("temp.csv","wb+");
	node *ptr,*next;
	
	
	for (ptr = head; ptr != NULL; ptr = ptr -> next) {
		fprintf(fp,"%s,%s,%s\n",ptr -> firstname, ptr -> lastname, ptr -> mob_no);
	}
	fclose(fp);
	remove("contact_list.csv");
	rename("temp.csv","contact_list.csv");
	ptr=head;
	while(ptr!=NULL)
	{
		next=ptr->next;
		free(ptr);
		ptr = next;
	}
	head=NULL;
}
void smartsortfunc()
{
	struct data{
		char name[30];
		int count;
	};
	FILE *fp;
	fp = fopen("call_log.csv","r");
	time_t t= time(NULL);
	struct tm tm = *localtime(&t);
	int cur_hour = tm.tm_hour;
	int cur_min = tm.tm_min;
	if(fp == NULL)
	{
		printf("call_log.csv file failed to open");
		exit(1);
	}
	node * ptr;
	for (ptr = head; ptr != NULL; ptr = ptr -> next){
		ptr->count=0;
	}
	char line[200];
	while(fgets(line,sizeof(line), fp))
	{
		char *token;
		char name[30];
		int hour,min;
		token = strtok(line, ",");
		for(int i=0;token!=NULL;i++)
		{
			if(i==0)
			{
				strcpy(name, token);
			}
			if(i==4)
			{
				hour=atoi(token);
			}
			if(i==5)
			{
				min=atoi(token);
			}
			token = strtok(NULL,",");
		}
		if(cur_hour-1<=hour && hour<=cur_hour+1){
			if(hour==cur_hour-1 && min<cur_min)
			{
				continue;
			}
			if(hour==cur_hour+1 && min>cur_min)
			{
				continue;
			}
			node * ptr;
			ptr = head;
			while (strcmp(ptr -> firstname, name) != 0) {
				ptr = ptr -> next;
				if (ptr == NULL) break;
			}
			if (ptr != NULL) {
				ptr -> count++;
			} else {
				printf("No such record Found .......\n");
			}
		}
	}
	for (ptr = head; ptr != NULL; ptr = ptr -> next){
		printf("\nThe count of %s is %d",ptr->firstname,ptr->count);
	}
	fclose(fp);
	sort();
	printf("\n\t\t------------------------------\n");
  	for (ptr = head; ptr != NULL; ptr = ptr -> next) {
	    printf("\t\tFirst name: %s", ptr -> firstname);
	    printf("\n\t\tLast name:%s", ptr -> lastname);
	    printf("\n\t\tTelephone No.: %s", ptr -> mob_no);
	    printf("\n\t\t------------------------------\n");
  }
	update_file();
	load_data();
	getch();
	menu();
}
void sort(){
	node *current = head, *index=NULL;
	int temp;
	char t[30];
	if(head==NULL){
		return;
	}
	else{
		while(current!=NULL){
			index=current->next;
			while(index!=NULL){
				if(current->count < index->count){
					temp= current->count;
					current->count=index->count;
					index->count =temp;
					strcpy(t,current->firstname);
					strcpy(current->firstname,index->firstname);
					strcpy(index->firstname,t);
					
					strcpy(t,current->lastname);
					strcpy(current->lastname,index->lastname);
					strcpy(index->lastname,t);
					
					strcpy(t,current->mob_no);
					strcpy(current->mob_no,index->mob_no);
					strcpy(index->mob_no,t);
				}
				index= index->next;
			}
			current= current->next;
		}
	}
}
int main() {

	head = (node * ) malloc(sizeof(node));
	head = NULL;
	load_data();
	old_record();
	menu();
	return 0;

}
