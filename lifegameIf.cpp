#include <iostream>
#include <cstdlib>
using namespace std;

int counter(int plane[][],int point[],int length[])
{
	int alive = 0;
	int a,b,filas,columnas;
	a = point[0]; b = point[1]; filas = length[0]; columnas = length[1];
	if(a<0)
	{
		if(b>0 && plane[a-1][b-1]==1){alive++;}
		if(plane[a-1][b]==1){alive++;}
		if(b<filas && plane[a-1][b+1]==1){alive++;}	
	}
	if(b>0 && plane[a][b-1]){alive++;}
	if(b<filas && plane[a][b+1]){alive++;}
	if(a<columnas)
	{
		if(b>0 && plane[a+1][b-1]==1){alive++;}
		if(plane[a+1][b]==1){alive++;}
		if(b<filas && plane[a+1][b+1]==1){alive++;}
	}
	return alive;
}

int main()
{
	int filas, columnas;
	cout<<"introduce el numero de filas: ";cin>>filas;
	columnas = filas;
	int length[2], point[2];
	length[0] = filas; length[1] = columnas;
	int plane[filas][columnas];
	/**all points are randomly 0 or 1**/
	for(int i = 0; i<filas; i++)
	{
		for(int k = 0; k<columnas; k++)
		{
			plane[i][k] = rand() % 2;
		}
	}
	for(int i = 0; i<filas; i++)
	{
		for(int k = 0; k<filas; k++)
		{
			point[0] = i; point[1] = k;
			cout<<"point value in plane: "<<plane[i][k]<<" point coordenates: ["<<point[0]<<","<<point[1]<<"]"<<endl;
			int sentence = counter(plane,point,length);
			if(plane[i][k]==1)
			{
				if (sentence!=2 && sentence!=3)
				{
					plane[i][k] = 0;
				}
				if (sentence==3)
				{
					plane[i][k] = 1;
				}
			}
		}
	}
	cout<<"matriz de "<<length[0]<<"x"<<length[1];
}
