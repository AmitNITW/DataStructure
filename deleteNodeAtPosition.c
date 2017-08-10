#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void menu(){
	printf("1. Create list\n");
	printf("2. Display\n");
	printf("3. Delete node at position\n");
	printf("4. Quit\n");
}

struct node *create_list(struct node *start){
	int item;
	printf("Enter list elements (-1 for stop list creation) : ");
	struct node *tmp, *tmp_start;
	while(1){
		scanf("%d", &item);
		if(item == -1)
			break;

		tmp_start = start;

		tmp = (struct node*)malloc(sizeof(struct node));
		tmp->data = item;
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

int count(struct node *start){
	int count;
	while(start != NULL){
		start = start->link;
		count++;
	}
	return count;
}

struct node *delete_node_pos(struct node *start){
	int i, pos;
	struct node *tmp;
	printf("Enter the position at which to delete (position start from 0): ");
	scanf("%d", &pos);
	int size = count(start);

	printf("Size : %d\n", size);
	if(size > pos){
		if(pos == 0){
			tmp = start;
			start = start->link;
			free(tmp);
			return start;
		}else{
			struct node *tmp_start = start;
			for(i=0; i<pos-1 && tmp_start != NULL; i++){
				tmp_start = tmp_start->link;
			}
			tmp = tmp_start->link;
			tmp_start->link = tmp_start->link->link;
			free(tmp);
		}
		return start;
	}else{
		printf("Entered position is incorrect...\n");
		return start;
	}
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
				start = delete_node_pos(start);
				break;

			case 4:
				exit(1);

			default:
				printf("Wrong choise\n");
				menu();
//				exit(1);
		}
	}
}
