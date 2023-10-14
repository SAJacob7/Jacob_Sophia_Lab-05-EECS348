#include <stdio.h>



void print_sales(float sales[], char month[12][20]) // Takes in the sales and month.
{
	printf("Monthly Sales Report for 2023: \n");
	printf("\n%-10s %-10s\n", "Month", "Sales");
  for(int i = 0; i<=11; i++) { // Goes through each sale item, and prints the month and sale corresponding to it.
    printf("%-10s $%-10.2f \n", month[i], sales[i]);
  }
}

void sales_summary(float sales[], char month[12][20]) // Takes in the sales and month.

{
	printf("\nSales Summary\n");

	float minimum = sales[0]; // Makes the minimum the first element of sales.
	float maximum = sales[0]; // Makes the maximum the first element of sales.
	int iterate_min = 0; // These two variables help track which index the min and max are at to find which month the min/max is in.
	int iterate_max = 0;
	for (int i = 0; i <=11; i++){ // Iterates through the whole sales array.
		float num = sales[i]; // Makes a variable to compare the sales at i to the minimum/maximum.
		if (num < minimum) { // If this number at i is less than the current min, then it is the new min.
			minimum = num;
			iterate_min = i; // This is the new index where the new minimum is.
		}
		if (num > maximum) { // If this number at i is greater than the current max, then it is the new max.
			maximum = num;
			iterate_max = i; // This is the new index where the new maximum is.
		}
	}
	float average; // Make average and sum variables.
	float sum = 0;
	for (int i = 0; i <=11; i++){ // Iterates through the whole sales array.
		float num = sales[i];
		sum = sum + num; // Keeps adding each number to the sum to get the full sum of sales.
	}
	average = sum / 12; // Divide the sum by 12 months to get average.



	printf("Minimum Sales: $%-10.2f (%s)\n", minimum, month[iterate_min]); // Prints minimum and finds month by seeing what index min is at, and finds corresponding month to it.
	printf("Maximum Sales: $%-10.2f (%s)\n", maximum, month[iterate_max]); // Prints maximum and finds month by seeing what index min is at, and finds corresponding month to it.
	printf("Average Sales: $%-10.2f \n", average); // Average is printed.



}
void moving_average(float sales[], char month[12][20]) // Takes in the sales and month.
{
	printf("\nSix-Month Moving Average Report\n");
	for (int i =0; i <=11; i++){ // Iterates through the whole sales array.
		if (i+6<=12) { // Need 6 month moving average so there should be 6 months after the current month i is on. There is a total of 12 months.
			float average; // Creates average and sum variables.
			float sum = 0;
			int iterate = i; // This variable keeps track of what index month is on.
			for (int x = 0; x <= 5; x++) {
				float num = sales[iterate]; // Num is the variable of sales at the index.
				sum = sum + num; // Keeps adding each number to the sum to get the full sum of sales from the month iterate is on to 6 months after this month.
				iterate++; // Iterate is moved up one to add the next sales number at iterate.
			}
			average = sum / 6; // Since it is a 6 month average, divide sum by 6.
			printf("\n%-10s - %-10s $%.2f\n", month[i], month[i+5], average); // Print the month to month plus the 6 months and the average.
		}
	}
}

void sales_report(float sales[], char month[12][20]) // Takes in the sales and month.
{
	printf("\nSales Report Highest to Lowest\n");
	float salescopy[12]; // Copy of sales array.
	for (int i = 0; i <=11; i++) {
    salescopy[i] = sales[i]; // Copies each sales element into salescopy in original order.
	}
	for (int i = 0; i <=11; i++){ // Iterates through sales array.
		for (int j = i+1; j <=11; j++) { // Iterates through sales array, but starting at the next element from where i is on to compare.
			if (sales[i] < sales[j]) { // We need highest to lowest order, so if the current sales element is less than the next element, they need to be swapped.
				float num = sales[i]; // Store original sales at i.
				sales[i] = sales[j]; // Swap the 2 elements.
				sales[j] = num; // Make the j element become the original sales at i.


			}
		}
	}
	int index;
	printf("%-10s %-10s\n", "Month", "Sales");
	for (int i = 0; i <=11; i++) { // This part of the code is to find the corresponding month for this new order.
		for (int j = 0; j <=11; j++){

			if (sales[i] == salescopy[j]) { // Compares where the new order of sales is equal to the old order of sales. The old order corresponds with the months, so we need to find what index contains the element from the new order.
				index = j; // When they are equal, we know that this is the corresponding number to the month.
				break; // We found the index so no need to continue the loop.

			}
		}
		printf("%-10s $%-10.2f\n", month[index], sales[i]); // Prints the month corresponding to the sales in highest to lowest order.
	}
}



int main()
{
	float sales[12]; // Creates an array of sales one for each month.
	char month[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; // Makes char array of the months.
	for (int i=0; i<=11; i++){ // Iterates through 12 times for each month.
		float sale; // Sale variable made.
		printf("Enter the Sale of Month %s: ", month[i]); // Asks for user input for each sale.
		scanf("%f", &sale);
		sales[i] = sale; // Makes sale at that index become the input the user wants.
		
	}
	//float sales[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22}; // Makes float array of sales.
	print_sales(sales, month); // Calls to print_sales function.
	sales_summary(sales, month); // Calls to sales_summary function.
	moving_average(sales, month); // Calls to moving_average function.
	sales_report(sales, month); // Calls to sales_report function.
	return (0);
}
