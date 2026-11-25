#include <stdio.h>

void buildScores(int deltaArr[], int scoreArr[], int idx, int totalLen, int runningVal)
{
if (idx == totalLen)
{
return;
}
runningVal += deltaArr[idx];
scoreArr[idx] = runningVal;
buildScores(deltaArr, scoreArr, idx + 1, totalLen, runningVal);
}

int countLow(int scoreArr[], int totalLen)
{
int dipFlag = 0;
if (totalLen == 0)
{
return 0;
}
if (scoreArr[0] < 50)
{
dipFlag = 1;
}
return dipFlag + countLow(scoreArr + 1, totalLen - 1);
}

void reverse(int scoreArr[], int loIdx, int hiIdx)
{
int tempHold = 0;
if (loIdx >= hiIdx)
{
return;
}
tempHold = scoreArr[loIdx];
scoreArr[loIdx] = scoreArr[hiIdx];
scoreArr[hiIdx] = tempHold;
reverse(scoreArr, loIdx + 1, hiIdx - 1);
}

int main()
{
int initScore = 70;
int deltaArr[10] = {5, -8, -10, -12, 4, 6, 3, 7, -2, 5};
int scoreArr[10];
int lowDayNum = 0;
int q = 0;
buildScores(deltaArr, scoreArr, 0, 10, initScore);
lowDayNum = countLow(scoreArr, 10);
printf("Daily scores:");
for (q = 0; q < 10; q++)
{
printf(" %d", scoreArr[q]);
}
printf("\n");
printf("Days below 50: %d\n", lowDayNum);
reverse(scoreArr, 0, 9);
printf("Latest first:");
for (q = 0; q < 10; q++)
{
printf(" %d", scoreArr[q]);
}
printf("\n");
return 0;
}