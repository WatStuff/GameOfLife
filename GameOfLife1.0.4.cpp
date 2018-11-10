#include <iostream>
#include <unistd.h>
#include <cstdlib>
const int MAXx = 100;	///100x100 is the default size of the square

char w[][90] ={
			{' ','_','_','_','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',    '_','_','_','_','_','_','_','_','_','_','_','_','_',' ',       ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
			{'|','\\',' ',' ',' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '  ,' ','\\',      ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
			{'|',' ','\\',' ',' ',' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','_','_','_','L','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',   ' ',' ','|',      ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
			{'|',' ',' ','\\',' ',' ',' ','\\',' ',' ',' ',' ',' ',' ','_',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ','W',' ','/','\\','_','_','_','_',' ',' ',' ',' ',' ',' ',  '_','_','_','/','_','_','_','_','_','_','_','_',' ',  ' ',    ' ','_','_','_','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
			{'|',' ',' ',' ','\\',' ',' ',' ','\\',' ',' ',' ',' ','/',' ','/','\\',' ',' ',' ',' ',' ',' ','/',' ','A',' ','/','\\','/',' ',' ',' ','|',' ','|',' ',' ',' ',     '|',' ',' ','/','_','/',' ','_','_','_','_','_',' ', '\\','/',' ','/',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
			{' ','\\',' ',' ',' ','\\',' ',' ',' ','\\',' ',' ','/',' ','/',' ',' ','\\',' ',' ',' ',' ','/',' ','T',' ','/','\\','/',' ','\\',' ',' ','|',' ','|',' ',' ',' ',   '|',' ',' ','|',' ','|','|',' ',' ',' ','|',' ','|',  '|',' ','/',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ','\\',' ',' ',' ','\\',' ',' ',' ','\\','/',' ','/',' ','/','\\',' ','\\',' ',' ','/',' ','0',' ','/','\\','/','\\',' ',' ','\\',' ','|',' ','|',' ',' ',' ', '|',' ',' ','|',' ','|','|',' ',' ',' ','|',' ','|',  '|','/',' ',' ','/','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ','\\',' ',' ',' ','\\',' ',' ',' ','\\','/',' ','/',' ',' ','\\',' ','\\','/',' ','1',' ','/','\\','/','\\',' ','\\',' ',' ','\\','|',' ','|',' ',' ',' ','|',' ',' ','|',' ','|','|',' ',' ',' ','|',' ','|',  '|','\\','_','/','|','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ','\\',' ',' ',' ','\\',' ',' ',' ',' ','/','\\',' ',' ',' ','\\',' ','\\',' ',' ','/','\\','/',' ',' ','\\',' ','\\',' ',' ','\\',' ','|',' ',' ',' ','|',' ',' ','|',' ','|','|',' ',' ',' ','|',' ','|',  '|',' ',' ',' ','|','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ',' ','\\',' ',' ',' ','\\',' ',' ','/',' ',' ','\\',' ',' ',' ','\\',' ','\\','/','\\','/','_','_','_','_','\\','_','\\',' ',' ','\\','|',' ',' ',' ','|',' ',' ','|','_','|','|','_','_','_','|','_','|',  '|','_','_','_','L','|',' ','L','_','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ',' ',' ','\\','_','_','_','\\','/',' ',' ',' ',' ','\\','_','_','_','\\','_','_','/','_','_','_','_','_','_','_','_','_','_','_','\\','_','_','_',    '|',' ',' ','\\','_','\\','_','_','_','_','_','_','_','/','|','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
			};
			
using namespace std;

bool board_comp(int board1[][MAXx], int board2[][MAXx],int length[])
{
	for(int i = 0;i<length[0];i++)
	{
		for(int k = 0; k<length[1];k++){if(board1[i][k]!=board2[i][k]){return false;}}
	}	
return true;	
}

bool extintion(int plane[][MAXx],int length[])
{
	for(int ii = 0; ii<length[0]; ii++)
	{
			for(int kk = 0; kk<length[1]; kk++)
			{
				if(plane[ii][kk]==1){return false;}
			}
	}
	return true;
}

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
	float time;
	cout<<"Write the number of rows: ";cin>>filas;
	///cout<<"Write the number of columns: ";cin>>columnas;
	cout<<"Write the time between each iteration: ";cin>>time;cout<<endl;
	columnas = filas;
	bool infinite = false;		///comment this line if you don't want to finish the programme when it gets into a one period loop.
	int length[2], point[2];
	length[0] = filas; length[1] = columnas;
	int plane[filas][MAXx];
	int plane1[filas][MAXx];
	char action;
	int coor[2];
	cout<<"Write the action followed by the coordenates."<<endl<<"Ex1: + 3 4\t(add [3,4])"<<endl<<"Ex2: - 3 4\t(remove [3,4])"<<endl<<"Ex3: % \t\t(add a random point)"<<endl<<"Ex4: /\t\t(to stop)"<<endl;
	for(int i = 0; i<filas; i++)
	{
		for(int k = 0; k<columnas; k++)
		{
			plane[i][k] = 0;
		}
	}

	show_at_Conf(plane,length);


	cin>>action;
	while(action!='/')
	{
			if(action=='%')
			{
				coor[0] = rand()%filas;
				coor[1] = rand()%columnas;
				plane[coor[0]][coor[1]] = 1;
			}
			else if(action=='+')
			{
				cin>>coor[0]>>coor[1];
				if(coor[0]<filas && coor[1]<columnas)
				{
					plane[coor[0]][coor[1]] = 1;
				}
				else{cout<<"the coordenates must be in the square"<<endl;}
			}
			else if(action=='-')
			{
				cin>>coor[0]>>coor[1];
				if(coor[0]<filas && coor[1]<columnas)
				{
					plane[coor[0]][coor[1]] = 0;
				}
				else{cout<<"the coordenates must be in the square"<<endl;}
			}
			else{cout<<"not valid action ("<<action<<"). Avaliable actions are: '+','-','%','/'"<<endl;}

			show_at_Conf(plane,length);
			cin>>action;
	}
	show(plane,length);

	///for(int iter = 0; iter<times; iter++)
	while(extintion(plane,length)==false)
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
		if(board_comp(plane,plane1,length)==true && infinite==false)
		{	usleep(time*1000000);
			show(plane,length);
			cout<<"Broken loop because of a period-1 layout"<<endl<<endl;
			break;
		}
		for(int i = 0; i<filas; i++)
		{
			for(int k = 0; k<columnas; k++){plane[i][k] = plane1[i][k];}
		}
		///sleep(1);
		usleep(time*1000000);
		show(plane,length);
		
		///cout<<endl;
	
	}
	cout<<"Developed by:"<<endl<<endl<<endl;
	for(int i = 0; i<11; i++){for(int k = 0; k<90;k++){cout<<w[i][k];}cout<<endl;}
	cout<<endl<<endl<<"more at:"<<endl<<"https://github.com/WatStuff"<<endl<<"https://github.com/Wat01"<<endl; 
}
