#include <stdio.h>
#include <string.h>

int main()
{
FILE *gaugeFp = fopen("temperature.txt", "w");
char placeWord[11];
float degVal = 0.0f;
int idx = 0;
int slotPick = 0;
int editSlot = 0;
float freshDeg = 0.0f;
char warmPlace[11];
float topDeg = -999.0f;
int firstPass = 1;
for (idx = 0; idx < 5; idx++)
{
scanf("%10s %f", placeWord, &degVal);
fprintf(gaugeFp, "%-10s %5.1f\n", placeWord, degVal);
}
fclose(gaugeFp);
gaugeFp = fopen("temperature.txt", "rb+");
printf("City number: ");
scanf("%d", &slotPick);
fseek(gaugeFp, (slotPick - 1) * 17L, SEEK_SET);
fscanf(gaugeFp, "%10s %f", placeWord, &degVal);
printf("%s %.1f\n", placeWord, degVal);
printf("City number to correct: ");
scanf("%d", &editSlot);
printf("New temperature: ");
scanf("%f", &freshDeg);
fseek(gaugeFp, (editSlot - 1) * 17L, SEEK_SET);
fscanf(gaugeFp, "%10s %f", placeWord, &degVal);
fseek(gaugeFp, (editSlot - 1) * 17L, SEEK_SET);
fprintf(gaugeFp, "%-10s %5.1f\n", placeWord, freshDeg);
fflush(gaugeFp);
printf("%s updated to %.1f\n", placeWord, freshDeg);
rewind(gaugeFp);
while (fscanf(gaugeFp, "%10s %f", placeWord, &degVal) == 2)
{
if (firstPass || degVal > topDeg)
{
topDeg = degVal;
strcpy(warmPlace, placeWord);
firstPass = 0;
}
}
printf("Hottest city: %s (%.1f)\n", warmPlace, topDeg);
fclose(gaugeFp);
return 0;
}