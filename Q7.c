#include <stdio.h>

int finalBalance(int moveList[], int remCount, int cashNow)
{
if (remCount == 0)
{
return cashNow;
}
return finalBalance(moveList + 1, remCount - 1, cashNow + moveList[0]);
}

int totalDeposits(int moveList[], int remCount)
{
int plusChunk = 0;
if (remCount == 0)
{
return 0;
}
if (moveList[0] > 0)
{
plusChunk = moveList[0];
}
return plusChunk + totalDeposits(moveList + 1, remCount - 1);
}

int copyLarge(int moveList[], int atIdx, int remCount, int heavyOut[], int outPos)
{
if (atIdx == remCount)
{
return outPos;
}
if (moveList[atIdx] <= -10000)
{
heavyOut[outPos] = moveList[atIdx];
outPos++;
}
return copyLarge(moveList, atIdx + 1, remCount, heavyOut, outPos);
}

int main()
{
int startCash = 20000;
int moveList[7] = {20000, -5000, -12000, 8000, -25000, -2500, 15000};
int heavyOut[7];
int closingCash = 0;
int inSum = 0;
int heavyTotal = 0;
int m = 0;
closingCash = finalBalance(moveList, 7, startCash);
inSum = totalDeposits(moveList, 7);
heavyTotal = copyLarge(moveList, 0, 7, heavyOut, 0);
printf("Final balance: %d\n", closingCash);
printf("Total deposits: %d\n", inSum);
printf("Large withdrawals (%d):", heavyTotal);
for (m = 0; m < heavyTotal; m++)
{
printf(" %d", heavyOut[m]);
}
printf("\n");
return 0;
}