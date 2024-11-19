#include "complexe.h"
#include <math.h>           // Pour certaines fonctions trigo notamment

// Implantations de reelle et imaginaire
void reelle(double* a, complexe_t z){
    *a=z.reelle;
}

void imaginaire(double* b, complexe_t z){
    *b=z.imaginaire;
}

// Implantations de set_reelle et set_imaginaire
void set_reelle(complexe_t* z, double a){
    z->reelle=a;
}

void set_imaginaire(complexe_t* z, double b){
    z->imaginaire=b;
}

void init(complexe_t* z, double a, double b){
    z->reelle=a;
    z->imaginaire=b;
}


// Implantation de copie
void copie(complexe_t* resultat, complexe_t autre){
    resultat->reelle=autre.reelle;
    resultat->imaginaire=autre.imaginaire;
}

// Implantations des fonctions algébriques sur les complexes
void conjugue(complexe_t* resultat, complexe_t op){
    resultat->reelle=op.reelle;
    resultat->imaginaire=-1*op.imaginaire;
}

void ajouter(complexe_t* resultat, complexe_t gauche, complexe_t droite){
    resultat->reelle=gauche.reelle+droite.reelle;
    resultat->imaginaire=gauche.imaginaire+droite.imaginaire;
}

void soustraire(complexe_t* resultat, complexe_t gauche, complexe_t droite){
    resultat->reelle=gauche.reelle-droite.reelle;
    resultat->imaginaire=gauche.imaginaire-droite.imaginaire;
}

void multiplier(complexe_t* resultat, complexe_t gauche, complexe_t droite){
    resultat->reelle=gauche.reelle*droite.reelle-gauche.imaginaire*droite.imaginaire;
    resultat->imaginaire=gauche.reelle*droite.imaginaire+gauche.imaginaire*droite.reelle;
}

void echelle(complexe_t* resultat, complexe_t op, double facteur){
    resultat->reelle=op.reelle*facteur;
    resultat->imaginaire=op.imaginaire*facteur;
}

void puissance(complexe_t* resultat, complexe_t op, int exposant){
    if (exposant==0){
        resultat->reelle=1;
        resultat->imaginaire=0;
    }
    else{
        copie(resultat,op);
        for (int i=1; i < exposant;i++){
            multiplier(resultat,*resultat,op);
        }
    }
}

// Implantations du module et de l'argument
void module_carre(double* carré, complexe_t z){
    *carré=pow(z.reelle,2)+pow(z.imaginaire,2);
}

void module(double* mod, complexe_t z){
    double c;
    module_carre(&c, z);
    *mod=sqrt(c);
}

void argument(double* arg, complexe_t z){
    if (z.imaginaire!=0){
        double mod;
        module(&mod, z);
        *arg=2*atanf(z.imaginaire/(z.reelle+mod));
    }
    else if (z.reelle<0){
        *arg=M_PI;
    }
    else{
        *arg=0;
    }
}


