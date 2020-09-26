#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#define size 3

using namespace std;


char matrix[size][size];

int main()
{
    system("cls");
	char p1[20],p2[20],s1,s2;
	int player=1,c=1,boxno;
	void display();
	void update();
	cout<<"Enter the player names\nPlayer 1:";
	gets(p1);
	cout<<"\nPlayer 2:";
	gets(p2);
	cout<<"Choose your symbol(x/o)\nPlayer 1: ";
	cin>>s1;
	if(s1=='x'||s1=='X')
	{
		s2='o';
		cout<<"\nPlayer 2: o\n";
	}
	else if(s1=='o'||s1=='O')
	{
		s2='x';
		cout<<"\nPlayer 2: x";
	}
	else
		cout<<"Invalid choice";

	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			matrix[i][j]=('0'+c);
			c++;
		}
	}

	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<"Enter the box no\n";
			cin>>boxno;
		}
	display();
	}

	return 0;
}

void display(void)
{
    system("cls");
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

