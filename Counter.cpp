int counter(plane[][],columnas,filas){

	int alive=0;
		for(int j=0;j<columnas;j++){
			for(int k=0;k<filas;k++){
					if(plane[j][k]==1){
							for(int i=0;i<2;i++){
								if(plane[j+1][b+i]==1){alive++;}
								if(plane[j-1][b-i]==1){alive++;}
								if(plane[j+i][b+1]==1){alive++;}
								if(plane[j-i][b-1]==1){alive++;}
							}
						}
					}
				}

	return alive;
}
