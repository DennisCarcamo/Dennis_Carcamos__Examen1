#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
void inicializarmatris(char** ,int );
char** crearmatriz();
void imprimematris(char** ,int);
int conteoespacios(char** , int);
int  distancia(int ,int , int , int  );
void comermas(char**,int  ,int );
void comechar(char**,int  ,int );
void liberarmemoria(char** , int );
int totalcharr(char** ,int );
int totalmass(char** , int );


void moverpieza();
int main(int argc, char const *argv[]){
	int size=7;
	char** matris=crearmatriz();
	inicializarmatris(matris,size);
	cout<<"///Las coordenadas se ingresan dos numeros de 0 a 6 ///"<<endl;
	cout<<""<<endl;
	imprimematris(matris,size);
	
	bool turn=false;
	while((conteoespacios(matris,size))!=0){
		int piezaselectedi ,piezaselectedj ,moveri ,moverj ;
		if (!turn){
			cout<<""<<endl;
			cout<<"Ingrese las coordenadas de la pieza '+' a mover"<<endl;	
			cin>>piezaselectedi;
			cin>>piezaselectedj;
			cout<<"Ingrese las coordenadas a donde mover"<<endl;	
			cin>>moveri;
			cin>>moverj;

			//validando que las coordenadas sean validas
			if (matris[piezaselectedi][piezaselectedj]=='+'){
				if ((moveri<size && moverj<size)){
					if (matris[moveri][moverj]=='.'){
						if ((distancia(piezaselectedi ,piezaselectedj ,moveri ,moverj))==1) {
							matris[moveri][moverj]='+'; 
							comermas(matris, moveri,moverj);
							if (   conteoespacios(matris,size)==0 || totalmass(matris,size)==49   ){
								break;
							}else{
								turn=true;
							}
							
						}else{
							matris[moveri][moverj]='+';
							matris[piezaselectedi][piezaselectedj]='.';
							comermas(matris, moveri,moverj);
							if (conteoespacios(matris,size)==0  ||  totalmass(matris,size)==49){
								break;
							}else{
								turn=true;
							}
							
						}
						 
						 imprimematris(matris,size);
					
					}
					
					
				}else{
					cout<<"se sale  del rango permitido vuelva a intentarlo"<<endl;
				}
			}else{
				cout<<"No existe pieza en ese lugar vuelva a intentarlo"<<endl;
			}

			



		}else if(turn){
			cout<<""<<endl;
			cout<<"Ingrese las coordenadas de la pieza '#' a mover"<<endl;	
			cin>>piezaselectedi;
			cin>>piezaselectedj;
			cout<<"Ingrese las coordenadas a donde mover"<<endl;	
			cin>>moveri;
			cin>>moverj;

			//validando que las coordenadas sean validas
			if (matris[piezaselectedi][piezaselectedj]=='#'){
				if ((moveri<size && moverj<size)){
					if (matris[moveri][moverj]=='.'){
						if ((distancia(piezaselectedi ,piezaselectedj ,moveri ,moverj))==1) {
							matris[moveri][moverj]='#'; 
							comechar(matris, moveri,moverj);
							if (conteoespacios(matris,size)==0 || totalcharr(matris,size)==49){
								break;
							}else{
								turn=false;
							}
							
						}else{
							matris[moveri][moverj]='#';
							matris[piezaselectedi][piezaselectedj]='.';
							comechar(matris, moveri,moverj);
							if (conteoespacios(matris,size)==0 || totalcharr(matris,size)==49){
								break;
							}else{
								turn=false;
							}
							
						}
						
						imprimematris(matris,size);
					}
					
					
				}else{
					cout<<"se sale  del rango permitido vuelva a intentarlo"<<endl;
				}
			}else{
				cout<<"No existe una pieza suya en este lugar"<<endl;
		
		}

 	}


int totalmas=totalmass(matris,size),totalchar=totalcharr(matris,size);
if (totalmas>totalchar){
	cout<<"Gano el jugador de piezas '+' "<<endl;
}else if (totalchar>totalmas){
	cout<<"Gano el jugador de piezas '#' "<<endl;
}else {
	cout<<"Hay un Empate";
}
}
liberarmemoria(matris,size);



	return 0;

}////esta llave me frego parte del codigo no estoy seguro donde hiba

void liberarmemoria(char** matris, int size){
	for (int i = 0; i < size; ++i){
		delete [] matris[i];
	}

	
	delete [] matris;
}

int totalcharr(char** matris, int  size){
	int suma=0;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (matris[i][j]=='#'){
				suma++;
			}
		}
	}

	return suma;
}

int totalmass(char** matris, int size){
	int suma=0;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (matris[i][j]=='+'){
				suma++;
			}
		}
	}

	return suma;
}

void comermas(char** matris,int moveri,int moverj){
	//x+1
	if (    ((moveri+1)>=0) &&  ((moveri+1)<=6)  && ((moverj+1)>=0) && ((moverj+1)<=6)   ){
		if (matris[moveri+1][moverj+1]=='#'){
			matris[moveri+1][moverj+1]='+';
		}
	}

	if (    ((moveri+1)>=0) &&  ((moveri+1)<=6)  && ((moverj)>=0) && ((moverj)<=6)   ){
		if (matris[moveri+1][moverj]=='#'){
			matris[moveri+1][moverj]='+';
		}
	}

	if (    ((moveri+1)>=0) &&  ((moveri+1)<=6)  && ((moverj-1)>=0) && ((moverj-1)<=6)   ){
		if (matris[moveri+1][moverj-1]=='#'){
			matris[moveri+1][moverj-1]='+';
		}
	}

	//x
	if (    ((moveri)>=0) &&  ((moveri)<=6)  && ((moverj+1)>=0) && ((moverj+1)<=6)   ){
		if (matris[moveri][moverj+1]=='#'){
			matris[moveri][moverj+1]='+';
		}
	}

	if (    ((moveri)>=0) &&  ((moveri)<=6)  && ((moverj-1)>=0) && ((moverj-1)<=6)   ){
		if (matris[moveri][moverj-1]=='#'){
			matris[moveri][moverj-1]='+';
		}
	}

	//x-1

	if (    ((moveri-1)>=0) &&  ((moveri-1)<=6)  && ((moverj+1)>=0) && ((moverj+1)<=6)   ){
		if (matris[moveri-1][moverj+1]=='#'){
			matris[moveri-1][moverj+1]='+';
		}
	}

	if (    ((moveri-1)>=0) &&  ((moveri-1)<=6)  && ((moverj)>=0) && ((moverj)<=6)   ){
		if (matris[moveri-1][moverj]=='#'){
			matris[moveri-1][moverj]='+';
		}
	}

	if (    ((moveri-1)>=0) &&  ((moveri-1)<=6)  && ((moverj-1)>=0) && ((moverj-1)<=6)   ){
		if (matris[moveri-1][moverj-1]=='#'){
			matris[moveri-1][moverj-1]='+';
		}
	}







	 	
}

void comechar(char** matris,int moveri,int moverj){
	//x+1
	if (    ((moveri+1)>=0) &&  ((moveri+1)<=6)  && ((moverj+1)>=0) && ((moverj+1)<=6)   ){
		if (matris[moveri+1][moverj+1]=='+'){
			matris[moveri+1][moverj+1]='#';
		}
	}

	if (    ((moveri+1)>=0) &&  ((moveri+1)<=6)  && ((moverj)>=0) && ((moverj)<=6)   ){
		if (matris[moveri+1][moverj]=='+'){
			matris[moveri+1][moverj]='#';
		}
	}

	if (    ((moveri+1)>=0) &&  ((moveri+1)<=6)  && ((moverj-1)>=0) && ((moverj-1)<=6)   ){
		if (matris[moveri+1][moverj-1]=='+'){
			matris[moveri+1][moverj-1]='#';
		}
	}

	//x
	if (    ((moveri)>=0) &&  ((moveri)<=6)  && ((moverj+1)>=0) && ((moverj+1)<=6)   ){
		if (matris[moveri][moverj+1]=='+'){
			matris[moveri][moverj+1]='#';
		}
	}

	if (    ((moveri)>=0) &&  ((moveri)<=6)  && ((moverj-1)>=0) && ((moverj-1)<=6)   ){
		if (matris[moveri][moverj-1]=='+'){
			matris[moveri][moverj-1]='#';
		}
	}

	//x-1

	if (    ((moveri-1)>=0) &&  ((moveri-1)<=6)  && ((moverj+1)>=0) && ((moverj+1)<=6)   ){
		if (matris[moveri-1][moverj+1]=='+'){
			matris[moveri-1][moverj+1]='#';
		}
	}

	if (    ((moveri-1)>=0) &&  ((moveri-1)<=6)  && ((moverj)>=0) && ((moverj)<=6)   ){
		if (matris[moveri-1][moverj]=='+'){
			matris[moveri-1][moverj]='#';
		}
	}

	if (    ((moveri-1)>=0) &&  ((moveri-1)<=6)  && ((moverj-1)>=0) && ((moverj-1)<=6)   ){
		if (matris[moveri-1][moverj-1]=='+'){
			matris[moveri-1][moverj-1]='#';
		}
	}

		
}

int distancia(int x1,int y1, int x2 ,int y2){
	int r1,r2,dis;
	r1=pow((x2-x1),2.0);
	r2-=pow((y2-y1),2.0);
	dis=sqrt(r1-r2);
	return dis;

}


char** crearmatriz(){
 	int size=7;
	char** matris=new char* [size];
	for(int i=0;i<=size; i++){
		matris[i]=new char [size];	
	}
	return matris;

}


void inicializarmatris(char** matris,int size){
	for (int i = 0; i <= size; i++){
		for (int j = 0; j <= size; j++) {
			matris[i][j]='.';
		}
		
	}

	matris[0][3]='+';
	matris[3][0]='#';
	matris[3][6]='#';
	matris[6][3]='+';

}

void imprimematris(char** matris,int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout<<" "<<matris[i][j]<<" ";
		}
		cout<<""<<endl;
	}
}

int conteoespacios(char** matris, int size){
	int suma=0;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (matris[i][j]=='.'){
				suma++;
			}
		}
	}

	return suma;
}