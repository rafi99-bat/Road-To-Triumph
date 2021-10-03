#include "FileUtils.h"
#include "Menu.h"
#include "Book.h"
#include <stdlib.h>
#include<stdio.h>
#include<Windows.h>

extern Book book[5];
int count=0;
extern char playerName[30];
Info::Info()
{
	strcpy(name,"UserName");
	cgpa=0.0;
	totalMarks=0;
}
Info info[6];
void Save()
{
 int i;

  FILE *save;
  save=fopen("res/File/Save&Load.txt","w");

  if(save == NULL)
  {
	exit(1);
  }

 for(i=0;i<5;i++)
	{

	 fprintf(save,"%d %d %lf %lf ",book[i].score,book[i].count,book[i].speed,book[i].posY);

	}

 fclose(save);
}

 void Load()
 {
	FILE *load;
	load= fopen("res/File/Save&Load.txt","r");
	 
	 if(load == NULL)
  {
	exit(1);
  }
	for(int i=0;i<5;i++)
	{
	
	 fscanf(load,"%d %d %lf %lf",&book[i].score,&book[i].count,&book[i].speed,&book[i].posY);

	}
 fclose(load);
 }

 void loadScore()
 {
	FILE *score = fopen("res/File/Score.txt","r");
	if(score == NULL)
	{
		exit(1);
	}
	for(int i=0;i<5;i++)
	{
		fscanf(score,"%s %lf %d",&info[i].name,&info[i].cgpa,&info[i].totalMarks);		
	}
	fclose(score);
 }

 void saveScore()
 {
	strcpy(info[5].name,playerName);
	info[5].cgpa=((book[0].GPA + book[1].GPA + book[2].GPA + book[3].GPA + book[4].GPA)/5);
	info[5].totalMarks=book[0].score + book[1].score + book[2].score + book[3].score + book[4].score;
	double temp;
	char temp1[30];
	int temp2;

	FILE *score = fopen("res/File/Score.txt","r");

	if(score == NULL)
	{
		exit(1);
	}

	for(int i=0;i<5;i++)
	{
		fscanf(score,"%s %lf %d",&info[i].name,&info[i].cgpa,&info[i].totalMarks);		
	}
	fclose(score);


	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<6;j++)
		{
			if(info[j].cgpa > info[i].cgpa)
			{
				temp = info[i].cgpa;
				info[i].cgpa= info[j].cgpa;
				info[j].cgpa=temp;

				strcpy(temp1,info[i].name);
				strcpy(info[i].name,info[j].name);
				strcpy(info[j].name,temp1);

				temp2 = info[i].totalMarks;
				info[i].totalMarks= info[j].totalMarks;
				info[j].totalMarks=temp2;			

			}
			else if(info[i].cgpa==info[j].cgpa)
			{
				if(info[j].totalMarks > info[i].totalMarks)
				{
				temp = info[i].cgpa;
				info[i].cgpa= info[j].cgpa;
				info[j].cgpa=temp;

				strcpy(temp1,info[i].name);
				strcpy(info[i].name,info[j].name);
				strcpy(info[j].name,temp1);

				temp2 = info[i].totalMarks;
				info[i].totalMarks= info[j].totalMarks;
				info[j].totalMarks=temp2;
				}
			}
		}
	}

	FILE *score1 = fopen("res/File/Score.txt","w");

	for(int i=0;i<5;i++)
	{
		fprintf(score1,"%s %lf %d ",info[i].name,info[i].cgpa,info[i].totalMarks);
	}
	fclose(score1);
 }
