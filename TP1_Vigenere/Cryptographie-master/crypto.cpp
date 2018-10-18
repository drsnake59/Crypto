//DELAETER JOSEPH & LABUSSIERE HUGO

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string traitementLigne(string lig){
	string nouv="";
	
	for(unsigned int i=0;i<lig.size();i++){
		if(lig[i]<='z' and lig[i]>='a' ){
		nouv+=lig[i];
		}
		
		else if(lig[i]<='Z' and lig[i]>='A'){
			nouv+=lig[i];
		}
	}
transform(nouv.begin(), nouv.end(),nouv.begin(), ::tolower);

return nouv;
}

string extractionFichierTexte(string texte){
     string mon_fichier = texte;   
     string texteFic="";    
     ifstream fichier(mon_fichier.c_str(), ios::in);  
      
     if(fichier){
		string ligne;
        while(getline(fichier, ligne))
        {
			ligne=traitementLigne(ligne);
			texteFic+=ligne;
        }
        fichier.close();
     }
     else
        cerr << "Erreur à l'ouverture !" << endl;
 
return texteFic;
}

void insererFichierCryp(string texte){	
	 ofstream fichier("texteChiffre.txt", ios::out | ios::trunc);
	 
        if(fichier){
                fichier <<"Texte crypté : "<< texte;
                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
}

string dechiffrer(string cle,string texte){

	int tailleCle = cle.length();
	int tailleTexte = texte.length();
	int incCle=0;
	
	string nouveau;
	
	for(int i=0;i<tailleTexte;i++){
		if(texte[i]==' '){
			nouveau+=' ';
			}
			else if(texte[i]<='z' and texte[i]>='a'){
			nouveau+=char((texte[i]-cle[incCle%tailleCle]+26)%26+97);
			incCle++;	
			}
			else if(texte[i]<='Z' and texte[i]>='A'){
			nouveau+=char((texte[i]-cle[incCle%tailleCle]+26)%26+65);
			incCle++;	
			}
		}
		
return nouveau;
}

string chiffrer(string cle,string texte){
	int tailleCle = cle.length();
	int tailleTexte = texte.length();
	int incCle=0;	
	string nouveau;

	for(int i=0;i<tailleTexte;i++){
		if(texte[i]==' ')
			nouveau+=' ';
		else if(texte[i]<='z' and texte[i]>='a'){
			nouveau+=char((texte[i]+cle[incCle%tailleCle]-97*2 )%26+97);
			incCle++;	
		}
		else if(texte[i]<='Z' and texte[i]>='A'){
			nouveau+=char((texte[i]+cle[incCle%tailleCle]-65*2 )%26+65);
			incCle++;	
		}
	}
	
return nouveau;
}

void afficherVector(vector<char> tab){//A regrouper

	for(unsigned int i=0;i<tab.size();i++){
		cout<<tab[i]<<" ";
	}
	cout<<endl;
	}

void afficherVector(vector<int> tab){
	for(unsigned int i=0;i<tab.size();i++){
		cout<<tab[i]<<" ";
	}
	cout<<endl;
	}

void afficherVector(vector<double> tab){
	for(unsigned int i=0;i<tab.size();i++){
		cout<<tab[i]<<" ";
	}
	cout<<endl;
	}
	
vector<int> nbOcc(string texte){
	vector<int> tabOcc(26);
	
	for(unsigned int i=0;i<texte.size();i++){
		if(texte[i]>='a' && texte[i]<='z'){
		tabOcc[texte[i]-97]++;
		}
		if(texte[i]>='A' && texte[i]<='Z'){
		tabOcc[texte[i]-97]++;
		}
	}
return tabOcc;
}

float indiceCoincidence(string txt){
	vector<int> tabOcc(26);
	tabOcc=nbOcc(txt);
	float tailleTexte=txt.size();
	float IC=0;
	
	for(unsigned int i=0;i<tabOcc.size();i++){//calcul de l'indice
		IC+=(tabOcc[i])*(tabOcc[i]-1);
	}
	IC=IC/(tailleTexte*(tailleTexte-1));

	return IC;
}

string genererTexte(string texte,int k,int inc){//generer une sous-chaine avec une clé de taille k et un increment possible
	string s;
	int tailleTexte=texte.size();
	int compteur=-1;
	
	for(int i=inc;i<tailleTexte;i++){
		if(texte[i]!=' ' &&((texte[i]<='z' && texte[i]>='a')||(texte[i]<='Z' && texte[i]>='A'))){
			compteur++;
			if((compteur)%k==0){
			s+=texte[i];
			}
		}
	}
return s;
}

int tailleCle(string texte){
	int max=0;
	double indiceMax=0.0;
	//taillecle
	
	for(int i=1;i<12;i++){
		string s=genererTexte(texte,i,0);
		//cout<<"indice de coincidence "<<indiceCoincidence(s)<<endl;
		if(indiceCoincidence(s)>indiceMax){
			indiceMax=indiceCoincidence(s);
			max=i;
			}
	}
	
	return max;
}

int nbLettre(vector<int> tab){
	int cpt=0;
	
	for(unsigned int i=0;i<tab.size();i++){
		cpt+=tab[i];	
	}
	
	return cpt;
}

vector<double> versPourcentage(vector<int> tab){
	vector<double> tDouble(26);
	double nbLettreTab=nbLettre(tab);
	
	for(unsigned int i=0;i<tDouble.size();i++){
		tDouble[i]=100.00*(((double)tab[i])/nbLettreTab);
		}
return tDouble;
}

int plusGrandVect(vector<double> tab){
	int indiceMax;
	double maxVal=-100.00;
	
	for(int i=0;i<tab.size();i++){
		if(tab[i]>maxVal){
			maxVal=tab[i];
			indiceMax=i;
		}
	}
	return indiceMax;
}	

int determinerPartieCle(string texte,int tC,int inc){	
	int lettre;
	int lettreMaxAnglais=101;//E 
	string sousTexte=genererTexte(texte,tC,inc);//genere sous texte avec la meme sous clé;
	vector<int> occTexte=nbOcc(sousTexte);//occurence de chaques lettres dans le sous texte
	vector<double> occTexteP=versPourcentage(occTexte);//traduction en pourcentage
	int lettreMax=plusGrandVect(occTexteP)+97;
	lettre=(lettreMax-lettreMaxAnglais+26)%26+97;
	
	return lettre;
}

string determinerCle(string txt,int tCle){
	string s="";
	for(int i=0;i<tCle;i++){
		cout<<(char)determinerPartieCle(txt,tCle,i);
		s+=(char)determinerPartieCle(txt,tCle,i);
	}
	return s;
}



int main(int argc, char* argv[]){
	
	string txt=extractionFichierTexte(argv[1]);
	string cle=argv[2];
	//string parametre=argv[3];
	string texte=traitementLigne(txt);
	
	int tCle=tailleCle(txt);

	//Affichage de la taille et de la clé pour le texte entré en paramètre
	cout<<"La taille de la Clé =>"<<tCle<<endl;
	cout<<"La clé est =>";
	//déclaration et affichage de la cle
	string a=determinerCle(texte,tCle);
	cout<<endl;
	/*
	cout<<dechiffrer(a,texte);
	cout<<endl;
	*/
		

}
