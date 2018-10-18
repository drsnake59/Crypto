//DELAETER LABUSSIERE

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
				 
void invPermutationInitiale(vector<int> &tab){
		vector <int> tabPer={tab[3],tab[0],tab[2],tab[4],tab[6],tab[1],tab[7],tab[5]};
		tab=tabPer;
	}
	
void echange(vector <int> a,vector <int> b,vector<int> &c){
		vector<int> res;
		for(int i=0;i<b.size();i++){
			res.push_back(b[i]);
			}
		for(int i=0;i<a.size();i++){
			res.push_back(a[i]);
			}
		c=res;
		}

void entSw(vector<int> a,vector<int> b,vector<int> &ent){
		vector<int> tab;
		int tailleA=a.size();
		int taille=a.size()+b.size();
		for(int i=0;i<tailleA;i++){
			tab.push_back(a[i]);
			}
		for(int i=0;i<b.size();i++){
			tab.push_back(b[i]);
			}
	ent=tab;
	}

void permutationInitiale(vector<int> &tab){
	vector <int> tab8={tab[1],tab[5],tab[2],tab[0],tab[3],tab[7],tab[4],tab[6]};
	tab=tab8;
	}

void permutation10(vector<int> &tab){
	vector <int> tabPer={tab[2],tab[4],tab[1],tab[6],tab[3],tab[9],tab[0],tab[8],tab[7],tab[5]};
	tab=tabPer;
	}
void rotationGaucheParCinq(vector<int> &tab){
	vector<int> copie = tab;
	int moitie=tab.size()/2;
	for(int i=0;i<moitie;i++){
		tab[i%5]=copie[(i+1)%5];
		}
	copie=tab;
	////////////////////////////////
	for(int i=0;i<moitie;i++){
		tab[(i%5)+moitie]=copie[((i+1)%5)+moitie];
		}
	}
	
void XOR(vector<int> s, vector<int> k,vector <int> & sortie)
{
	vector<int> p;
	int taille = s.size();
	for(unsigned int i = 0; i < taille; ++i)
	{
		s[i]^k[i] == 1 ? p.push_back(1) : p.push_back(0) ;
	}
sortie=p;
}

void expansionPermutation(vector <int> & extPer){
	vector<int> nouv= {extPer[3],extPer[0],extPer[1],extPer[2],extPer[1],extPer[2],extPer[3],extPer[0]};
	extPer=nouv;
	}
	
void afficherVector(vector<int> tab){
		for(int i =0;i<tab.size();i++){
			cout<<tab[i];
		}
	cout<<endl;
	}

vector<int> permutation8(vector<int> tab){
	vector <int> tab8={tab[5],tab[2],tab[6],tab[3],tab[7],tab[4],tab[9],tab[8]};
	return tab8;
	}
	
void k1(vector<int> &tab){
	permutation10(tab);
	rotationGaucheParCinq(tab);
	vector<int>tab8=permutation8(tab);
	tab=tab8;
	}
	
void k2(vector<int>&tab){
	permutation10(tab);
	rotationGaucheParCinq(tab);
	rotationGaucheParCinq(tab);
	rotationGaucheParCinq(tab);
	vector<int>tab8=permutation8(tab);
	tab=tab8;
	}
	
vector<int> getL(vector<int> tab){
	vector<int> mitab;
	for(int i=0;i<tab.size()/2;i++){
		mitab.push_back(tab[i]);
		}
	return mitab;
	}
	
void convertBinInt(int a,int &b){
stringstream ss;
ss << a;
string stri = ss.str();
reverse(stri.begin(), stri.end());
int nb=0;
int mul=1;

for(int i=0;i<stri.size();i++){
	nb+=stri[i]*mul;
	mul=mul*2;
	}
b=nb;
}

vector<int> getR(vector<int> tab){
	int moitie=tab.size()/2;
	vector<int> mitab;
	for(int i=0;i<moitie;++i){
		mitab.push_back(tab[i+moitie]);
		}
	return mitab;
	}
/*void sBox(vector<int> tabFin,vector <int> &retour2){
	
vector <int> S0={1,0,3,2,
				 3,2,1,0,
				 0,2,1,3,
				 3,1,3,2};
				 
vector<int> S1={0,1,2,3,
				 2,0,1,3,
				 3,0,1,0,
				 2,1,0,3};
	//partie gauche
	cout<<"TABB FINN"<<endl;
	afficherVector(tabFin);
	cout<<endl;
	vector<int> gauche=getL(tabFin);
	vector<int> droite=getR(tabFin);
	
	vector<int> gaucheG=getL(gauche);
	vector<int> gaucheD=getR(gauche);	
	
	vector<int> droiteG=getL(droite);
	vector<int> droiteD=getR(droite); 
	
	int ligneGauche;
	convertBinInt(gaucheG,ligneGauche);//entier tab lg
	int colonneGauche;
	convertBinInt(gaucheD,colonneGauche);//entier tab cg
	
	int ligneDroite;
	convertBinInt(droiteG,ligneDroite);//entier tab lg
	int colonneDroite;
	convertBinInt(droiteD,colonneDroite);//entier tab cg
	
	int valGauche=S0[3*(ligneGauche)+colonneGauche];
	int valDroite=S1[3*(ligneDroite)+colonneDroite];
	
	vector<int> outputL;
	vector<int> outputR;
	
	switch(valGauche)
    {
        case 0:
            outputL.push_back(0);
            outputL.push_back(0);
            break;

        case 1:
            outputL.push_back(0);
            outputL.push_back(1);
            break;

        case 2:
            outputL.push_back(1);
            outputL.push_back(0);
            break;

        case 3:
            outputL.push_back(1);
            outputL.push_back(1);
            break;

        default:
            cout << "Error in s-box" << endl;
            exit(0);
            break;
    }
    
    	switch(valDroite)
    {
        case 0:
            outputR.push_back(0);
            outputR.push_back(0);
            break;

        case 1:
            outputR.push_back(0);
            outputR.push_back(1);
            break;

        case 2:
            outputR.push_back(1);
            outputR.push_back(0);
            break;

        case 3:
            outputR.push_back(1);
            outputR.push_back(1);
            break;

        default:
            cout << "Error in s-box" << endl;
            exit(0);
            break;
    }
    
 vector<int> ret2={outputL[0],outputL[1],outputR[0],outputR[1]};   
retour2=ret2;
}*/

void permutation4(vector<int> &tab){
	vector <int> perm;
	perm.push_back(tab[1]);
	perm.push_back(tab[3]);
	perm.push_back(tab[2]);
	perm.push_back(tab[1]);
	tab=perm;
	}

int main(){

	int A=65;
	int e=101;
	vector<int> clek1={1,1,1,1,0,1,1,0,0,1};
	vector<int> clek2={1,1,1,1,0,1,1,0,0,1};
	
	cout<<"calcul de k1"<<endl;
	k1(clek1);//calcul p10 + decalage gauche + appliquer p8
	afficherVector(clek1);
	cout<<"calcul de k2"<<endl;
	k2(clek2);
	afficherVector(clek2);
	
	cout<<"transformation des caractères"<<endl;
	
	//A
	vector<int> tabA={0,1,0,0,0,0,0,1};
	vector<int> tabe={0,1,1,0,0,1,0,1};
	cout<<"permutation initial A"<<endl;
	permutationInitiale(tabA);
	afficherVector(tabA);
	cout<<"Partie droite"<<endl;
	vector<int> rightP=getR(tabA);
	afficherVector(rightP);
	
	cout<<"expansionPermutation"<<endl;
	expansionPermutation(rightP);
	afficherVector(rightP);
	
	vector<int> sort;
	XOR(rightP,clek1,sort);
	cout<<"XOR"<<endl;
	afficherVector(sort);
	vector<int> finSbox;
	//sBox(sort,finSbox);
	cout<<"finSbox"<<endl;
	afficherVector(finSbox);
	cout<<"p4"<<endl;
	permutation4(finSbox);
	afficherVector(finSbox);
	
	cout<<"XOR2"<<endl;
	vector<int> leftPart=getL(tabA);
	afficherVector(leftPart);
	/*	
	vector<int> fin;
	XOR(leftPart,finSbox,fin);
	cout<<"valeur sortie du XOR"<<endl;
	afficherVector(fin);
	
	//concat fin et parti gauche de ip

	vector<int> swEnt;
	vector<int> droite=getR(tabA);
	
	entSw(fin,droite,swEnt);
	afficherVector(swEnt);
	
	//sw
	vector<int> finSw;
	echange(swEnt,droite,finSw);

	cout<<endl;
	afficherVector(finSw);
	//fin SW
	*/
	//Application d'un deuxieme F
	
	//P-1
	
	cout<<endl;
	cout<<"/////////////ZOR,expension-permutation,k1,k2 OKK///////////"<<endl;
	
	//fin sbox 0111
	//fk1 11110100
	
	//dechiffrer k2+k1
	
	int a=11;
	int fin;
	
	convertBinInt(a,fin);
	cout<<fin;
	
	return 0;
	}
