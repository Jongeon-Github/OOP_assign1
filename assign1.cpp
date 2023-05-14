/*
* Filename: assign1.cpp 
* Project: OOP-assign1
* By: Jongeon Lee
* Date: May 20, 2023
* Description: Write a program that determines the pass or fail of the course.
*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assessGrade.h"

#define MAXCHARACTER 100
#define MAXSPACE 4
#define MAXINPUT 5


int main(void)
{
	int i = 0; // counter
	char grade[MAXCHARACTER] = "0";
	int arrSpace[MAXSPACE-1] = { 0 };
	char* pos;

	printf("Enter Student¡¯s Grade(s) >>> ");

	fgets(grade, MAXCHARACTER, stdin);
	grade[strlen(grade) - 1] = '\0';
	pos = strchr(grade, ' ');
	while (pos !=NULL)
	{
		arrSpace[i] = pos - grade + 1;
		pos = strchr(pos + 1, ' ');
		i++;
	}

	parseUserInput(grade);








	return 0;
}