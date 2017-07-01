#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
};

void menu(){
	printf("1. Create list\n");
	printf("2. Display\n");
	printf("3. Count\n");
	printf("4. Search\n");
	printf("5. Add at beginning\n");
	printf("6. Add at end\n");
	printf("7. Add after node\n");
	printf("8. Add before node\n");
	printf("9. Add at position\n");
	printf("10. Delete\n");
	printf("11. Reverse\n");
	printf("12. Quit\n");
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

void count(struct node *start){
	int count;
	while(start != NULL){
		start = start->link;
		count++;
	}
	printf("\nNumber of elements are : %d\n", count);
}

void search_node(struct node *start){
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

struct node *addAtBeg(struct node *start){
	int n;
	printf("Enter the element to be inserted : ");
	scanf("%d", &n);

	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = n;
	tmp->link = start;
	return tmp;
}

struct node *addAtEnd(struct node *start){
	int n;
	printf("Enter the element to be inserted : ");
	scanf("%d", &n);

	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = n;
	tmp->link = NULL;

	struct node *tmp_start = start;
	while(tmp_start->link != NULL){
		tmp_start = tmp_start->link;
	}
	tmp_start->link = tmp;
	return start;
}

struct node *addAfterNode(struct node *start){
	struct node *tmp_start = start;
	int item, data;
	printf("Enter the element to be inserted : ");
	scanf("%d", &data);
	printf("Enter element after which to insert : ");
	scanf("%d", &item);

	int flag = 0;

	while(tmp_start != NULL){
		if(tmp_start->data == item){
			flag = 1;
		}
		tmp_start = tmp_start->link;
	}

	if(flag){
		tmp_start = start;
		while(tmp_start != NULL){
			if(tmp_start->data == item){
				struct node *tmp = (struct node*)malloc(sizeof(struct node));
				tmp->data = data;
				tmp->link = tmp_start->link;
				tmp_start->link = tmp;
				return start;
			}
			tmp_start = tmp_start->link;
		}
		return start;
	}else{
		printf("%d not present in the list\n" , item);
	}
	return start;
}

struct node *addBeforeNode(struct node *start){
	struct node *tmp_start = start;
	int item, data;
	printf("Enter the element to be inserted : ");
	scanf("%d", &data);
	printf("Enter element before which to insert : ");
	scanf("%d", &item);

	int flag = 0;

	while(tmp_start != NULL){
		if(tmp_start->data == item){
			flag = 1;
		}
		tmp_start = tmp_start->link;
	}

	if(flag){
		tmp_start = start;
		struct node *tmp = (struct node*)malloc(sizeof(struct node));
		tmp->data = data;

		if(tmp_start->data == item){
			tmp->link = tmp_start;
			start = tmp;
			return start;
		}else{
			while(tmp_start != NULL){
				if(tmp_start->link->data == item){
					tmp->link = tmp_start->link;
					tmp_start->link = tmp;
					return start;
				}
				tmp_start = tmp_start->link;
			}
		}
	}else{
		printf("%d not present in the list\n" , item);
	}
	return start;
}

struct node *addAtPotision(struct node *start){
	int i, pos, item;
	printf("Enter the element to be inserted : ");
	scanf("%d", &item);
	printf("Enter the position at which to insert : ");
	scanf("%d", &pos);

	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = item;

	if(pos == 1){
		tmp->link = start;
		start = tmp;
		return start;
	}

	struct node *tmp_start = start;
	for(i=1; i<pos-1 && tmp_start !=NULL; i++){
		tmp_start = tmp_start->link;
	}

	if(tmp_start == NULL){
		printf("There are less than %d elements", pos);
	}
	else{
		tmp->link = tmp_start->link;
		tmp_start->link = tmp;
	}
return start;
}

struct node *delete_node(struct node *start){
	int item;
	struct node *tmp;

	printf("\nEnter the element to be deleted : ");
	scanf("%d", &item);

	if(start == NULL){
		printf("\nList is Empty...\n");
		return start;
	}

	if(start->data == item){
		tmp = start;
		start = start->link;
		free(tmp);
		return start;
	}

	struct node *tmp_start = start;

	while(tmp_start->link != NULL){
		if(tmp_start->link->data == item){
			tmp = tmp_start->link;
			tmp_start->link = tmp_start->link->link;
			free(tmp);
			return start;
		}
		tmp_start = tmp_start->link;
	}
	printf("\nElement %d not found", item);
}

struct node *reverse(struct node *start){
	struct node *next, *prev;
	next = prev = NULL;

	while(start != NULL){
		next = start->link;
		start->link = prev;
		prev =  start;
		start = next;
	}

	return prev;
}

int main(){
	int n, choise;
	struct node *start = NULL;

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
				count(start);
				break;

			case 4:
				search_node(start);
				break;

			case 5:
				start = addAtBeg(start);
				break;

			case 6:
				start = addAtEnd(start);
				break;

			case 7:
				start = addAfterNode(start);
				break;

			case 8: 
				start = addBeforeNode(start);
				break;

			case 9:
				start = addAtPotision(start);
				break;

			case 10:
				start = delete_node(start);
				break;

			case 11:
				start = reverse(start);
				break;

			case 12:
				exit(1);

			default:
				printf("Wrong choise");
				menu();
				exit(1);
		}
	}
}
