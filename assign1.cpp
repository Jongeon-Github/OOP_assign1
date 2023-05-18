/*
* Filename: assign1.cpp 
* Project: OOP-assign1
* By: Jongeon Lee
* Date: May 20, 2023
* Description: Write a program that determines the pass or fail of the course.
* Returns 
*    0: Code complete.
*   -1: The user enters the incorrect input.
*   -2: The user enters the 'x' or 'X' for exiting the program.
*   -3: The file is not open.
*   -4: The opened file is not closed.
*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assessGrade.h"

#pragma warning(disable:4996)
#pragma warning(disable:6031) // It ignores warning for sscanf return value. I don`t need a return value for sscanf.

#define MAX_CHARACTER_LEN 100
#define MAX_DATA_LEN 80
#define MAXSPACE 4
#define MAXINPUT 5


//Prototypes
void parseUserInput(char* input);

int main(void)
{
    const int kArr = 5;
    int i = 0; // counter
    int arrInputs[kArr] = { 0 };
    char grade[MAX_CHARACTER_LEN] = "0";
    char fileName[MAX_CHARACTER_LEN] = "\0";
    char* userInput = NULL;
    double doubleInput = 0.0;

    printf("Enter Student¡¯s Grade(s) >>> ");

    if (fgets(grade, MAX_CHARACTER_LEN, stdin) == NULL)
    {
        printf("**ERROR : Invalid Input\n");
        return -1;
    }

    grade[strlen(grade) - 1] = '\0';

    if (grade[0] == 'x' || grade[0] == 'X')
    {
        return -2;
    }
    else if ((grade[0] == 'z' || grade[0] == 'Z'))
    {
        sscanf(grade, "%*s %s", fileName);
        strcpy(grade, fileName);

        FILE* fp = NULL;
        fp = fopen(fileName, "r");

        if (fp == NULL)
        {
            printf("**ERROR : Can't open the file\n");
            return -3;
        }

        char data[MAX_DATA_LEN] = { '\0' };
        char* pLinePos = NULL;
        
        while (fgets(data, MAX_DATA_LEN, fp))
        {
            pLinePos = strchr(data, '\n');

            if (pLinePos != NULL)
            {
                *pLinePos = '\0';
            }

            parseUserInput(data);

        }
        if (fclose(fp) != NULL)
        {
            printf("**ERROR : Can't close the file opened\n");
            return -4;
        }
    }
    else
    {
        parseUserInput(grade);
    }
	return 0;
}


/*
* Function: parseUserInput(char* input)
* Description: This function will parse the user input and help the assessGrade() function to work.
* Parameter: char* input: User input
* Return Value: nothing
*/

void parseUserInput(char* input)
{
    const int kArr = 5;
    char fileName[MAX_CHARACTER_LEN] = "\0";
    int arrInputs[kArr] = { 0 };
    int returnValue = 0;
    double arrDoubleInput[kArr] = { 0.0 };
    double doubleInput = 0.0;

    returnValue = sscanf(input, "%lf %lf %lf %lf %lf", &arrDoubleInput[0], &arrDoubleInput[1], &arrDoubleInput[2], &arrDoubleInput[3], &arrDoubleInput[4]);
    doubleInput = arrDoubleInput[0];

    if (returnValue == 0)
    {
        assessGrade(input);
    }
    else if (returnValue == 1)
    {
        assessGrade(doubleInput);
    }
    else if (returnValue >= 2 && returnValue <= 5)
    {
        if (strchr(input, '.') != NULL)
        {
            printf("**ERROR : Invalid Input\n");
            return;
        }
        for (int i = 0; i < kArr; i++)
        {
            arrInputs[i] = (int)arrDoubleInput[i];
        }
        assessGrade(arrInputs);
    }
}