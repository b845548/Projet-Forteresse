#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define ROW 3
#define COLUMN 9
int Titre(void);
  void resetTab(int [ROW][COLUMN]);
  void Affichage(int [ROW][COLUMN]);
  void ConstructTowerA(int [ROW][COLUMN]);
  void ConstructTowerB(int [ROW][COLUMN]);
  int joueCombienFois(int [ROW][COLUMN]);
int CombienRempliePourFinir(int [ROW][COLUMN]);
  void Controle(int [ROW][COLUMN],int [ROW][COLUMN]);
  int Destruct(int [ROW][COLUMN],int [ROW][COLUMN]);
  int CombienDeProbabilite(int [ROW][COLUMN]);
  void ProbabiliteVersionOriginal(int [ROW][COLUMN],int [ROW][COLUMN],int [ROW][COLUMN]);
  void SuperPlay_AI(int [ROW][COLUMN],int [ROW][COLUMN],int [ROW][COLUMN]);
  void Affiche(int [ROW][COLUMN]);
  void QuiEstVainqueur(int [ROW][COLUMN],int [ROW][COLUMN],int ,int);
