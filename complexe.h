#ifndef COMPLEX_H
#define COMPLEX_H

// Type utilisateur complexe_t
struct complexe_t
{
    double reelle;
    double imaginaire;
};
typedef struct complexe_t complexe_t;

// Fonctions reelle et imaginaire
/**
 * reelle
 *
 * Retourne la partie réelle d'un nombre complexe
 *
 * Paramètres :
 *   z      [in] Nombre complexe
 *
 * Post-condition : réelle est la partie réelle de z
 */
double reelle( complexe_t z);

/**
 * imaginaire
 * 
 * Retourne la partie imaginaire d'un nombre complexe
 *
 * Paramètres :
 *   z      [in] Nombre complexe
 *
 * Post-condition : imaginaire est la partie réelle de z
 */
double imaginaire (complexe_t z);

// Procédures set_reelle, set_imaginaire et init
/**
 * set_reelle
 *
 * Modifie la partie réelle d'un nombre complexe
 *
 * Paramètres :
 *   resultat       [in out] Nombre complexe pour lequel on modifie sa partie réelle
 *   a          [in]  Nouvelle partie réelle du nombre complexe
 *
 * Pré-conditions : z non null
 * Post-conditions : reelle(&z) = a
 */
void set_reelle(complexe_t* z, double a);

/**
 * set_imaginaire
 *
 * Modifie la partie imaginaire d'un nombre complexe
 *
 * Paramètres :
 *   resultat       [in out] Nombre complexe pour lequel on modifie sa partie imaginaire
 *   a          [in]  Nouvelle partie imaginaire du nombre complexe
 *
 * Pré-conditions : z non null
 * Post-conditions : imaginaire(&z) = b
 */
void set_imaginaire(complexe_t* z, double b);

/**
 * init
 *
 * Initialise un nombre complexe
 *
 * Paramètres :
 *   z       [in out] Nombre complexe que l'on initialise
 *   a          [in] Partie réelle du nombre complexe qu'on initialise
 *   b          [in] Partie imaginaire du nombre complexe qu'on initialise
 * Pré-conditions : z non null
 * Post-conditions : imaginaire(&z) = b et réelle(&z) = a
 */
void init(complexe_t* z, double a, double b);

// Procédure copie
/**
 * copie
 * Copie les composantes du complexe donné en second argument dans celles du premier
 * argument
 *
 * Paramètres :
 *   resultat       [out] Complexe dans lequel copier les composantes
 *   autre          [in]  Complexe à copier
 *
 * Pré-conditions : resultat non null
 * Post-conditions : resultat et autre ont les mêmes composantes
 */
void copie(complexe_t* resultat, complexe_t autre);

// Algèbre des nombres complexes
/**
 * conjugue
 * Calcule le conjugué du nombre complexe op et le stocke dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe dont on veut le conjugué
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : reelle(*resultat) = reelle(op), complexe(*resultat) = - complexe(op)
 */
void conjugue(complexe_t* resultat, complexe_t op);

/**
 * ajouter
 * Réalise l'addition des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche + droite
 */
void ajouter(complexe_t* resultat, complexe_t gauche, complexe_t droite);

/**
 * soustraire
 * Réalise la soustraction des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche - droite
 */
void soustraire(complexe_t* resultat, complexe_t gauche, complexe_t droite);

/**
 * multiplier
 * Réalise le produit des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche * droite
 */
void multiplier(complexe_t* resultat, complexe_t gauche, complexe_t droite);

/**
 * echelle
 * Calcule la mise à l'échelle d'un nombre complexe avec le nombre réel donné (multiplication
 * de op par le facteur réel facteur).
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe à mettre à l'échelle
 *   facteur        [in]  Nombre réel à multiplier
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = op * facteur
 */
void echelle(complexe_t* resultat, complexe_t op, double facteur);

/**
 * puissance
 * Calcule la puissance entière du complexe donné et stocke le résultat dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe dont on veut la puissance
 *   exposant       [in]  Exposant de la puissance
 *
 * Pré-conditions : resultat non-null, exposant >= 0
 * Post-conditions : *resultat = op * op * ... * op
 *                                 { n fois }
 */
void puissance(complexe_t* resultat, complexe_t op, int exposant);

// Module et argument
/**
 * module_carre
 *
 * Calcule et retourne le module au carré d'un nombre complexe
 *
 * Paramètres :
 *   z       [in] Nombre complexe dont on calcule le module au carré
 * Post-conditions : on retourne le module de z au carré
 */
double module_carre(complexe_t z);

/**
 * module
 *
 * Calcule et retourne le module d'un nombre complexe
 *
 * Paramètres :
 *   z       [in] Nombre complexe dont on calcule le module 
 * Post-conditions : module(z) = sqrt(module_carre(z))
 */
double module(complexe_t z);

/**
 * argument
 *
  * Calcule et retourne l'argument d'un nombre complexe
 *
 * Paramètres :
 *   z       [in] Nombre complexe dont on calcule l'argument
 * Prés-conditions : le nombre complexe z n'est pas nul
 * Post-conditions : argument d'un réel strictement positif vaut 0, argument d'un réel strictement négatif
 * vaut pi, on retourne l'argument du nombre complexe
 */
double argument(complexe_t z);


#endif // COMPLEXE_H



