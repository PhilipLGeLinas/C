#include "Employees.h"

int main()
{
	FILE *payroll = fopen("payroll.txt", "r");
	FILE *paid = fopen("paid.txt", "w");
	Employee employees[200] = { 0 };
	char last_name[100] = "", first_name[100] = "";

	int count = 0;
	while (!feof(payroll))
	{
		fscanf(payroll, "%s", &last_name);
		fscanf(payroll, "%s", &first_name);
		strcat(last_name, " ");
		strcpy(employees[count].name, strcat(last_name, first_name));
		fscanf(payroll, " %c", &employees[count].title);
		fscanf(payroll, "%lf", &employees[count].hours_worked);
		fscanf(payroll, "%lf", &employees[count].payrate);
		count++;
	}

	printf("BEFORE:\n\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", employees[i].name);
		printf("%c\n", employees[i].title);
		printf("%lf\n", employees[i].hours_worked);
		printf("%lf\n", employees[i].payrate);
		printf("%lf\n", employees[i].payment);
	}

	double total = 0.0, average = 0.0, max = 0.0, min = 99999.0;
	for (int i = 0; i < count; i++)
	{
		switch (employees[i].title)
		{
			case 'B':
				employees[i].payment = (employees[i].hours_worked > 80.0) ? ((employees[i].hours_worked - 80.0) * employees[i].payrate * 1.5) + (80 * employees[i].payrate) : ((employees[i].hours_worked) * employees[i].payrate);
				break;
			case 'M':
				employees[i].payment = (employees[i].hours_worked > 80.0) ? ((employees[i].hours_worked - 80.0) * employees[i].payrate * 1.8) + (80 * employees[i].payrate) : ((employees[i].hours_worked) * employees[i].payrate);
				break;
		}
		total += employees[i].payment;
		if (employees[i].payment > max)
			max = employees[i].payment;
		if (employees[i].payment < min)
			min = employees[i].payment;
	}
	average = total / (double) count;

	printf("\nAFTER:\n\n");
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", employees[i].name);
		printf("%c\n", employees[i].title);
		printf("%lf\n", employees[i].hours_worked);
		printf("%lf\n", employees[i].payrate);
		printf("%lf\n", employees[i].payment);
	}

	fprintf(paid, "%.2lf\n", total);
	fprintf(paid, "%.2lf\n", average);
	fprintf(paid, "%.2lf\n", max);
	fprintf(paid, "%.2lf\n", min);

	fclose(payroll);
	fclose(paid);
	return 0;
}