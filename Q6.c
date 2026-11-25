#include <stdio.h>

void grow(int spanArr[], int leftLen)
{
if (leftLen == 0)
{
return;
}
grow(spanArr, leftLen - 1);
spanArr[leftLen - 1] += (int)(spanArr[leftLen - 1] * 0.10);
}

int tallest(int spanArr[], int leftLen)
{
int pickIdx = 0;
int earlierIdx = 0;
if (leftLen == 1)
{
return 0;
}
earlierIdx = tallest(spanArr, leftLen - 1);
if (spanArr[leftLen - 1] > spanArr[earlierIdx])
{
pickIdx = leftLen - 1;
}
else
{
pickIdx = earlierIdx;
}
return pickIdx;
}

int search(int spanArr[], int leftLen, int goalHeight)
{
int hitSlot = 0;
if (leftLen == 0)
{
return -1;
}
if (spanArr[leftLen - 1] == goalHeight)
{
return leftLen - 1;
}
hitSlot = search(spanArr, leftLen - 1, goalHeight);
return hitSlot;
}

int main()
{
int siteCodes[6] = {101, 102, 103, 104, 105, 106};
int spanArr[6] = {45, 120, 78, 200, 95, 150};
int loopPos = 0;
int maxPos = 0;
int askMeters = 0;
int foundPos = 0;
grow(spanArr, 6);
printf("New heights:");
for (loopPos = 0; loopPos < 6; loopPos++)
{
printf(" %d", spanArr[loopPos]);
}
printf("\n");
maxPos = tallest(spanArr, 6);
printf("Tallest: tower %d (%d m)\n", siteCodes[maxPos], spanArr[maxPos]);
printf("Height to search: ");
scanf("%d", &askMeters);
foundPos = search(spanArr, 6, askMeters);
if (foundPos != -1)
{
printf("Tower %d is %d m\n", siteCodes[foundPos], askMeters);
}
return 0;
}