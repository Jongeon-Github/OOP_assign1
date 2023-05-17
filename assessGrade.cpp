/*
* Filename: assessGrade.cpp
* Project: OOP-assign1
* By: Jongeon Lee
* Date: May 20, 2023
* Description: This is prototype cpp files for assign1.cpp
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "assessGrade.h"


/*
* Function: void assessGrade(const char* letterGrade)
* Description: This function will show the user a grade.
* Parameter: const char* letterGrade: user input letter
* Return Value: nothing
*/

void assessGrade(const char* letterGrade)
{
    const int kCharMax = 80;
    char grade[kCharMax] = { 0 };
    int len = strlen(letterGrade);

    if (len == 1)
    {
        grade[0] = toupper(letterGrade[0]);
        grade[1] = '\0';
    }
    else if (len == 2 && letterGrade[1] == '+')
    {
        grade[0] = toupper(letterGrade[0]);
        grade[1] = '+';
        grade[2] = '\0';
    }
    else if (len == 3)
    {
        grade[0] = toupper(letterGrade[0]);
        grade[1] = toupper(letterGrade[1]);
        grade[2] = toupper(letterGrade[2]);
        grade[3] = '\0';
    }

    if (len == 1)
    {
        switch (grade[0])
        {
        case 'A':
            printf("Student achieved 85.00 %% which is a PASS condition.\n");
            break;
        case 'B':
            printf("Student achieved 72.00 %% which is a PASS condition.\n");
            break;
        case 'C':
            printf("Student achieved 62.00 %% which is a PASS condition.\n");
            break;
        case 'D':
            printf("Student achieved 57.00 %% which is a PASS condition.\n");
            break;
        case 'F':
            printf("Student achieved 50.00 %% which is a FAIL condition.\n");
            break;
        case 'I':
            printf("Student has Special Situation : I (Incomplete)\n");
            break;
        case 'Q':
            printf("Student has Special Situation : Q (Withdrawal After Drop/Refund Date)\n");
            break;
        default:
            printf("¡°**ERROR : Invalid Input\n");
            break;
        }
    }
    else if (len == 2)
    {
        switch (grade[0])
        {
        case 'A':
            if (grade[1] == 'U')
            {
                printf("Student has Special Situation : AU (Audit Condition)\n");
                break;
            }
            else if (grade[1] == '+')
            {
                printf("Student achieved 95.00 %% which is a PASS condition.\n");
                break;
            }
            else
            {
                printf("¡°**ERROR : Invalid Input\n");
                break;
            }
        case 'B':
            if (grade[1] == '+')
            {
                printf("Student achieved 77.00 %% which is a PASS condition.\n");
                break;
            }
            else
            {
                printf("¡°**ERROR : Invalid Input\n");
                break;
            }
        case 'C':
            if (grade[1] == '+')
            {
                printf("Student achieved 67.00 %% which is a PASS condition.\n");
                break;
            }
            else
            {
                printf("¡°**ERROR : Invalid Input\n");
                break;
            }
        default:
            printf("¡°**ERROR : Invalid Input\n");
            break;
        }
    }
    else if (len == 3)
    {
        switch (grade[0])
        {
        case 'D':
            if (grade[1] == 'N' && grade[2] == 'A')
            printf("Student has Special Situation : DNA (Did Not Attend)\n");
            break;
        case 'I':
            if (grade[1] == '/' && grade[2] == 'P')
            printf("Student has Special Situation : I/P (In Process)\n");
            break;
        default:
            printf("¡°**ERROR : Invalid Input\n");
            break;
        }

    }
    else if (len >= 4)
    {
        printf("¡°**ERROR : Invalid Input\n");
    }
}


/*
* Function: void assessGrade(double doubleGrade)
* Description: This function will show the user a grade.
* Parameter: double doubleGrade: User input number
* Return Value: nothing
*/

void assessGrade(double doubleGrade)
{
    const double passScore = 54.5;

    if (doubleGrade >= 0.0 && doubleGrade <= 100.0)
    {
        if (doubleGrade >= passScore)
        {
            printf("Student achieved %.2f %% which is a PASS condition.\n", doubleGrade);
        }
        else
        {
            printf("Student achieved %.2f %% which is a FAIL condition.\n", doubleGrade);
        }
    }
    else
    {
        printf("¡°**ERROR : Invalid Input\n");
    }
}


/*
* Function: void assessGrade(int arrGrade[])
* Description: This function will show the user a grade.
* Parameter: int arrGrade: User input numbers by an array.
* Return Value: nothing
*/

void assessGrade(int arrGrade[])
{
    const double kArrConout = 5.0;
    const double kPassScore = 54.5;
    const double kPassScoreMin = 0.0;
    const double kPassScoreMax = 100.0;
    double aveGrade = 0;

    for (int i = 0; i < kArrConout; i++)
    {
        if (arrGrade[i] >= kPassScoreMin && arrGrade[i] <= kPassScoreMax)
        {
            aveGrade += arrGrade[i];
        }
        else
        {
            printf("¡°**ERROR : Invalid Input\n");
            return;
        }
    }
    
    aveGrade = aveGrade / kArrConout;

    if (aveGrade >= kPassScore)
    {
        printf("Student achieved %.2f %% which is a PASS condition.\n", aveGrade);
    }
    else
    {
        printf("Student achieved %.2f %% which is a FAIL condition.\n", aveGrade);
    }
}
