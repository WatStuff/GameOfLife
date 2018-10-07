int counter(int plane[][],int point[], int length){
	filas = length[0]; columnas = length[1];
	int alive=0;
		for(int j=0;j<columnas;j++){
			for(int k=0;k<filas;k++){
					if(plane[j][k]==1){
							for(int i=0;i<2;i++){
								if(plane[j+1][k+i]==1){alive++;}
								if(plane[j-1][k-i]==1){alive++;}
								if(plane[j+i][k+1]==1){alive++;}
								if(plane[j-i][k-1]==1){alive++;}
							}
						}
					}
				}

	return alive;
}
