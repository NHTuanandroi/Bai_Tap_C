#include"stdio.h"
#include"stdint.h"

typedef struct DDate 
{
  /* data */
  int Day;
  int month;
  int Year;
}DateMonthYear ;

//-------------------Initialization Function-----------------
int Check_Month(DateMonthYear D1);
int DayOfYear(DateMonthYear D2);
int Total_Day_To_Input_Month(DateMonthYear D3);
void Date_Of_Week(int d);
//----------------------------------------------------------

int main()
{
    int Total_day = 0, count_date;

    DateMonthYear Input_Date;
    Input_Date.Day = 28;
    Input_Date.month = 3;
    Input_Date.Year = 2023; 
  // ================= Inalize day =================//
    Total_day =  DayOfYear(Input_Date)+ Total_Day_To_Input_Month(Input_Date) + Input_Date.Day - 1;
    printf("Total day:%d ",Total_day);

    count_date = (Total_day%7);
    printf("\nToday is: ");
    Date_Of_Week(count_date);
  
}


//------------------------- Define function---------------------------

int Check_Month(DateMonthYear D1){
    switch (D1.month)
    {
        case 1:
        case 3:
        case 5:
        case 6:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 7:
        case 9:
        case 11:
            return 30;
        case 2:
        if ((D1.Year % 4 == 0 && D1.Year % 100 != 0) || D1.Year % 400 == 0)
            return 29;
        else
            return 28;
        default:
        printf("InValid Number\n");
        break;
    }
 }

int DayOfYear(DateMonthYear D2) // total day from year 1 to input year
{
  int Total = 0;
  for(int i = 1; i < D2.Year; i++)
  {
    if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) // check leap year
    {
      /* code */
      Total = Total + 366;
    }
    else{
      Total = Total+ 365;
    } 
  }
  return Total;

}

int Total_Day_To_Input_Month(DateMonthYear D3)
{
  int total_day = 0;
  for(int i = 1; i< D3.month; i++){
    total_day = total_day + Check_Month(D3);
  }

}

void Date_Of_Week(int d){
   switch (d)
    {
    case 0:
        printf("Monday");
        break;
    case 1:
        printf("Tuesday");
        break;
    case 2:
        printf("Wednesday");
        break;
    case 3:
        printf("Thursday");
        break;
    case 4:
        printf("Friday");
        break;
    case 5:
        printf("Saturday");
        break;
    case 6:
        printf("Sunday");
        break;
    default:
        printf("Invalid");
        break;
    }
}