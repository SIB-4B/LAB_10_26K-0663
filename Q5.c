#include <stdio.h>

int main()
{
FILE *spendFp = fopen("expenses.txt", "ab");
char headTag[13];
float rupeeAmt = 0.0f;
char nextTag[13];
float nextAmt = 0.0f;
int rowPick = 0;
float rightAmt = 0.0f;
float grandSum = 0.0f;
printf("Category: ");
scanf("%12s", headTag);
printf("Amount: ");
scanf("%f", &rupeeAmt);
fprintf(spendFp, "%-12s %9.2f\n", headTag, rupeeAmt);
fclose(spendFp);
spendFp = fopen("expenses.txt", "rb+");
fseek(spendFp, -2L * 23L, SEEK_END);
fscanf(spendFp, "%12s %f", headTag, &rupeeAmt);
fscanf(spendFp, "%12s %f", nextTag, &nextAmt);
printf("Latest two: %s %.2f, %s %.2f\n", headTag, rupeeAmt, nextTag, nextAmt);
printf("Entry to fix: ");
scanf("%d", &rowPick);
printf("Correct amount: ");
scanf("%f", &rightAmt);
fseek(spendFp, (rowPick - 1) * 23L, SEEK_SET);
fscanf(spendFp, "%12s %f", headTag, &rupeeAmt);
fseek(spendFp, (rowPick - 1) * 23L, SEEK_SET);
fprintf(spendFp, "%-12s %9.2f\n", headTag, rightAmt);
fflush(spendFp);
rewind(spendFp);
while (fscanf(spendFp, "%12s %f", headTag, &rupeeAmt) == 2)
{
printf("%s %.2f\n", headTag, rupeeAmt);
grandSum += rupeeAmt;
}
printf("Total: %.2f\n", grandSum);
fclose(spendFp);
return 0;
}