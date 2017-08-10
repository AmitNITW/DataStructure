#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
};

void menu(){
	printf("1. Create list\n");
	printf("2. Display\n");
	printf("3. Length Using Iterative\n");
	printf("4. Length Using Recursive\n");
	printf("5. Quit\n");
}

struct node *create_list(struct node *start){
	int n;
	struct node *tmp_start, *tmp;
	printf("Enter list elements (-1 for stop list creation) : ");
	while(1){
		scanf("%d", &n);
		if (n == -1)
			break;

		tmp_start = start;

		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->data = n;
		tmp->link = NULL;
	
		if(tmp_start == NULL){
			start = tmp;
		}else{
			while(tmp_start->link != NULL){
				tmp_start = tmp_start->link;
			}
			tmp_start->link = tmp;
		}	
	}
	return start;
}

void display(struct node *start){

	if(start == NULL){
		printf("List is Empty...");
		return;
	}

	printf("\nlist are : ");
	while(start != NULL){
		printf("%d\t", start->data);
		start = start->link;
	}
	printf("\n");
}

void lengthUsingIterative(struct node *start){
	int count;
	while(start != NULL){
		start = start->link;
		count++;
	}
	printf("\nSize of Linked List is : %d\n", count);
}

int lengthUsingRecursive(struct node *start){
	if(start == NULL)
		return 0;

	return 1 + lengthUsingRecursive(start->link);
}

int main(){
	struct node *start = NULL;
	int choise;
	menu();
	while(1){
		printf("\nEnter your choise : ");
		scanf("%d", &choise);

		switch(choise){
			case 1:
				start = create_list(start);
				break;

			case 2:
				display(start);
				break;

			case 3:
				lengthUsingIterative(start);
				break;

			case 4:
				printf("\nSize of Linked List is : %d\n", lengthUsingRecursive(start));
				break;

			case 5:
				exit(1);

			default:
				printf("Wrong choise\n");
				menu();
		}
	}
}
