# include <stdio.h>
# include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void insertFirst(){
	struct node *newNode=NULL;
	int val;
	newNode=(struct node *)malloc(sizeof(struct node));
	if(newNode==NULL){
		printf("OVERFLOW"); }
		else{
			printf("Enter the value to be inserted\n");
			scanf("%d",&val);
			newNode->data=val;
			newNode->next=start;
			start=newNode;
			printf("Insertion at start succesfull\n");
			}
	};
void insertLast(){
	struct node *newNode=NULL;
	struct node *temp;
	int val;
	newNode=(struct node *)malloc(sizeof(struct node));
	if(newNode==NULL){
		printf("OVERFLOW");
		}
		else {
			printf("Enter the value to be inserted\n");
			scanf("%d",&val);
			newNode->data=val;
			newNode->next=NULL;
			temp=start;
			while(temp->next!=NULL){
				temp=temp->next;
				}
				temp->next=newNode;
				printf("Insertion at last is succesful\n");
			}
	};
void deletefirst(){
	struct node *temp;
	if(start==NULL){
		printf("UNDERFLOW\n");
		}
		else {
			temp=start;
			start=start->next;
			free(temp);
			printf("Deletion at start succesful\n");
			}
	};
void deletelast(){
	struct node *temp;
	struct node *prev;
	if(start==NULL){
		printf("UNDERFLOW");
		}
		else{
			temp=start;
			prev=start;
			while(temp->next!=NULL){
				prev=temp;
				temp=temp->next;
				}
				prev->next=NULL;
				free(temp);
				printf("Deletion at last successfull\n");
			}
	};
void displayLL(){
	struct node *temp;
	temp=start;
	if(temp==NULL)
	{
		printf("UNDERFLOW\n\n");
	}
	else{
		printf("start->");
		while(temp->next!=NULL){
			printf("%d -> ",temp->data);
			temp=temp->next;
			}
			printf("%d -> ",temp->data);
		printf("NULL\n\n");
		}
	};
int main()
{
	int ch=1;
	
	while(ch!=0)
	{
		printf("1. Insert at Start\n");
		printf("2. Insert at End\n");
		printf("3. Delet at first \n");
		printf("4. Delete at last\n");
		printf("9. Display Link List\n");
		printf("0. Exit\n");
		printf("Enter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			insertFirst();
			break;
			case 2:
			insertLast();
			break;
			case 3:
			deletefirst();
			break;
			case 4:
			deletelast();
			break;
			case 9:
			displayLL();
			break;
			case 0:
			printf("Thanks for using our program\n");
			exit(1);
			break;
			default:
			printf("Incorrect Choice. Please try again...\n");
			break;
		}
	}
	return 0;
}
