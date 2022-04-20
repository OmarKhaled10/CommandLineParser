/*
 * test2.c
 *
 *  Created on: Mar 29, 2021
 *      Author: Omar
 */

#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

void print (int a_size, char* arr[]);
void reverse (int a_size, char* arr[]);
void upper (int a_size, char* arr[]);
void shuffle_word (char * s);
void shuffle_statement (int a_size, char* arr[]);
void delete_fn (int a_size, char* arr[]);
void middle (int a_size, char* arr[]);
void add (int a_size, char* arr[]);
void random (int a_size, char* arr[]);

int main (int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Incorrect Number of Arguments";
		return 0;
	}
	if(! strcmp(argv[1], "print"))
	{
		if (argc < 3)
		{
			cout << "Incorrect Number of Arguments";
			return 0;
		}
		print( argc, argv);
	}
	else if (! strcmp(argv[1], "reverse"))
	{
		if (argc < 3)
		{
			cout << "Incorrect Number of Arguments";
			return 0;
		}
		reverse( argc, argv);
	}
	else if (! strcmp(argv[1], "upper"))
	{
		if (argc < 3)
		{
			cout << "Incorrect Number of Arguments";
			return 0;
		}
		upper( argc, argv);
	}
	else if (! strcmp(argv[1], "shuffle"))
	{
		if (argc !=3)
		{
			cout << "Incorrect Number of Arguments";
			return 0;
		}
		shuffle_word (argv[2]);
	}
	else if (! strcmp(argv[1], "shuffleStatement"))
	{
		if (argc < 3)
		{
			cout << "Incorrect Number of Arguments";
			return 0;
		}
		shuffle_statement ( argc, argv);
	}
	else if (! strcmp(argv[1], "delete"))
	{
		if (argc < 3)
		{
			cout << "Incorrect Number of Arguments";
			return 0;
		}
		if (argv[2][0]==48)
		{
			cout << "Incorrect Data Type";
			return 0;
		}
		for (int j=0; j< strlen(argv[2]);j++)
		{
			if (!((argv[2][j]>=48) && (argv[2][j]<=57) ))
			{
				cout << "Incorrect Data Type";
				return 0;
			}
		}

		int x=0;
		for (int i =(strlen(argv[2])-1); i>=0 ; i--)
		{
			x+=(argv[2][i]-48)*pow(10,strlen(argv[2])-1-i);
		}

		if (argc < (x+3))
		{
			cout << "Incorrect Number of Arguments";
			return 0;
		}
		delete_fn ( argc, argv);
	}
	else if (! strcmp(argv[1], "middle"))
	{
		if (argc < 3)
		{
			cout << "Incorrect Number of Arguments";
			return 0;
		}
		middle ( argc, argv);
	}
	else if (! strcmp(argv[1], "add"))
	{
		if (argc < 3)
		{
			cout << "Incorrect Number of Arguments";
			return 0;
		}
		for (int i= 2;i<argc ; i++)
		{
			for (int j=0; j< strlen(argv[i]);j++)
			{
				if (!((argv[i][j]>=48) && (argv[i][j]<=57) || (argv[i][0]==45) ))
				{
					cout << "Incorrect Data Type";
					return 0;
				}
			}
		}
		add ( argc, argv);
	}
	else if (! strcmp(argv[1], "random"))
	{
		if (argc != 6)
		{
			cout << "Incorrect Number of Arguments";
			return 0;
		}
		if (argv[2][0]==48)
		{
			cout << "Incorrect Data Type";
			return 0;
		}
		for (int i= 2;i<argc ; i++)
		{
			for (int j=0; j< strlen(argv[i]);j++)
			{
				if (!((argv[i][j]>=48) && (argv[i][j]<=57) ))
				{
					cout << "Incorrect Data Type";
					return 0;
				}
			}
		}
		random ( argc, argv);
	}
	else
	{
		cout << "Undefined Command";
	}

	return 0;
}

void print (int a_size, char* arr[])
{
	for (int i =2 ; i< a_size; i++)
	{
		cout << arr[i] << " ";
	}
}

void reverse (int a_size, char* arr[])
{
	for (int i =a_size-1 ; i> 1; i--)
	{
		cout << arr[i] << " ";
	}
}

void upper (int a_size, char* arr[])
{
	for (int i =2 ; i< a_size; i++)
	{
		for (int j=0; j<strlen(arr[i]);j++)
		{
			if ((arr[i][j]>=97) && (arr[i][j]<=122) )
			{
				arr[i][j]-=32;
			}
		}
	}
	for (int i =2 ; i< a_size; i++)
	{
		cout << arr[i] << " ";
	}
}

void shuffle_word (char *s)
{

	for (int i=0 ; i<(strlen(s)-1) ; i+=2)
	{
		cout << s[i+1];
		cout << s[i];
	}
	if (strlen(s) % 2 == 1)
	{
		cout << s[strlen(s)-1];
	}
}

void shuffle_statement (int a_size, char* arr[])
{

	for (int i=2 ; i<a_size-1 ; i+=2)
	{
		cout << arr[i+1] << " ";
		cout << arr[i]<< " " ;
	}
	if (a_size % 2 == 1)
	{
		cout << arr[a_size-1];
	}
}

void delete_fn (int a_size, char* arr[])
{
	int num =arr[2][0]-48;
	for (int i =3;i<num+2;i++)
	{
		cout << arr[i] << " ";
	}
	for (int i =num+3;i<a_size;i++)
	{
		cout << arr[i] << " ";
	}

}

void middle (int a_size, char* arr[])
{
	if ((a_size%2) ==0)
	{
		cout << arr[a_size/2]<< " ";
		cout << arr[(a_size/2)+1];
	}
	else
	{
		cout << arr[(a_size/2)+1];
	}
}

void add (int a_size, char* arr[])
{
	int s=0;
	int x=0;
	for (int i=2 ; i <a_size ; i++)
	{
		if (arr[i][0]==45)
		{
			for (int j =(strlen(arr[i])-1); j>0 ; j--)
			{
				x+=(arr[i][j]-48)*pow(10,strlen(arr[i])-1-j);
			}
			x=-x;
		}
		else
		{
			for (int j =(strlen(arr[i])-1); j>=0 ; j--)
			{
				x+=(arr[i][j]-48)*pow(10,strlen(arr[i])-1-j);
			}
		}
		s+=x;
		x=0;
	}
	cout << s;
}

void random (int a_size, char* arr[])
{
	int seed=0;
	for (int i =(strlen(arr[5])-1); i>=0 ; i--)
	{
		seed+=(arr[5][i]-48)*pow(10,strlen(arr[5])-1-i);
	}
	int rand_number=0;
	for (int i =(strlen(arr[2])-1); i>=0 ; i--)
	{
		rand_number+=(arr[2][i]-48)*pow(10,strlen(arr[2])-1-i);
	}
	int min=0;
	for (int i =(strlen(arr[3])-1); i>=0 ; i--)
	{
		min+=(arr[3][0]-48)*pow(10,strlen(arr[3])-1-i);
	}
	int max=0;
	for (int i =(strlen(arr[4])-1); i>=0 ; i--)
	{
		max+=(arr[4][i]-48)*pow(10,strlen(arr[4])-1-i);
	}
	srand(seed);
	for (int i =0;i<rand_number;i++)
	{
		cout << ((rand ()+min)%max)<< " ";
	}
}

