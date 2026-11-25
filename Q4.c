#include <stdio.h>
#include <string.h>

int main()
{
FILE *lodgeFp = fopen("hotel.txt", "w");
int doorNo = 0;
char markCode = 'F';
char visitorName[21];
int nightSpan = 0;
float dayTariff = 8000.00f;
int roomPick = 0;
char typedGuest[21];
int typedNights = 0;
char nameBook[10][21];
int doorBook[10];
int p = 0;
int matchedDoor = 0;
float stayBill = 0.0f;
for (p = 0; p < 10; p++)
{
doorNo = 101 + p;
fprintf(lodgeFp, "%3d %c%-20s %2d %8.2f\n", doorNo, 'F', "None", 0, dayTariff);
}
fclose(lodgeFp);
lodgeFp = fopen("hotel.txt", "rb+");
printf("Check-in room: ");
scanf("%d", &roomPick);
fseek(lodgeFp, (roomPick - 101) * 39L, SEEK_SET);
fscanf(lodgeFp, "%d %c%20s %d %f", &doorNo, &markCode, visitorName, &nightSpan, &dayTariff);
if (markCode == 'F')
{
printf("Name: ");
scanf("%20s", typedGuest);
printf("Nights: ");
scanf("%d", &typedNights);
fseek(lodgeFp, (roomPick - 101) * 39L, SEEK_SET);
fprintf(lodgeFp, "%3d %c%-20s %2d %8.2f\n", doorNo, 'B', typedGuest, typedNights, dayTariff);
fflush(lodgeFp);
printf("Room %d booked\n", doorNo);
}
else
{
printf("Room already booked\n");
}
rewind(lodgeFp);
for (p = 0; p < 10; p++)
{
fscanf(lodgeFp, "%d %c%20s %d %f", &doorBook[p], &markCode, nameBook[p], &nightSpan, &dayTariff);
}
printf("Search name: ");
scanf("%20s", typedGuest);
matchedDoor = 0;
for (p = 0; p < 10; p++)
{
if (strcmp(nameBook[p], typedGuest) == 0)
{
matchedDoor = doorBook[p];
}
}
if (matchedDoor != 0)
{
printf("%s is in room %d\n", typedGuest, matchedDoor);
}
printf("Check-out room: ");
scanf("%d", &roomPick);
fseek(lodgeFp, (roomPick - 101) * 39L, SEEK_SET);
fscanf(lodgeFp, "%d %c%20s %d %f", &doorNo, &markCode, visitorName, &nightSpan, &dayTariff);
stayBill = nightSpan * dayTariff;
printf("Bill: %d x %.2f = %.2f\n", nightSpan, dayTariff, stayBill);
fseek(lodgeFp, (roomPick - 101) * 39L, SEEK_SET);
fprintf(lodgeFp, "%3d %c%-20s %2d %8.2f\n", doorNo, 'F', "None", 0, dayTariff);
fflush(lodgeFp);
fclose(lodgeFp);
return 0;
}