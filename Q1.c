#include <stdio.h>
int main()
{
FILE *pantryFp = fopen("items.txt", "w");
int codes[5] = {1, 2, 3, 4, 5};
char labels[5][21] = {"Rice", "Sugar", "Milk", "CookingOil", "Tea"};
float rates[5] = {250.00f, 160.00f, 220.00f, 560.00f, 450.00f};
int counts[5] = {40, 25, 30, 12, 18};
int k = 0;
int pickedNo = 0;
int askedQty = 0;
int recNo = 0;
char recLabel[21];
float recRate = 0.0f;
int recCount = 0;
float billSum = 0.0f;
float rowCost = 0.0f;
for (k = 0; k < 5; k++)
{
fprintf(pantryFp, "%-4d %-20s %9.2f %5d\n", codes[k], labels[k], rates[k], counts[k]);
}
fclose(pantryFp);
pantryFp = fopen("items.txt", "rb+");
while (1)
{
printf("Item no: ");
scanf("%d", &pickedNo);
if (pickedNo == 0)
{
break;
}
printf("Quantity: ");
scanf("%d", &askedQty);
fseek(pantryFp, (pickedNo - 1) * 42L, SEEK_SET);
fscanf(pantryFp, "%d %20s %f %d", &recNo, recLabel, &recRate, &recCount);
printf("%s\n", recLabel);
if (askedQty <= recCount)
{
rowCost = askedQty * recRate;
billSum += rowCost;
recCount -= askedQty;
printf("%d x %.2f = %.2f\n", askedQty, recRate, rowCost);
fseek(pantryFp, (pickedNo - 1) * 42L, SEEK_SET);
fprintf(pantryFp, "%-4d %-20s %9.2f %5d\n", recNo, recLabel, recRate, recCount);
fflush(pantryFp);
}
else
{
printf("Only %d %s in stock\n", recCount, recLabel);
}
}
printf("Total bill: %.2f\n", billSum);
fclose(pantryFp);
return 0;
}