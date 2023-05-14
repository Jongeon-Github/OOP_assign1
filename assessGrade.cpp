/*
* Filename: assessGrade.cpp
* Project: OOP-assign1
* By: Jongeon Lee
* Date: May 20, 2023
* Description: This is prototype cpp file for assign1.cpp
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#pragma warning(disable: 4996)


void assessGrade(char* letterGrade)
{
    char grade[3];
    int len = strlen(letterGrade);

    if (len == 2 && letterGrade[1] == '+')
    {
        grade[0] = toupper(letterGrade[0]);
        grade[1] = '+';
        grade[2] = '\0';
    }
    else
    {
        grade[0] = toupper(letterGrade[0]);
        grade[1] = '\0';
    }

    switch (grade[0])
    {
    case 'A':
        if (grade[1] == '+')
        {
            printf("Student achieved 95.00 %% which is a PASS condition.\n");
        }
        else
        {
            printf("Student achieved 85.00 %% which is a PASS condition.\n");
        }
        break;
    case 'B':
        if (grade[1] == '+')
        {
            printf("Student achieved 77.00 %% which is a PASS condition.\n");
        }
        else
        {
            printf("Student achieved 72.00 %% which is a PASS condition.\n");
        }
        break;
    case 'C':
        if (grade[1] == '+')
        {
            printf("Student achieved 67.00 %% which is a PASS condition.\n");
        }
        else
        {
            printf("Student achieved 62.00 %% which is a PASS condition.\n");
        }
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
    case 'AU':
        printf("Student has Special Situation : AU (Audit Condition)\n");
        break;
    case 'DNA':
        printf("Student has Special Situation : DNA (Did Not Attend)\n");
        break;
    case 'I/P':
        printf("Student has Special Situation : I/P (In Process)\n");
        break;
    default:
        printf("��**ERROR : Invalid Input\n");
        break;
    }
}


void assessGrade(double doubleGrade)
{
    double passScore = 54.5;
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
        printf("��**ERROR : Invalid Input\n");
    }
}

void assessGrade(int arrGrade[5])
{
    double aveGrade = 0;
    double passScore = 54.5;

    for (int i = 0; i < 5; i++)
    {
        if (arrGrade[i] >= 0.0 || arrGrade[i] <= 100.0)
        {
            aveGrade += arrGrade[i];
        }
        else
        {
            printf("��**ERROR : Invalid Input\n");
            return;
        }
    }
    
    aveGrade = aveGrade / 5;

    if (aveGrade >= passScore)
    {
        printf("Student achieved %.2f %% which is a PASS condition.\n", aveGrade);
    }
    else
    {
        printf("Student achieved %.2f %% which is a FAIL condition.\n", aveGrade);
    }
}


void parseUserInput(char* input)
{
    int returnValue = 0;
    char* letterInput = NULL;
    double doubleInput = 0.0;
    double arrDoubleInput[5] = { 0.0 };
    int arrInputs[5] = { 0 };

    returnValue = sscanf(input, "%lf %lf %lf %lf %lf", &arrDoubleInput[0], &arrDoubleInput[1], &arrDoubleInput[2], &arrDoubleInput[3], &arrDoubleInput[4]);
    doubleInput = arrDoubleInput[0];

    if (returnValue == 0)
    {
        assessGrade(input);
    }
    else if(returnValue == 1)
    {
        assessGrade(doubleInput);
    }
    else if (returnValue >= 2 && returnValue <= 5)
    {
        for (int i = 0; i < 5; i++)
        {
            arrInputs[i] = (int)arrDoubleInput[i];
        }
        assessGrade(arrInputs);
    }



}

