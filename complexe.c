#include "complexe.h"
#include <math.h>           // Pour certaines fonctions trigo notamment

// Implantations de reelle et imaginaire
void reelle(float* a, complexe_t z){
    *a=z.reelle;
}

void imaginaire(float* b, complexe_t z){
    *b=z.imaginaire;
}

// Implantations de set_reelle et set_imaginaire
void set_reelle(complexe_t* z, float a){
    z->reelle=a;
}

void set_reelle(complexe_t* z, float b){
    z->imaginaire=b;
}

void init(complexe_t* z, float a, float b){
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
void module_carre(float* carré,complexe_t z){
    *carré=1;
}

/** FONCTION module À IMPLANTER **/

/** FONCTION argument À IMPLANTER **/


