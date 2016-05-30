#include"algo.h"


int main(){
	int code=0;
	int scoreA=0;
	int scoreB=0;
	int tabVisuel[ROW][COLUMN]={0,};
	int tabControle[ROW][COLUMN]={0,};
	int tabValue[ROW][COLUMN]={0,};
    
ResetZone:
	resetTab(tabVisuel);
	resetTab(tabControle);
	resetTab(tabValue);

switch (Titre()){
	case 1:
	Affichage(tabVisuel);	
    jouerEncore:
	printf("Score A = %d, Score B = %d\n\t",scoreA,scoreB);
	ConstructTowerA(tabVisuel);

	switch(Destruct(tabVisuel,tabControle))
		{case 0:
			Affichage(tabVisuel);
			break;
		case 1:
			scoreA++;
			break;
		case 2:	
			scoreA+=2;
			break;
		case 3:	
			scoreA+=3;
			break;
		case 4:	
			scoreB++;
			break;
		case 5:	
			scoreB+=2;
			break;
		case 6:	
			scoreB+=2;
			break;}

	printf("Score A = %d, Score B = %d\n\t",scoreA,scoreB);
	ConstructTowerB(tabVisuel);
	switch(Destruct(tabVisuel,tabControle))
		{case 0:
			Affichage(tabVisuel);
			break;
		case 1:
			scoreA++;
			break;
		case 2:	
			scoreA+=2;
			break;
		case 3:	
			scoreA+=3;
			break;
		case 4:	
			scoreB++;
			break;
		case 5:	
			scoreB+=2;
			break;
		case 6:	
			scoreB+=2;
			break;

		}
	if(CombienRempliePourFinir(tabVisuel)==1) goto VainqueurZone;
	goto jouerEncore;
	VainqueurZone:
	QuiEstVainqueur(tabVisuel,tabControle,scoreA,scoreB);
	scanf("%d",&code);
		if(code==1)goto ResetZone;
	break;

	case 2:
	Affichage(tabVisuel);	
    jouerEncore2:
	printf("Your Score = %d, Score AI = %d\n\t",scoreA,scoreB);
	ConstructTowerA(tabVisuel);
	switch(Destruct(tabVisuel,tabControle))
		{case 0:
			Affichage(tabVisuel);
			break;
		case 1:
			scoreA++;
			break;
		case 2:	
			scoreA+=2;
			break;
		case 3:	
			scoreA+=3;
			break;
		case 4:	
			scoreB++;
			break;
		case 5:	
			scoreB+=2;
			break;
		case 6:	
			scoreB+=2;
			break;}

	printf("Your Score  = %d, Score AI = %d\n\t",scoreA,scoreB);
	printf("* Veuillez patienter *\n   AI est en train d'examiner les probabilites...\n");

	SuperPlay_AI(tabVisuel, tabControle, tabValue);
	switch(Destruct(tabVisuel,tabControle))
		{case 0:
			Affichage(tabVisuel);
			break;
		case 1:
			scoreA++;
			break;
		case 2:	
			scoreA+=2;
			break;
		case 3:	
			scoreA+=3;
			break;
		case 4:	
			scoreB++;
			break;
		case 5:	
			scoreB+=2;
			break;
		case 6:	
			scoreB+=2;
			break;}

	if(CombienRempliePourFinir(tabVisuel)==1) goto VainqueurZone2;
	goto jouerEncore2;
	VainqueurZone2:
	QuiEstVainqueur(tabVisuel,tabControle,scoreA,scoreB);
	scanf("%d",&code);
	if(code==1)goto ResetZone;
	break;}

return 0;
}	
