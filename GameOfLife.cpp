#include <iostream>
#include <cstdlib>
const int MAX = 100;
using namespace std;


void show(int plane[][MAX], int length[])
{
	for(int i = 0; i<length[0]; i++)
	{
		for(int k = 0; k<length[1]; k++)
		{
			cout<<plane[i][k];
		}
		cout<<endl;
	}	
}



int counter(int plane[][MAX],int point[],int length[])
{
	int alive = 0;
	int a,b,filas,columnas;
	a = point[0]; b = point[1]; filas = length[0]; columnas = length[1];
	if(a>0)
	{
		if(b>0 && plane[a-1][b-1]==1){alive++;}
		if(plane[a-1][b]==1){alive++;}
		if(b+1<filas && plane[a-1][b+1]==1){alive++;}
	}
	if(b>0 && plane[a][b-1]){alive++;}
	if(b+1<filas && plane[a][b+1]){alive++;}
	if(a<columnas)
	{
		if(b>0 && plane[a+1][b-1]==1){alive++;}
		if(plane[a+1][b]==1){alive++;}
		if(b+1<filas && plane[a+1][b+1]==1){alive++;}
	}
	return alive;
}

int main()
{
	int filas, columnas,times;
	cout<<"introduce el numero de filas: ";cin>>filas;
	cout<<"introduce el numero de iteraciones: ";cin>>times;
	columnas = filas;
	int length[2], point[2];
	length[0] = filas; length[1] = columnas;
	int plane[filas][MAX];
	int plane1[filas][MAX];
	/**all points are randomly 0 or 1**/
	for(int i = 0; i<filas; i++)
	{
		for(int k = 0; k<columnas; k++)
		{
			plane[i][k] = rand() % 2;
		}
	}

	show(plane,length);
	cout<<endl;
	for(int iter = 0; iter<times; iter++)
	{
		for(int i = 0; i<filas; i++)
		{
			for(int k = 0; k<columnas; k++)
			{
				point[0] = i; point[1] = k;
				plane1[i][k] = plane[i][k];
				int sentence = counter(plane,point,length);
				if(plane[i][k]==1)
				{
					if (sentence!=2 && sentence!=3)
					{
						plane1[i][k] = 0;
					}
				}
				if(plane[i][k]==0)
				{
					if (sentence==3)
					{
						plane1[i][k] = 1;
					}	
				}
			}
		}
		for(int i = 0; i<filas; i++)
		{
			for(int k = 0; k<columnas; k++){plane[i][k] = plane1[i][k];}
		}
		show(plane,length);
		cout<<endl;
	}
}
