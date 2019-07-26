
//  Age calculator in c programming This program run and input present date and birth date then you will get your legal age

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>

COORD coord = {0, 0};
COORD max_res, cursor_size;

int TEST_ITEM(char DATE)
{
    int return_date;

    if (DATE == '0')    return_date = 0;
    else if (DATE == '1')   return_date = 1;
    else if (DATE == '2')   return_date = 2;
    else if (DATE == '3')   return_date = 3;
    else if (DATE == '4')   return_date = 4;
    else if (DATE == '5')   return_date = 5;
    else if (DATE == '6')   return_date = 6;
    else if (DATE == '7')   return_date = 7;
    else if (DATE == '8')   return_date = 8;
    else if (DATE == '9')   return_date = 9;

    return return_date;
}

int main()
{
    int     Date, Month, Year, n, i;
    int     date1, date2, date3, month1, month11, month2, month3, year1, year2, year3;


    year1 = buffer_year();
    month1 = buffer_month();
    date1 = buffer_date();

    printf("\n\t\t\xde"); design(223, 38);
    printf("\xdd\n\t\t\xde                                      ");
    printf("\xdd\n\t\t\xde   You Should Enter Your Birth Date   \xdd\n\t\t\xde                                      ");
    printf("\xdd\n\t\t\xde"); design(220, 38); printf("\xdd");




    printf("\n\n\n     ");
    printf("\n\n\n\t\t #  Year (Less than %d) : \n\t\t #  Month (0-12)          : \n\t\t #  Date (0-31)           : ", year1);


    gotoxy(4, 7);
    for(i=1; i<=67; i++) {
        printf("\xb1");
        Sleep(15);
    }

    for(i=7; i<=17; i++) {
        gotoxy(4, i); printf("\xb1"); gotoxy(70, i); printf("\xb1");
        Sleep(20);
    }

    gotoxy(4, 18);
    for(i=1; i<=67; i++) {
        printf("\xb1");
        Sleep(15);
    }

    gotoxy(45, 11);
    scanf("%d", &year2);
    if(year2>year1) {

        gotoxy(20, 18);
        printf("\n\n\tInvalid Year and year must be less then %d\n\n\tPress 1 for continue exit otherwise : ", year1);
        afterDateChecking();
    }

    gotoxy(45, 12);
    scanf("%d", &month2);

    if((month2>12) || ((year1 == year2) && (month2 > month1))){
        gotoxy(20, 18);
        printf("\n\n\tInvalid Month and month must be less then %d\n\n\tPress 1 for continue exit otherwise : ", month1+1);
        afterDateChecking();
    }

    gotoxy(45, 13);
    scanf("%d", &date2);

    if((year1 == year2) && (month2 == month1) && ((date2 > date1))){
        gotoxy(20, 18);
        printf("\n\n\tInvalid Date and date must be less then %d\n\n\tPress 1 for continue exit otherwise : ", month1+1);
        afterDateChecking();
    }
    system("cls");






    if(date1 >= date2) {
        date3 = date1 - date2;

        if(month1 >= month2) {
            month3 = month1 - month2;
            year3 = year1 - year2;
        }
        else {
            month3 = month1 + 12 - month2;
            year3 = year1 - year2 - 1;
        }
    }
    else {
        date3 = date1 + 30 - date2;

        month11 = month1 - 1;

        if(month11 >= month2) {
            month3 = month11 - month2;
            year3 = year1 -year2;
        } else {
            month3 = month11 + 12 - month2;
            year3 = year1 - year2 - 1;
        }
    }

    system("cls");
    if (year3 < 0) {
        printf("\n\n\tYou are not born yet. \n\n\tIf you want to input your age press 1");
        scanf("%d", &n);
        if(n==1) { system("cls");   main();}
        else { system("cls"); printf("\n\tExit the program.\n\n"); getch();    exit(0);
        }
    }

        printf("\n\n\n\n\n\t\tPresent  Date  ==>\t");
        if(date1<10)    printf("0");
        printf("%d - ", date1);
        if(month1<10)    printf("0");
        printf("%d - ", month1);
        if(year1<10)    printf("0");
        printf("%d", year1);

        printf("\n\t\tBirth    Date  ==>\t");
        if(date2<10)    printf("0");
        printf("%d - ", date2);
        if(month2<10)    printf("0");
        printf("%d - ", month2);
        if(year2<10)    printf("0");
        printf("%d", year2);

        printf("\n\n\t   YOUR  Legal Age  is  %d years %d months and %d days.", year3, month3, date3);

        gotoxy(4, 3);
        for(i=1; i<=67; i++) {
            printf("\xb1");
            Sleep(15);
        }

        for(i=4; i<=12; i++) {
            gotoxy(4, i); printf("\xb1"); gotoxy(70, i); printf("\xb1");
            Sleep(20);
        }

        gotoxy(4, 12);
        for(i=1; i<=67; i++) {
            printf("\xb1");
            Sleep(15);
        }



       // gotoxy(21, 10);
        printf("\n\n\n\t\t\xde"); design(223, 38);
        printf("\xdd\n\t\t\xde                                      ");
        printf("\xdd\n\t\t\xde          Developed by AKASH          \xdd\n\t\t\xde                                      ");
        printf("\xdd\n\t\t\xde"); design(220, 38); printf("\xdd");

    //getchar();

    printf("\n\n\tPress 1 for continue or exit otherwise: ");
    scanf("%d", &n);
    if (n==1) {
        system("cls");
        main();
    }

}

void afterDateChecking() {
    int n;
    scanf("%d", &n);
    if(n==1) {
        system("cls");
        main();
    } else {
        system("cls");
        printf("\n\tProgram will be exit after five (5) seconds   ");
        Sleep(5000);
        exit(0);
    }
}
int buffer_date()
{
    int ret_buff_date;
    time_t date;
    struct tm *show;
    char buffer[80];

    time( &date );
    show = localtime(&date);
    strftime(buffer, 80, "%d", show);

    ret_buff_date = TEST_ITEM(buffer[0])*10 + TEST_ITEM(buffer[1]);

    return ret_buff_date;
}

int buffer_month()
{
    int ret_buff_month;
    time_t date;
    struct tm *show;
    char buffer[80];

    time(&date);
    show = localtime( &date );
    strftime(buffer,80,"%m", show);

    ret_buff_month = TEST_ITEM(buffer[0])*10 + TEST_ITEM(buffer[1]);
    return ret_buff_month;
}

int buffer_year()
{
    int ret_buff_year;
    time_t date;
    struct tm *show;
    char buffer[80];

    time( &date );
    show = localtime( &date );
    strftime(buffer,80,"%Y", show);

    ret_buff_year = TEST_ITEM(buffer[0])*1000 + TEST_ITEM(buffer[1])*100 + TEST_ITEM(buffer[2])*10 + TEST_ITEM(buffer[3]);
    return ret_buff_year;
}


/*   #################################### COORD FUNCTIONS ################################  */
void design(int d, int n){
    while(n!=0) {
        if(d==222)
            printf("\xde");
        else if(d==223)
            printf("\xdf");
        else if(d==220)
            printf("\xdc");
        else if(d==176)
            printf("\xb0");
        else if(d==177)
            printf("\xb1");
        n--;
    }
}

void gotoxy (int x, int y) {
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
