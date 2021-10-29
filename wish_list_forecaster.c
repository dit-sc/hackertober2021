#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

#define MAX_ITEM 10

int main(void)
{
	const double min_income = 500.00;
	const double max_income = 400000.00;
	const double min_itemcost = 100.00;
	int done, wishlistitem, importance[MAX_ITEM], i;
	double monthlyincome, itemcost[MAX_ITEM], total_cost;
	char yes_no[MAX_ITEM];


	printf("+-------------------------+\n");
	printf("+   Wish List Forecaster  |\n");
	printf("+-------------------------+\n");

	do
	{
		printf("\nEnter the monthly NET income: $");
		scanf("%lf", &monthlyincome);


		if (monthlyincome < min_income)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
			done = 0;
		}
		else if (monthlyincome > max_income)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value of no more than $400000.00\n");
			done = 0;
		}
		else if (monthlyincome >= min_income && monthlyincome <= max_income)
		{
			done = 1;
		}

	} while (done == 0);

	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &wishlistitem);

		if (wishlistitem < 1)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
			done = 0;
		}
		else if (wishlistitem > MAX_ITEM)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
			done = 0;
		}
		else if (wishlistitem >= 1 && wishlistitem <= MAX_ITEM)
		{
			done = 1;
		}
	} while (done == 0);

	printf("\n");

	for (i = 0; i < wishlistitem; i++)
	{

		do
		{
			printf("Item-");
			printf("%d", i + 1);
			printf(" Details:\n");
			printf("   Item cost: $");
			scanf("%lf", &itemcost[i]);

			if (itemcost[i] < min_itemcost)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
				done = 0;
			}
			else
			{
				done = 1;
			}
		} while (done == 0);

		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &importance[i]);

			if (importance[i] < 1 || importance[i] > 3)
			{
				printf("      ERROR: Value must be between 1 and 3");
				done = 0;
			}
			else if (importance[i] >= 1 && importance[i] <= 3)
			{
				done = 1;
			}
		} while (done == 0);


		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf("\n%c", &yes_no[i]);
			printf("\n");

			if (yes_no[i] != 'y' && yes_no[i] != 'n')
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'");
				done = 0;
			}
			else
			{
				done = 1;
			}

		} while (done == 0);

	}

	printf("\n");
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (i = 0; i < wishlistitem; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, importance[i], yes_no[i], itemcost[i]);
		total_cost += itemcost[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total_cost);
	printf("Best of luck in all your future endeavours!");

	return 0;
}
