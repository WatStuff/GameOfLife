#include <iostream>
#include <unistd.h>
const int MAXx = 100;	///100x100 is the default size of the square
using namespace std;

void show(int plane[][MAXx], int length[])
{
	for(int i = 0; i<length[0]; i++)
	{
		for(int k = 0; k<length[1]; k++)
		{
			if(plane[i][k]==1){cout<<"1";}
			else {cout<<" ";}
			///cout<<plane[i][k];
		}
		cout<<endl;
	}
	for(int i = 0; i<length[0]; i++){cout<<"-";}
	cout<<endl;
}


void show_at_Conf(int plane[][MAXx], int length[])
{
        for(int i = 0; i<length[0]; i++)
        {
                for(int k = 0; k<length[1]; k++)
                {
                        if(plane[i][k]==1){cout<<"1\t";}
                        else {cout<<"["<<i<<","<<k<<"]\t";}
                    ///    cout<<plane[i][k];
                }
                cout<<endl;
        }
}



int counter(int plane[][MAXx],int point[],int length[])
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
	cout<<"Write the number of rows: ";cin>>filas;
	///cout<<"Write the number of columns: ";cin>>columnas;
	cout<<"Write the number of iterations: ";cin>>times;
	cout<<"The default time between each iteration is 1s"<<endl;
	columnas = filas;
	int length[2], point[2];
	length[0] = filas; length[1] = columnas;
	int plane[filas][MAXx];
	int plane1[filas][MAXx];
	char action;
	int coor[2];
	cout<<"Write the action followed by the coordenates."<<endl<<"Ex1: + 3 4\t(add [3,4])"<<endl<<"Ex2: - 3 4\t(remove [3,4])"<<endl<<"Ex3: /\t\t(to stop)"<<endl;
	for(int i = 0; i<filas; i++)
	{
		for(int k = 0; k<columnas; k++)
		{
			plane[i][k] = 0;
		}
	}

	show_at_Conf(plane,length);

	while(1==1)
	{
		cin>>action;
		if(action=='/'){break;}
		else
		{
			cin>>coor[0]>>coor[1];
			if(coor[0]<length[0] && coor[1]<length[1] && (action=='+' || action=='-'))
			{
				if(action=='+')
				{
					plane[coor[0]][coor[1]] = 1;
				}

				else if(action=='-')
				{
					plane[coor[0]][coor[1]] = 0;
				}
			}
			else
			{	if(action!='+' && action!='-'){cout<<"not valid action ("<<action<<"). Avaliable actions are: '+','-','/'"<<endl;}
				else {cout<<"the coordenates must be in the square"<<endl;}
			}
		show_at_Conf(plane,length);
		}
	}
	show(plane,length);
	///cout<<endl;
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
		sleep(1);
		show(plane,length);
		///cout<<endl;
	}
}

