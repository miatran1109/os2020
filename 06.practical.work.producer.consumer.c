#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 10

typedef struct product
{
	char type;  // 0=fried chicken, 1=French fries
	int amount; // pieces or weight
	char unit;  // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void initChicken(item *smt) {
	smt->type = 0;
	smt->amount = 0;
	smt->unit = 0;
}

void initFries(item *smt) {
    smt->type = 1;
    smt->amount = 0;
    smt->unit = 1;
}

void produce(item *i)
{
	while ((first + 1) % BUFFER_SIZE == last)
	{
		printf("No free buffer item!\n");
		return;
	}
	memcpy(&buffer[first], i, sizeof(item));
	i->amount += 1;
	first = (first + 1) % BUFFER_SIZE;
	printf("First = %d\n", first);
}

item *consume()
{
	item *i = malloc(sizeof(item));
	while (first == last)
	{
		printf("Nothing to consume!\n");
	}
	memcpy(i, &buffer[last], sizeof(item));
	i->amount -= 1;
	last = (last + 1) % BUFFER_SIZE;
	printf("Last = %d\n", last);
	return i;
}

int main(){
    int opt = 0;
	item *chicken, fried, *french, fries;
	chicken = &fried;
	french = &fries;
	printf("Enter 1 or 2 to order\n");
	printf("Fried chiken: 1 or French fries: 2 \n");
   
	while (true)
	{
		 scanf("%d", &opt);
		if (opt== 1)
		{
			printf("2 fried chicken coming right up!\n");
			initChicken(chicken);
			produce(chicken);
			produce(chicken);
			printf("Consuming...\n");
			chicken = consume();
			break;
		}
		else if (opt == 2)
		{
			printf("2 French Fries coming right up!\n");
			initFries(french);
			produce(french);
			produce(french);
			printf("Consuming...\n");
			french = consume();
			break;
		}
		else
		{
			printf("There is just 2 options. TvT \n");
			printf("Fried Chiken: 1 or French fries: 2\n");
		}
	}
	return 0;
}