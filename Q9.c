#include <stdio.h>

int markZone(char chartGrid[][5], int rPos, int cPos, char patchMark)
{
int cellSum = 0;
if (rPos < 0 || rPos >= 5 || cPos < 0 || cPos >= 5)
{
return 0;
}
if (chartGrid[rPos][cPos] != '*')
{
return 0;
}
chartGrid[rPos][cPos] = patchMark;
cellSum = 1;
cellSum += markZone(chartGrid, rPos - 1, cPos, patchMark);
cellSum += markZone(chartGrid, rPos + 1, cPos, patchMark);
cellSum += markZone(chartGrid, rPos, cPos - 1, patchMark);
cellSum += markZone(chartGrid, rPos, cPos + 1, patchMark);
return cellSum;
}

int main()
{
float tempGrid[5][5] = {
{2.1f, -1.5f, -2.0f, 3.0f, 4.2f},
{1.8f, -0.5f, 2.5f, 3.1f, -1.0f},
{3.3f, 2.0f, 1.5f, -0.8f, -2.2f},
{-1.2f, 3.4f, 4.0f, 3.8f, -0.6f},
{-2.5f, -3.1f, 5.1f, 6.0f, 4.7f}
};
char chartGrid[5][5];
char alphaLetter = 'A';
int patchTotal = 0;
int rowI = 0;
int colJ = 0;
int areaSize = 0;
for (rowI = 0; rowI < 5; rowI++)
{
for (colJ = 0; colJ < 5; colJ++)
{
if (tempGrid[rowI][colJ] < 0.0f)
{
chartGrid[rowI][colJ] = '*';
}
else
{
chartGrid[rowI][colJ] = '.';
}
}
}
for (rowI = 0; rowI < 5; rowI++)
{
for (colJ = 0; colJ < 5; colJ++)
{
if (chartGrid[rowI][colJ] == '*')
{
areaSize = markZone(chartGrid, rowI, colJ, alphaLetter);
printf("Zone %c: %d stations\n", alphaLetter, areaSize);
alphaLetter++;
patchTotal++;
}
}
}
printf("Total zones: %d\n", patchTotal);
for (rowI = 0; rowI < 5; rowI++)
{
for (colJ = 0; colJ < 5; colJ++)
{
printf("%c ", chartGrid[rowI][colJ]);
}
printf("\n");
}
return 0;
}