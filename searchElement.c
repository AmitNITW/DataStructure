#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
};

void menu(){
	printf("1. Create list\n");
	printf("2. Display\n");
	printf("3. Search Using Iterative\n");
	printf("4. Search Using Recursive\n");
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

void searchUsingIterative(struct node *start){
	int item, pos;
	printf("Enter the element to be searched : ");
	scanf("%d", &item);

	while(start != NULL){
		if(start->data == item){
			printf("\nItem %d fount at position %d\n", item, pos);
			return;
		}
		pos++;
		start = start->link;
	}
	printf("\nItem %d not fount in list\n", item);
}

int elementPosition = 1;
int searchUsingRecursive(struct node *start, int n){
	if(start == NULL){
		elementPosition = 0;
		return -1;
	}else{
		if(start->data == n){
			return 0;
		}
		else{
			return elementPosition + searchUsingRecursive(start->link, n);
		}
	}
}

int main(){
	struct node *start = NULL;
	int choise, item, pos;
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
				searchUsingIterative(start);
				break;

			case 4:
				printf("Enter the element to be searched : ");
				scanf("%d", &item);
				pos = searchUsingRecursive(start, item);
				if(pos >= 0){
					printf("\nItem %d fount at position %d\n", item, pos);
				}else{
					printf("\nItem %d not fount in list\n", item);
				}
				
				break;

			case 5:
				exit(1);

			default:
				printf("Wrong choise\n");
				menu();
		}
	}
}
