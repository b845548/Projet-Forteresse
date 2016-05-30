///////////////////////////////////////////////////////////////////////////////////////////
//                                                                                       //
//                  Universite Paris 8 Departement informatique			  	 //
//                              Langage Imperatif                                        //
//                                                                                       //
//  Nom :BAE										 //
//  Prenom : Hobean 									 //
//  N'etudiant : 14500464								 //
//  Nom : Kim										 //
//  Premnom : Kyung Taek								 //
//  N'etudiant : 14503236								 //
//											 //
//  Projet : Forteresse									 //
//  Enseignant : Jean-Jacques Bourdin 							 //
//  Date de presentation : 13/05/2015							 //
//  Date de correction : 16/05/2015							 //
//  Spec:										 //
//        Version corrigée, demandé par l'ameilioration de programme precedent 		 //
//        Sans commentaire car ce fichier se presentera avec le documment d'explication. //
//											 //
//  Les programations à faire :								 //
//											 //
// (realisé) 1.Faire un programme qui permet de jouer, à deux, à ce jeu. Attention, 	 //
//         	  l'esthétique est secondaire, une série de "printf" suffira.		 //
// (realisé) 2.Ajouter à ce programme le jeu par l'ordinateur. 				 //
// (realisé) 3.Étudier et définir des stratégies de gain.				 //
// (realisé) 4.Faire que l'on puisse jouer contre l'ordinateur,                          //
//             mais que l'ordinateur joue bien.						 //
//											 //
//  Point corrigé :                                                                      //
//											 //
//  Reduire les lignes et les fonction inutiles						 //
//  Pouvoir choisir la taille du jeu de table ex) 4*7 6*6 9*9                            //
//  char tabVisuel[ROW*3][COLUMN] -> int tabVisuel[ROW][COLUMN]         		 //
//  Attack, Defense, jouer avec la probabilite sont dans une fonction 'SuperPlayAI'      //
//  											 //
///////////////////////////////////////////////////////////////////////////////////////////

#include"algo.h"


int Titre(void){
	int votreChoix;
	printf("=================================================\n");
	printf("|\t\t\t\t\t\t|\n");
	printf("|\t\tLangage Imperatif   \t\t|\n");
	printf("|\t\t\t\t\t\t|\n");
	printf("|\t Projet : Le jeu de Forteresse    \t|\n");
	printf("|\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t|\n");
	printf("|\t\t       * Saisissez le code *    |\n");
	printf("|\t\t   1.Version Corrigee           |\n");
	printf("|\t\t     Jouer pour 2 Personne : 1  |\n");
	printf("|\t\t     Jouer contre SUPER-AI : 2  |\n");
	printf("|\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t|\n");
	printf("|\t Point Corrige:	   	          \t|\n");
	printf("|\t Supprimer les fonctions inutiles \t|\n");
	printf("|\t Reduire les ligne 1274->706    \t|\n");
	printf("|\t Convertir le tableau en char -> int\t|\n");
	printf("|\t Choisir la taille du table de jeu\t|\n");
	printf("|\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t|\n");
	printf("| Nom : BAE HOBEAN       \t\t\t|\n");
	printf("| Nom : KIM KYUNG TAEK   \t\t\t|\n");
	printf("| Date de Correction 16/05/2015 \t\t|\n");
	printf("| Date de Presentation 13/05/2015 \t\t|\n");
	printf("=================================================\n");
	scanf("%d",&votreChoix);
	return votreChoix;
}


void resetTab(int tab[ROW][COLUMN]){
	int i,j;
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++)
		{tab[i][j]=0;
		}
	}
}


void Affichage(int tabVisuel[ROW][COLUMN]){
	int i,j;
	char caractereAetB;
	int barre;
	int posNum;
	int posNum2=0;
	char tab[ROW*3][COLUMN]={' ',};
	for(i=0,barre=0; i<ROW; i++){
	for(j=0; j<COLUMN; j++){
			if(tabVisuel[i][j]==1){tab[i*3][j]=' ';
						tab[i*3+1][j]='A';
						tab[i*3+2][j]=' ';}
			if(tabVisuel[i][j]==2){tab[i*3][j]=' ';
						tab[i*3+1][j]='A';
						tab[i*3+2][j]='A';}

			if(tabVisuel[i][j]==3){tab[i*3+1][j]='A';
						tab[i*3+2][j]='A';
						tab[i*3][j]='A';}

			if(tabVisuel[i][j]==-1){tab[i*3][j]=' ';
						tab[i*3+1][j]='B';
						tab[i*3+2][j]=' ';}

			if(tabVisuel[i][j]==-2){tab[i*3][j]=' ';
						tab[i*3+1][j]='B';
						tab[i*3+2][j]='B';}

			if(tabVisuel[i][j]==-3){tab[i*3][j]='B';
						tab[i*3+1][j]='B';
						tab[i*3+2][j]='B';}

			if(tabVisuel[i][j]==0){tab[i*3][j]=' ';
						tab[i*3+1][j]=' ';
						tab[i*3+2][j]=' ';}
}
	}
	printf("       ");
	for(j=0;j<COLUMN;j++)printf("  %2d",j);
	printf("\n");
	for(j=0;j<COLUMN;j++){if(j==0)printf("\t+");
				if(j==COLUMN-1)printf("---");
				else printf("----");
				if(j==COLUMN-1)printf("+\n\t");}
	
	for(i=0,barre=0; i<ROW*3; i++,barre++){
		for(j=0; j<COLUMN; j++){
			caractereAetB=tab[i][j];
			printf("| %c ",caractereAetB);
		} 
	
		if(i%3==0){printf("|\n    %2d  ",posNum2); posNum2++;}
		else{printf("|\n        ");}
		if(barre % 3== 2)for(j=0;j<COLUMN;j++){if(j==0)printf("+");
				if(j==COLUMN-1)printf("---");
				else printf("----");
				if(j==COLUMN-1)printf("+\n\t");}
	}	
}


void ConstructTowerA(int tabVisuel[ROW][COLUMN]){
	int choixUilisateurX,choixUilisateurY;

refaire:
	printf("  Vous etes joueur A\n");
	printf("\tsaisissez la position X\n");
	scanf("%d",&choixUilisateurX);
	
		if(choixUilisateurX>ROW-1){	
			Affichage(tabVisuel);
			printf("* Erreur! *\n       La position X que vous avez compose est incorrect\n\t");
			goto refaire;}
	printf("\tsaisissez la position Y\n"); 	
	scanf("%d",&choixUilisateurY);

	if(choixUilisateurY>COLUMN-1){	
			Affichage(tabVisuel);
			printf("* Erreur! *\n       La position Y que vous avez compose est incorrect\n\t");
			goto refaire;}
	
	if(tabVisuel[choixUilisateurX][choixUilisateurY]<0){
		Affichage(tabVisuel);
		printf("* Erreur! *\n       Ce teritoire est deja occupe par l'adversaire(B) \n\t");
		goto refaire;}

		if(tabVisuel[choixUilisateurX][choixUilisateurY]<3){
		tabVisuel[choixUilisateurX][choixUilisateurY]+=1;return;}
 
		Affichage(tabVisuel);
		printf("* Erreur! *\n       Vos trois tours sont tous construites ici \n\t");
		goto refaire;
}

void ConstructTowerB(int tabVisuel[ROW][COLUMN]){
	int choixUilisateurX,choixUilisateurY;

refaire:
	printf("  Vous etes joueur B\n");
	printf("\tsaisissez la position X\n");
	scanf("%d",&choixUilisateurX);
	
		if(choixUilisateurX>ROW-1){	
			Affichage(tabVisuel);
			printf("* Erreur! *\n       La position X que vous avez compose est incorrect\n\t");
			goto refaire;}
	printf("\tsaisissez la position Y\n"); 	
	scanf("%d",&choixUilisateurY);

	if(choixUilisateurY>COLUMN-1){	
			Affichage(tabVisuel);
			printf("* Erreur! *\n       La position Y que vous avez compose est incorrect\n\t");
			goto refaire;}
	
	if(tabVisuel[choixUilisateurX][choixUilisateurY]>0){
		Affichage(tabVisuel);
		printf("* Erreur! *\n       Ce teritoire est deja occupe par l'adversaire(A) \n\t");
		goto refaire;}

		if(tabVisuel[choixUilisateurX][choixUilisateurY]>-3){
		tabVisuel[choixUilisateurX][choixUilisateurY]-=1;return;}
 
		Affichage(tabVisuel);
		printf("* Erreur! *\n       Vos trois tours sont tous construites ici \n\t");
		goto refaire;
}



int joueCombienFois(int tabVisuel[ROW][COLUMN]){
	int i,j;
	int val;
	int compteur;
	compteur = 0;
	
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
 		val=tabVisuel[i][j];
		if(val<0){compteur= compteur - val;}
		else {compteur= compteur + val;}
		}
}
	return compteur;

}
int CombienRempliePourFinir(int tabVisuel[ROW][COLUMN]){
 int code;
 int finicode;
 int Vingt=ROW*COLUMN/0.2;
 int Quarante=ROW*COLUMN* 0.4;
 int Soixante=ROW*COLUMN* 0.6;
 int QuatreVingt=ROW*COLUMN* 0.8;
 if(joueCombienFois(tabVisuel) == Vingt){
 		Affichage(tabVisuel);
		 printf("Vingt pour cent de tableau est rempli, Que desirez-vous?\n\t");
 		printf("Saisissez le code! Continuer : 1 , Finir : 9\n");
 		scanf("%d",&code);
 		finicode=code;
 		if(finicode==1)return 0;
 		if(finicode==9)return 1;
	}
	
 if(joueCombienFois(tabVisuel) == Quarante){
 		Affichage(tabVisuel);
 		printf("Quarante pour cent de tableau est rempli, Que desirez-vous?\n\t");
 		printf("Saisissez le code! Continuer : 1 , Finir : 9\n");
 		scanf("%d",&code);
 		finicode=code;
 		if(finicode==1)return 0;
 		if(finicode==9)return 1;
	}
	
 if(joueCombienFois(tabVisuel) == Soixante){
 		Affichage(tabVisuel);
 		printf("Soixante pour cent de tableau est rempli, Que desirez-vous?\n\t");
 		printf("Saisissez le code! Continuer : 1 , Finir : 9\n");
 		scanf("%d",&code);
 		finicode=code;
 		if(finicode==1)return 0;
 		if(finicode==9)return 1;
	}
	
 if(joueCombienFois(tabVisuel) == QuatreVingt){
 		Affichage(tabVisuel);
 		printf("Quatre-Vingt pour cent de tableau est rempli, Que desirez-vous?\n\t");
 		printf("Saisissez le code! Continuer : 1 , Finir : 9\n");
 		scanf("%d",&code);
 		finicode=code;
 		if(finicode==1)return 0;
 		if(finicode==9)return 1;
	}
	
 if(joueCombienFois(tabVisuel) == (ROW*COLUMN)){
		Affichage(tabVisuel);
		printf("\tGame Over...\n");
		printf("\tCent pour cent tableau est rempli\n");
 		printf("\tPour verifier le resultat, saisissez un nombre\n");
 		scanf("%d",&code);
 		finicode=code;
		if(finicode>0) return 1;
	}
	return 0;
 }


void Controle(int tabVisuel[ROW][COLUMN],int tabControle[ROW][COLUMN]){
int i,j;
int nombreDeTour=0;

for(i=0; i<ROW; i++){
	for(j=0; j<COLUMN; j++){
		nombreDeTour=tabVisuel[i][j];
		
	//coin
	if(i==0&&j==0){
		tabControle[i][j]+=nombreDeTour;
		tabControle[i][j+1]+=nombreDeTour; 
		tabControle[i+1][j]+=nombreDeTour;}
	if(i==0&&j==COLUMN-1){
		tabControle[i][j]+=nombreDeTour;
		tabControle[i][j-1]+=nombreDeTour; 
		tabControle[i+1][j]+=nombreDeTour;}
	if(i==ROW-1&&j==0){
		tabControle[i][j]+=nombreDeTour;
		tabControle[i][j+1]+=nombreDeTour; 
		tabControle[i-1][j]+=nombreDeTour;}
	if(i==ROW-1&&j==COLUMN-1){
		tabControle[i][j]+=nombreDeTour;
		tabControle[i][j-1]+=nombreDeTour; 
		tabControle[i-1][j]+=nombreDeTour;}
		}
	
}
	// Gauche
	for(i=0,j=1;j<COLUMN-1;j++){
		nombreDeTour=tabVisuel[i][j];
		tabControle[i][j]+=nombreDeTour;
		tabControle[i][j-1]+=nombreDeTour; 
		tabControle[i][j+1]+=nombreDeTour;
		tabControle[i+1][j]+=nombreDeTour;}
	// Droit
	for(i=1,j=COLUMN-1;i<ROW-1;i++){
		nombreDeTour=tabVisuel[i][j];
		tabControle[i][j]+=nombreDeTour;
		tabControle[i][j-1]+=nombreDeTour; 
		tabControle[i-1][j]+=nombreDeTour;
		tabControle[i+1][j]+=nombreDeTour;}

	// Haut
	for(i=1,j=0;i<ROW-1;i++){
		nombreDeTour=tabVisuel[i][j];
		tabControle[i][j]+=nombreDeTour;
		tabControle[i-1][j]+=nombreDeTour; 
		tabControle[i][j+1]+=nombreDeTour;
		tabControle[i+1][j]+=nombreDeTour;}
	// Bas
	for(i=ROW-1,j=1;j<COLUMN-1;j++){
		nombreDeTour=tabVisuel[i][j];
		tabControle[i][j]+=nombreDeTour;
		tabControle[i][j-1]+=nombreDeTour; 
		tabControle[i][j+1]+=nombreDeTour;
		tabControle[i-1][j]+=nombreDeTour;
		}
	

	for(i=1; i<ROW-1; i++){
	for(j=1; j<COLUMN-1; j++){
		nombreDeTour=tabVisuel[i][j];
	tabControle[i][j]+=nombreDeTour;
		tabControle[i][j-1]+=nombreDeTour;
		tabControle[i][j+1]+=nombreDeTour; 
		tabControle[i-1][j]+=nombreDeTour;
		tabControle[i+1][j]+=nombreDeTour;}}
}


int Destruct(int tabVisuel[ROW][COLUMN],int tabControle[ROW][COLUMN]){
	int i,j;
	int scoreA,scoreB;
	resetTab(tabControle);
	Controle(tabVisuel,tabControle);
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabControle[i][j]>0&&tabVisuel[i][j]<0){
				scoreA=tabVisuel[i][j];				
				tabVisuel[i][j]=0;
				Affichage(tabVisuel);
				printf("ATTACKED! Joueur A a detruit la tour de B(%d,%d)\n\t",i,j);
				if(scoreA==-1)return 1;
				if(scoreA==-2)return 2;
				if(scoreA==-3)return 3;
				}
				}
			}
		for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabControle[i][j]<0&&tabVisuel[i][j]>0){
				scoreB=tabVisuel[i][j];				
				tabVisuel[i][j]=0;
				Affichage(tabVisuel);
				printf("ATTACKED! Joueur B a detruit la tour de A(%d,%d)\n\t",i,j);
				if(scoreB==1)return 4;
				if(scoreB==2)return 5;
				if(scoreB==3)return 6;
				}
				}
			}
	return 0;
}

int CombienDeProbabilite(int tabValue[ROW][COLUMN]){
	int i,j;
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabValue[i][j]==100)return 100;}}
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabValue[i][j]==99)return 99;}}
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabValue[i][j]==5)return 5;}}
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabValue[i][j]==4)return 4;}}
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabValue[i][j]==3)return 3;}}
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabValue[i][j]==2)return 2;}}
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabValue[i][j]==1)return 1;}}
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabValue[i][j]==0)return 0;}
}
}
void ProbabiliteVersionOriginal(int tabVisuel[ROW][COLUMN],int tabControle[ROW][COLUMN],int tabValue[ROW][COLUMN]){
int i,j;
       // right 0 1 2 3 4 5
	for(i=1;i<ROW-1;i++){
	    for(j=1;j<COLUMN-1;j++){
		if(tabControle[i][j]==0||tabControle[i][j]==1)tabValue[i][j]+= 1;
		if(tabControle[i-1][j]==0||tabControle[i-1][j]==1)tabValue[i][j]+= 1;
		if(tabControle[i+1][j]==0||tabControle[i+1][j]==1)tabValue[i][j]+= 1;
		if(tabControle[i][j-1]==0||tabControle[i][j-1]==1)tabValue[i][j]+= 1;
		if(tabControle[i][j+1]==0||tabControle[i][j+1]==1)tabValue[i][j]+= 1;}}
	// corner (0 0) (0 1) (1 0)
		if(tabControle[0][0]==0||tabControle[0][0]==1)tabValue[0][0]+=1;
		if(tabControle[1][0]==0||tabControle[1][0]==1)tabValue[0][0]+=1;
		if(tabControle[0][1]==0||tabControle[0][1]==1)tabValue[0][0]+=1;
	
		if(tabControle[ROW-1][0]==0||tabControle[ROW-1][0]==1)tabValue[ROW-1][0]+=1;
		if(tabControle[ROW-2][0]==0||tabControle[ROW-2][0]==1)tabValue[ROW-1][0]+=1;
		if(tabControle[ROW-1][1]==0||tabControle[ROW-1][1]==1)tabValue[ROW-1][0]+=1;
	
		if(tabControle[0][COLUMN-1]==0||tabControle[0][COLUMN-1]==1)tabValue[0][COLUMN-1]+=1;
		if(tabControle[0][COLUMN-2]==0||tabControle[0][COLUMN-2]==1)tabValue[0][COLUMN-1]+=1;
		if(tabControle[1][COLUMN-1]==0||tabControle[1][COLUMN-1]==1)tabValue[0][COLUMN-1]+=1;
	
		if(tabControle[ROW-1][COLUMN-1]==0||tabControle[ROW-1][COLUMN-1]==1)tabValue[ROW-1][COLUMN-1]+=1;
		if(tabControle[ROW-2][COLUMN-1]==0||tabControle[ROW-2][COLUMN-1]==1)tabValue[ROW-1][COLUMN-1]+=1;
		if(tabControle[ROW-1][COLUMN-2]==0||tabControle[ROW-1][COLUMN-2]==1)tabValue[ROW-1][COLUMN-1]+=1;
	
	for(i=1,j=0;i<ROW-1;i++){
			if(tabControle[i][j]==0||tabControle[i][j]==1)tabValue[i][j]+= 1;
			if(tabControle[i-1][j]==0||tabControle[i-1][j]==1)tabValue[i][j]+= 1;
			if(tabControle[i+1][j]==0||tabControle[i+1][j]==1)tabValue[i][j]+= 1;
			if(tabControle[i][j+1]==0||tabControle[i][j+1]==1)tabValue[i][j]+= 1;
			}
	for(i=1,j=COLUMN-1;i<ROW-1;i++){
			if(tabControle[i][j]==0||tabControle[i][j]==1)tabValue[i][j]+= 1;
			if(tabControle[i-1][j]==0||tabControle[i-1][j]==1)tabValue[i][j]+= 1;
			if(tabControle[i+1][j]==0||tabControle[i+1][j]==1)tabValue[i][j]+= 1;
			if(tabControle[i][j-1]==0||tabControle[i][j-1]==1)tabValue[i][j]+= 1;
			}	
	for(i=0,j=1;j<COLUMN-1;j++){
			if(tabControle[i][j]==0||tabControle[i][j]==1)tabValue[i][j]+= 1;
			if(tabControle[i+1][j]==0||tabControle[i+1][j]==1)tabValue[i][j]+= 1;
			if(tabControle[i][j-1]==0||tabControle[i][j-1]==1)tabValue[i][j]+= 1;
			if(tabControle[i][j+1]==0||tabControle[i][j+1]==1)tabValue[i][j]+= 1;
			}
	for(i=ROW-1,j=1;j<COLUMN-1;j++){
			if(tabControle[i][j]==0||tabControle[i][j]==1)tabValue[i][j]+= 1;
			if(tabControle[i-1][j]==0||tabControle[i-1][j]==1)tabValue[i][j]+= 1;
			if(tabControle[i][j-1]==0||tabControle[i][j-1]==1)tabValue[i][j]+= 1;
			if(tabControle[i][j+1]==0||tabControle[i][j+1]==1)tabValue[i][j]+= 1;	
			}		
		
for(i=0;i<ROW;i++){
for(j=0;j<COLUMN;j++){	
	// tower A
		if(tabVisuel[i][j]>0){
		tabValue[i][j]=0;
		tabValue[i-1][j]=0;
		tabValue[i+1][j]=0;
		tabValue[i][j-1]=0;
		tabValue[i][j+1]=0;}
		// 3 tower B
		if(tabVisuel[i][j]==3)tabValue[i][j]=0;
		// 2 controle a cote
		if(tabControle[i][j]>=2)tabValue[i][j]=0;
		// il faut attaquer
		}
	}
for(i=0;i<ROW;i++){
for(j=0;j<COLUMN;j++){	
	if(tabControle[i][j]==0&&tabVisuel[i][j]>0){
			tabValue[i-1][j]=99;
			tabValue[i+1][j]=99;
			tabValue[i][j-1]=99;
			tabValue[i][j+1]=99;}}}
for(i=0;i<ROW;i++){
for(j=0;j<COLUMN;j++){
if(tabControle[i][j]==0&&tabVisuel[i][j]<0)tabValue[i][j]=100;}}

}

void SuperPlay_AI(int tabVisuel[ROW][COLUMN],int tabControle[ROW][COLUMN],int tabValue[ROW][COLUMN]){
int HasardPosX,HasardPosY;
int i,j;
int x,y;
	rechoisir:
		srand((unsigned)time(NULL));	
		HasardPosX = rand() % ROW;
		HasardPosY = rand() % COLUMN;
		resetTab(tabControle);
		Controle(tabVisuel,tabControle);
		resetTab(tabValue);
		ProbabiliteVersionOriginal(tabVisuel,tabControle,tabValue);
		x=HasardPosX;
		y=HasardPosY;
// defense 100%
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabValue[i][j]==100){
			if(tabVisuel[i][j]>-3&&tabControle[i][j]==0){tabVisuel[i][j]-=1;return;}
//si cette case est remplie on retoure aux voisins
			if(tabVisuel[i-1][j]>-3&&tabControle[i-1][j]==0){tabVisuel[i-1][j]-=1;return;}
			if(tabVisuel[i+1][j]>-3&&tabControle[i+1][j]==0){tabVisuel[i+1][j]-=1;return;}
			if(tabVisuel[i][j-1]>-3&&tabControle[i][j-1]==0){tabVisuel[i][j-1]-=1;return;}
			if(tabVisuel[i][j-1]>-3&&tabControle[i][j+1]==0){tabVisuel[i][j+1]-=1;return;}}}}
// attack 99%
		for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabValue[i][j]==99){tabVisuel[i][j]-=1;return;}}}
// si non jouer normal
		if(CombienDeProbabilite(tabValue)==5&&tabValue[x][y]>=4)goto remplissez;
		else{goto rechoisir;}
		if(CombienDeProbabilite(tabValue)==4&&tabValue[x][y]>=3)goto remplissez;
		else{goto rechoisir;}
		if(CombienDeProbabilite(tabValue)==3&&tabValue[x][y]>=2)goto remplissez;
		else{goto rechoisir;}
		if(CombienDeProbabilite(tabValue)==2&&tabValue[x][y]>=1)goto remplissez;
		else{goto rechoisir;}
		if(CombienDeProbabilite(tabValue)==1&&tabValue[x][y]==1)goto remplissez;
		else{goto rechoisir;}
		return;
// AI a trouve la bonne position
	remplissez:
		if(tabVisuel[x][y]>0)goto rechoisir;
		if(tabVisuel[x][y]>-3){
		tabVisuel[x][y]--;
		return;
}
}


void Affiche(int tabControle[ROW][COLUMN]){
int i,j;

	printf("\n");
for(i=0;i<ROW;i++){
	for(j=0;j<COLUMN;j++){
		printf("%2d",tabControle[i][j]);
	}
	printf("\n");
}
printf("\t");
}

void QuiEstVainqueur(int tabVisuel[ROW][COLUMN],int tabControle[ROW][COLUMN],int scoreA,int scoreB){
	int i,j;
	int territoA=0,territoB=0;
	resetTab(tabControle);	
	Controle(tabVisuel,tabControle);
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(tabControle[i][j]>0)territoA++;
			if(tabControle[i][j]<0)territoB++;
		}
	}
	Affichage(tabVisuel);
	if(territoA==territoB&&scoreA==scoreB)printf("Egalite! Total A = 1 Point, B = 1 Point\n");
	if(territoA>territoB&&scoreA<scoreB)printf("Egalite! Total A = 1 Point, B = 1 Point\n");
	if(territoA<territoB&&scoreA>scoreB)printf("Egalite! Total A = 1 Point, B = 1 Point\n");

	if(territoA>=territoB&&scoreA>scoreB) printf("Le jouer A est Vainqueur!\n");
	else{if(territoA>territoB&&scoreA>=scoreB) printf("Le jouer A est Vainqueur!\n");}
	if(territoA<=territoB&&scoreA<scoreB) printf("Le jouer B est Vainqueur!\n");
	else{if(territoA<territoB&&scoreA<=scoreB) printf("Le jouer B est Vainqueur!\n");}
	
	
	printf("   Score A : %2d territoires occupes, %2d tours perdues\n",territoA,scoreB);
	printf("   Score B : %2d territoires occupes, %2d tours perdues\n",territoB,scoreA);
	printf("	   	   				     * Saisissez le code! *\n");
	printf("   						     Rejouer : 1, Sortir : 9\n");
	
}
