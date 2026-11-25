#include <stdio.h>
#include <string.h>

int countRepeat(char origStr[], int atPos)
{
if (origStr[atPos] == '\0')
{
return 0;
}
if (origStr[atPos + 1] == origStr[atPos])
{
return 1 + countRepeat(origStr, atPos + 1);
}
return 1;
}

void compress(char origStr[], int srcIdx, char zipStr[], int dstIdx)
{
int streakLen = 0;
if (origStr[srcIdx] == '\0')
{
zipStr[dstIdx] = '\0';
return;
}
streakLen = countRepeat(origStr, srcIdx);
zipStr[dstIdx] = origStr[srcIdx];
zipStr[dstIdx + 1] = (char)('0' + streakLen);
compress(origStr, srcIdx + streakLen, zipStr, dstIdx + 2);
}

void expand(char zipStr[], int zIdx, char fullStr[], int fIdx)
{
char glyphCh = '\0';
int copyTimes = 0;
int w = 0;
if (zipStr[zIdx] == '\0')
{
fullStr[fIdx] = '\0';
return;
}
glyphCh = zipStr[zIdx];
copyTimes = zipStr[zIdx + 1] - '0';
for (w = 0; w < copyTimes; w++)
{
fullStr[fIdx + w] = glyphCh;
}
expand(zipStr, zIdx + 2, fullStr, fIdx + copyTimes);
}

int main()
{
char origStr[100] = "AAAAAABBBCCCCD";
char zipStr[200];
char fullStr[200];
compress(origStr, 0, zipStr, 0);
expand(zipStr, 0, fullStr, 0);
printf("Original: %s\n", origStr);
printf("Compressed: %s\n", zipStr);
printf("Expanded: %s\n", fullStr);
if (strcmp(origStr, fullStr) == 0)
{
printf("Match: Yes\n");
}
else
{
printf("Match: No\n");
}
return 0;
}