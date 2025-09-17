#include <stdio.h>
#include <string.h>

int quelleD(){
    //renvoie la dimension de grille voulue
    int x = 2;
    while (x != 3 && x != 5){
        printf("Veuillez choisir la dimension de la grille : (3 ou 5)\n");
        scanf("%d", &x);
    }
    return x;
}

void afficherGrille(char t[5][5], int dim){
    //affiche la grille
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            printf(" %c ", t[i][j] ? t[i][j] : '.');
        }
        printf("\n");
    }
}

int isWinL(char t[5][5], int dim, char joueur){
    //condition de victoire si il y a une ligne
    for (int i = 0; i < dim; i++){
        int win = 1;
        for (int j = 0; j < dim; j++){
            if (t[i][j] != joueur){
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }
    return 0;
}

int isWinC(char t[5][5], int dim, char joueur){
    //condition de victoire si il y a une colonne
    for (int i = 0; i < dim; i++){
        int win = 1;
        for (int j = 0; j < dim; j++){
            if (t[j][i] != joueur){
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }
    return 0;
}

int isWinD1(char t[5][5], int dim, char joueur){
    //condition de victoire si il y a une diagonale (haut vers bas)
    for (int i = 0; i < dim; i++){
        if (t[i][i] != joueur) return 0;
    }
    return 1;
}

int isWinD2(char t[5][5], int dim, char joueur){
    //condition de victoire si il y a une diagonale (bas vers haut)
    for (int i = 0; i < dim; i++){
        if (t[i][dim - 1 - i] != joueur) return 0;
    }
    return 1;
}

int isFull(int move, int dim){
    //condition si grille remplie
    return (move == dim*dim);
}

int main()
{
    int dim = quelleD();
    int move = 0;
    char joueurActu = 'O'; 

    
    char t[5][5] ={0};
    
    afficherGrille(t, dim);
    
    while (1){
        int ligne = 6, colonne = 6;
        
        joueurActu = (joueurActu == 'X') ? 'O' : 'X';
        
        //choix ligne
        while (ligne < 1 || ligne > dim){
            printf("Joueur %c, sur quelle ligne voulez-vous jouer ? (1 à %d)\n", joueurActu, dim);
            scanf("%d", &ligne);
        }
        
        //choix colonne
        while (colonne < 1 || colonne > dim){
            printf("Joueur %c, sur quelle colonne voulez-vous jouer ? (1 à %d)\n", joueurActu, dim);
            scanf("%d", &colonne);
        }
        
        //vérifier case
        if (t[ligne-1][colonne-1] == 0){
            t[ligne-1][colonne-1] = joueurActu;
            move++;
        } else{ 
            printf("Case déjà prise, rejouez.\n");
            continue;
        }
        
        afficherGrille(t, dim);
        
        //condition de victoire
        if (isWinL(t, dim, joueurActu) || isWinC(t, dim, joueurActu) ||
            isWinD1(t, dim, joueurActu) || isWinD2(t, dim, joueurActu)){
            printf("Le joueur %c a gagné !\n", joueurActu);
            break;
        }
        
        //condition match nul
        if (isFull(move, dim)){
            printf("Match nul !\n");
            break;
        }
    }
    
    return 0;
}
