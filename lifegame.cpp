#include <iostream>
#include <cstdlib>
using namespace std;

/**int counter(int plane[],int point[], int length)

{return alives;}**/

int main()
{
int filas, columnas;/// nvivas;
cout<<"introduce el numero de filas: ";cin>>filas;
columnas = filas;
int plane[filas][columnas];
/**all points are randomly 0 or 1**/
for(int i = 0; i<filas; i++){for(int k = 0; k<columnas; k++){plane[i][k] = rand() % 2;}}
int point[2];
cout<<endl;

for(int i = 0; i<filas; i++){
	for(int k = 0; k<filas; k++){
		point[0] = i; point[1] = k;
///counter(plane,point);
cout<<"point value in plane: "<<plane[point[0]][point[1]]<<" point coordenates: ["<<point[0]<<","<<point[1]<<"]"<<endl;
}}
}
