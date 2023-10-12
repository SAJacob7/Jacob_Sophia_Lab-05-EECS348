#include <stdio.h>



void print_sales(float sales[], char month[12][20])
{
	printf("Monthly Sales Report for 2023 \n");
  printf("Month \t Sales \n");
  for(int i = 0; i<=11; i++) {
    printf("%-10s $%.2f \n", month[i], sales[i]);
  }
}
void sales_summary(float sales[], char month[12][20])

{
	printf("\nSales Summary\n");

	float minimum = sales[0] ;
	float maximum = sales[0];
	int iterate_min = 0;
	int iterate_max = 0;
	for (int i = 0; i <=11; i++){
		float num = sales[i];
		if (num < minimum) {
			minimum = num;
			iterate_min = i;
		}
		if (num > maximum) {
			maximum = num;
			iterate_max = i;
		}
	}
	float average;
	float sum = 0;
	for (int i = 0; i <=11; i++){
		float num = sales[i];
		sum = sum + num;
	}
	average = sum / 12;



	printf("Minimum Sales: $%.2f (%s)\n", minimum, month[iterate_min]);
	printf("Maximum Sales: $%.2f (%s)\n", maximum, month[iterate_max]);
	printf("Average: $%.2f \n", average);



}
void moving_average(float sales[], char month[12][20])
{
	printf("\nSix-Month Moving Average Report\n");
	for (int i =0; i <=11; i++){
		if (i+6<=12) {
			float average;
			float sum = 0;
			int iterate = i;
			for (int x = 0; x <= 5; x++) {
				float num = sales[iterate];
				sum = sum + num;
				iterate++;
			}
			average = sum / 6;
			printf("\n %s - %s $%.2f\n", month[i], month[i+5], average);
		}
	}
}

void sales_report(float sales[], char month[12][20])
{
	printf("\nSales Report Highest to Lowest\n");
	float salescopy[12];
	for (int i = 0; i <=11; i++) {
    salescopy[i] = sales[i];
	}
	for (int i = 0; i <=11; i++){
		for (int j = i+1; j <=11; j++) {
			if (sales[i] < sales[j]) {
				float num = sales[i];
				sales[i] = sales[j];
				sales[j] = num;


			}
		}
	}
	int index;
	printf("Month \t    Sales \n");
	for (int i = 0; i <=11; i++) {
		for (int j = 0; j <=11; j++){

			if (sales[i] == salescopy[j]) {
				index = j;
				break;

			}
		}
		printf("%-10s $%.2f\n", month[index], sales[i]);
	}
}

int main()
{
	float sales[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
  char month[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	print_sales(sales, month);
	sales_summary(sales, month);
	moving_average(sales, month);
	sales_report(sales, month);
	return (0);
}
