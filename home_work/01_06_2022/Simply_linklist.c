#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

// FOR DISPLAY
void display(struct node *first)
{
struct node *save;
save=first;
do
	{
	printf("%d,",save->info);
	save=save->link;
	}
while(save != NULL);
}

//FOR INSERT
struct node* insert(int x,struct node *first)
{
struct node *new;
new=(struct node *)malloc(sizeof(struct node));
if(new==NULL)
	{
		printf("Overflow !!\n");
		return first;
	}
else
	{
	new->info=x;
	new->link=first;
	return new;
	}
}


struct node* insert_end(int x,struct node *first)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	struct node *save;
	save=first;
	
	if(new==NULL)
	{
		printf("Overflow\n");
		return first;
	}else
	{
		new->info=x;	
		new->link=NULL;
	}
	while(save->link != NULL)
	{
		save=save->link;
	}
	save->link=new;
	return first;
} 

int count (struct node *first)
{
	int c=0;	
	struct node *save;
	save=first;
	if(save == NULL)
	return c;
	else{
		while(save!=NULL){
		c++;
		save=save->link;
	 	    }
	return c;
	}
}

struct node* insert_sort(int x,struct node *first)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	struct node *save;
	save=first;
	
	if(save == NULL)
	{
		printf("Empty\n");
		return new;
	}

	new->info=x;
	if(new->info <= first->info){
		new->link=first;
		return new;
	}
	
	while(save->link != NULL && new->info >= save->link->info){
		save=save->link;
	}
	
	new->link=save->link;
	save->link=new;
	
	return first;
}

void Sort(struct node *first)
{
	//int swapped, i;
	//struct node *ptr1;
	//struct node *lptr = NULL;

	if (first == NULL)
	{
		return 0;
	}else{
		while(first->link != NULL)
		{
			if(first->info > first->link->info)
			{
				int temp = first->info;
				first->info = first->link->info;
				first->link->info = temp;
			}
			first = first->link;
		}
	}
}	

struct node* delete(struct node* x,struct node *first)
{
	if(first == NULL){
		printf("Underflow");
		return 0;
	}

	struct node *pred;
	pred=(struct node*)malloc(sizeof(struct node));
	struct node *save;
	
	save=first;

	while(save != x && save->link != NULL){
		pred=save;
		save=save->link;
	}
	if(save != x){
		printf("Element not found");
		return 0;
	}	
	if(x == first){
		first=first->link;
		return first;	
	}
	else{
		pred->link=x->link;
		return first;
	}free(x);
}	

struct node* copy(struct node* first)
{
	struct node *new;
	struct node *begin;
	struct node *pred;
	struct node *save;
	new=(struct node*)malloc(sizeof(struct node));

	if(first == NULL){
		printf("Linklist Empty");
		return NULL;
	}
	if(new == NULL){	
		printf("Underflow !!");
	}
	
	new->info=first->info;
	begin=new;
	save=first;

	pred=new;
	save=save->link;
	
	while(save!=NULL){
		new=(struct node*)malloc(sizeof(struct node));
		if(new == NULL){	
			printf("Underflow !!");
			return NULL;
			}
		
		new->info=save->info;
		pred->link=new;

		pred=new;
		save=save->link;
	}
	return begin;
}	 

void main()
{
	struct node *first,*second,*third,*fourth,*just;

	first=(struct node *)malloc(sizeof(struct node));
	second=(struct node *)malloc(sizeof(struct node));
	third=(struct node *)malloc(sizeof(struct node));
	fourth=(struct node *)malloc(sizeof(struct node));

	first->info=2;
	first->link=second;
		
	second->info=1;
	second->link=third;

	third->info=5;
	third->link=fourth;
	
	fourth->info=3;
	fourth->link=NULL;

	display(first);
	
	just=copy(first);
	printf("\nAfter COPY FUCTION:");
	display(just);
	
	printf("\nTotal Elements in LINKLIST %d",count(first));
	
	/*printf("\nAfter Insert:");
	first=insert(25,first);
	display(first);
	printf("\nInsert at END:");	
	first=insert_end(50,first);
	display(first);
	printf("\nInsert node in between:");
	first=insert_sort(35,first);
	display(first);
	
	
	first=delete(second,first);
	printf("\nAfter Deletion of second(2) node :");
	display(first);

	*/
	printf("\n Linked list before sorting ");
	display(first);

	
	Sort(first);

	printf("\n Linked list after sorting ");
	display(first);
	printf("\n------------------\n")

}
