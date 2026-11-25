#include <stdio.h>

int main()
{
FILE *sheetFp = fopen("attendance.txt", "w");
int rollNums[5] = {1, 2, 3, 4, 5};
char learnerNames[5][16] = {"Ayesha", "Bilal", "Hamza", "Sana", "Zainab"};
int presentCount[5] = {18, 14, 20, 12, 16};
int step = 0;
int checkRoll = 0;
int fileRoll = 0;
char fileName[16];
int filePresent = 0;
float ratioPct = 0.0f;
int slipRoll = 0;
int slipDays = 0;
for (step = 0; step < 5; step++)
{
fprintf(sheetFp, "%-3d %-15s %3d\n", rollNums[step], learnerNames[step], presentCount[step]);
}
fclose(sheetFp);
sheetFp = fopen("attendance.txt", "rb+");
printf("Roll number: ");
scanf("%d", &checkRoll);
fseek(sheetFp, (checkRoll - 1) * 24L, SEEK_SET);
fscanf(sheetFp, "%d %15s %d", &fileRoll, fileName, &filePresent);
ratioPct = (filePresent / 20.0f) * 100.0f;
printf("%s: %d/20 (%.1f%%)", fileName, filePresent, ratioPct);
if (ratioPct < 75.0f)
{
printf(" Short attendance");
}
printf("\n");
printf("Roll number for leave: ");
scanf("%d", &slipRoll);
printf("Lectures: ");
scanf("%d", &slipDays);
fseek(sheetFp, (slipRoll - 1) * 24L, SEEK_SET);
fscanf(sheetFp, "%d %15s %d", &fileRoll, fileName, &filePresent);
filePresent += slipDays;
ratioPct = (filePresent / 20.0f) * 100.0f;
fseek(sheetFp, (slipRoll - 1) * 24L, SEEK_SET);
fprintf(sheetFp, "%-3d %-15s %3d\n", fileRoll, fileName, filePresent);
fflush(sheetFp);
printf("%s: now %d / 20 (%.1f%%)\n", fileName, filePresent, ratioPct);
fseek(sheetFp, -24L, SEEK_END);
fscanf(sheetFp, "%d %15s %d", &fileRoll, fileName, &filePresent);
printf("Last record: %d %s %d\n", fileRoll, fileName, filePresent);
fclose(sheetFp);
return 0;
}