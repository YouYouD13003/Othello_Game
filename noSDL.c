//contient les fonctions qui gèrent le tableau "grid" après le début d'une partie ainsi que les bots
#include <stdlib.h>
#include <stdio.h>
#include "SDLIA.h"
#include "constantes.h"
#include "noSDL.h"
void new_grid(int grid[][8]) //initialiser la grid
{
for(int i=0; i<8; i++)
{
for(int j=0; j<8; j++)
{
grid[i][j]=VIDE;
}
}
grid[3][d]=BLANC;
grid[3][e]=NOIR;
grid[4][d]=NOIR;
grid[4][e]=BLANC;
}
int case_existance(int ligne,int colonne) //vérifier si les coordonnées sont dans la grid
{
return ((colonne >= 0) && (colonne < 8) && (ligne >= 0) && (ligne < 8));
}
int valid_move(int grid[][8],int ligne,int colonne,int joueur) //vérifier si le coup est valide ou non
{
int i, j, trouver;
int caractere_joueur, caractere_adversaire;

if (joueur == BLANC)
{
caractere_joueur = BLANC;
caractere_adversaire = NOIR;
}
else
{
caractere_joueur = NOIR;
caractere_adversaire = BLANC;
}
if (!case_existance(ligne, colonne) || grid[ligne][colonne] !=VIDE)
return 0;

i = ligne-1;
trouver = 0;
while (case_existance(i, colonne) && grid[i][colonne] == caractere_adversaire)
{
i--;
trouver = 1;
}
if (case_existance(i, colonne) && grid[i][colonne] == caractere_joueur && trouver == 1)
return 1;

i = ligne + 1;
trouver = 0;
while (case_existance(i, colonne) && grid[i][colonne] == caractere_adversaire)
{
i++;
trouver = 1;
}
if (case_existance(i, colonne) && grid[i][colonne] == caractere_joueur && trouver == 1)
return 1;

j = colonne-1;
trouver = 0;
while (case_existance(ligne, j) && grid[ligne][j] == caractere_adversaire)
{
j--;
trouver = 1;
}
if (case_existance(ligne, j) && grid[ligne][j] == caractere_joueur && trouver == 1)
return 1;


j = colonne + 1;
trouver = 0;
while (case_existance(ligne, j) && grid[ligne][j] == caractere_adversaire)
{
j++;
trouver = 1;
}
if (case_existance(ligne, j) && grid[ligne][j] == caractere_joueur && trouver == 1)
return 1;

i = ligne - 1;
j = colonne - 1;
trouver = 0;
while (case_existance(i, j) && grid[i][j] == caractere_adversaire)
{
i--;
j--;
trouver = 1;
}
if (case_existance(i, j) && grid[i][j] == caractere_joueur && trouver == 1)
return 1;

i = ligne + 1;
j = colonne + 1;
trouver = 0;
while (case_existance(i, j) && grid[i][j] == caractere_adversaire)
{
i++;
j++;
trouver = 1;
}
if (case_existance(i, j) && grid[i][j] == caractere_joueur && trouver == 1)
return 1;

i = ligne - 1;
j = colonne + 1;
trouver = 0;
while (case_existance(i, j) && grid[i][j] == caractere_adversaire)
{
i--;
j++;
trouver = 1;
}
if (case_existance(i, j) && grid[i][j] == caractere_joueur && trouver == 1)
return 1;


i = ligne + 1;
j = colonne - 1;
trouver = 0;
while (case_existance(i, j) && grid[i][j] == caractere_adversaire)
{
i++;
j--;
trouver = 1;
}
if (case_existance(i, j) && grid[i][j] == caractere_joueur && trouver == 1)
return 1;
return 0;
}
void player_make_a_move(int grid[][8],int ligne,int colonne,int joueur)
{
int i, j;
int caractere_joueur, caractere_adversaire;

if (joueur == BLANC)
{
caractere_joueur = BLANC;
caractere_adversaire = NOIR;
}
else if(joueur==NOIR)
{
caractere_joueur =NOIR;
caractere_adversaire = BLANC;
}
grid[ligne][colonne] = caractere_joueur;

i = ligne - 1;
while (case_existance(i, colonne) && grid[i][colonne] == caractere_adversaire)
i--;
if (case_existance(i, colonne) && grid[i][colonne] == caractere_joueur)
{
i = ligne - 1;
while (grid[i][colonne] == caractere_adversaire)
{
grid[i][colonne] = caractere_joueur;
i--;
}
}

/* Vertical vers le bas */
i = ligne + 1;
while (case_existance(i, colonne) && grid[i][colonne] == caractere_adversaire)
i++;
if (case_existance(i, colonne) && grid[i][colonne] == caractere_joueur)
{
i = ligne + 1;
while (grid[i][colonne] == caractere_adversaire)
{
grid[i][colonne] = caractere_joueur;
i++;
}
}

/* Horizontal vers la gauche */
j = colonne - 1;
while (case_existance(ligne, j) && grid[ligne][j] == caractere_adversaire)
j--;
if (case_existance(ligne, j) && grid[ligne][j] == caractere_joueur)
{
j = colonne - 1;
while (grid[ligne][j] == caractere_adversaire)
{
grid[ligne][j] = caractere_joueur;
j--;
}
}

/* Horizontal vers la droite */
j = colonne + 1;
while (case_existance(ligne, j) && grid[ligne][j] == caractere_adversaire)
j++;
if (case_existance(ligne, j) && grid[ligne][j] == caractere_joueur)
{
j = colonne + 1;
while (grid[ligne][j] == caractere_adversaire)
{
grid[ligne][j] = caractere_joueur;
j++;
}
}

/* Diagonal \ vers le haut */
i = ligne - 1;
j = colonne - 1;
while (case_existance(i, j) && grid[i][j] == caractere_adversaire)
{
i--;
j--;
}
if (case_existance(i, j) && grid[i][j] == caractere_joueur)
{
i = ligne - 1;
j = colonne - 1;
while (grid[i][j] == caractere_adversaire)
{
grid[i][j] = caractere_joueur;
i--;
j--;
}
}

/* Diagonal \ vers le bas */
i = ligne + 1;
j = colonne + 1;
while (case_existance(i, j) && grid[i][j] == caractere_adversaire)
{
i++;
j++;
}
if (case_existance(i, j) && grid[i][j] == caractere_joueur)
{
i = ligne + 1;
j = colonne + 1;
while (grid[i][j] == caractere_adversaire)
{
grid[i][j] = caractere_joueur;
i++;
j++;
}
}

/* Diagonal / vers le haut */
i = ligne - 1;
j = colonne + 1;
while (case_existance(i, j) && grid[i][j] == caractere_adversaire)
{
i--;
j++;
}
if (case_existance(i, j) && grid[i][j] == caractere_joueur)
{
i = ligne - 1;
j = colonne + 1;
while (grid[i][j] == caractere_adversaire)
{
grid[i][j] = caractere_joueur;
i--;
j++;
}
}

/* Diagonal \ vers le bas */
i = ligne + 1;
j = colonne - 1;
while (case_existance(i, j) && grid[i][j] == caractere_adversaire)
{
i++;
j--;
}
if (case_existance(i, j) && grid[i][j] == caractere_joueur)
{
i = ligne + 1;
j = colonne - 1;
while (grid[i][j] == caractere_adversaire)
{
grid[i][j] = caractere_joueur;
i++;
j--;
}
}
}
void proposer_coup(int grid[][8],int joueur)
{
int caractere_joueur=(joueur==BLANC) ? BLANC_PROPOSE:NOIR_PROPOSE;
for(int i=0; i<8; i++)
{
for(int j=0; j<8; j++)
{
if(valid_move(grid,i,j,joueur))
grid[i][j]=caractere_joueur;
}
}
}
void clean_grid(int grid[][8])
{
for(int i=0; i<8; i++)
{
for(int j=0; j<8; j++)
{
if(grid[i][j]==BLANC_PROPOSE || grid[i][j]==NOIR_PROPOSE)
{
grid[i][j]=VIDE;
}
}
}
}
int game_over(int grid[][8]) // s'il y a encore de coup valide à jouer cette fonction envoit 1 sinon elle envoit 0
{
int valide=1;
for(int i=0; i<8; i++)
{
for(int j=0; j<8; j++)
{
if(valid_move(grid,i,j,BLANC) || valid_move(grid,i,j,NOIR))
{
valide=0;
break;
}
}
if(!valide)
break;
}
return valide;
}

int black_pieces_counter(int grid[][8]) // cette fonction calcule le nombre de pion noir dans la grid
{
int noir=0;
for(int i=0; i<8; i++)
{
for(int j=0; j<8; j++)
{
if(grid[i][j]==NOIR)
noir++;
}
}
return noir;
}

int white_pieces_counter(int grid[][8])// cette fonction calcule le nombre de pion blanc dans la grid
{
int blanc=0;
for(int i=0; i<8; i++)
{
for(int j=0; j<8; j++)
{
if(grid[i][j]==BLANC)
blanc++;
}
}
return blanc;
}
coup get_coup(int a,int b)
{
coup position;
for(int i=0; i<8; i++)
{
if(a>i*90+280 && a<(i+1)*90+280)
position.x=i;
if(b>i*90 && b<(i+1)*90)
position.y=i;
}
return position;
}
int encore_coup(int grid[][8],int joueur) // s'il y a encore de coup valide pour un joueur
{
int valide=0;
for(int i=0; i<8; i++)
{
for(int j=0; j<8; j++)
{
if(valid_move(grid,i,j,joueur))
{
valide=1;
break;
}
}
if(valide)
break;
}
return valide;
}
coup bot(int grid[][8],int couleur,int difficulte)
{
switch(difficulte)
{
case FACILE:
return bot_easy(grid,couleur);
break;
case MOYEN:
return bot_moyen(grid,couleur);
break;
}
}
coup bot_easy(int grid[][8],int couleur) // ce bot cherche de jouer un coup à l'interieur de la grid(il ne capture pas les extrémités: les lignes et les colonnes extérieures) sinon il cherche un coup possible
{
coup bot;
for(int i=1; i<=6; i++) //chercher de jouer un coup à l'interieur de la grid
{
for(int j=b; j<g; j++)
{
if(valid_move(grid,i,j,couleur))
{
bot.x=i;
bot.y=j;
return bot;
}
}
}
// s'il ne trouve pas un coup possible à l'interieur
for(int j=a; j<=h; j++)
{
if(valid_move(grid,0,j,couleur))
{
bot.x=0;
bot.y=j;
return bot;
}
if(valid_move(grid,7,j,couleur))
{
bot.x=7;
bot.y=j;
return bot;
}
}
for(int i=1;i<7;i++)
{
if(valid_move(grid,i,a,couleur))
{
bot.x=i;
bot.y=a;
return bot;
}
if(valid_move(grid,i,h,couleur))
{
bot.x=i;
bot.y=h;
return bot;
}
}
}

coup bot_moyen(int grid[][8],int couleur) //ce bot cherche de capturer les extrémités et de ne pas jouer si possible un coup qui vous aidera de les capturer
{
coup bot;
//vérifier s'il est possible de jouer un coup en (1,a) , (1,h) , (8,a) , (8,h)
if(valid_move(grid,0,a,couleur))
{
 bot.x=0;
 bot.y=a;
 return bot;
}
if(valid_move(grid,0,h,couleur))
{
 bot.x=0;
 bot.y=h;
 return bot;
}
if(valid_move(grid,7,a,couleur))
{
 bot.x=7;
 bot.y=a;
 return bot;
}
if(valid_move(grid,7,h,couleur))
{
 bot.x=7;
 bot.y=h;
 return bot;
}

//sinon chercher à jouer un coup en extrémités
for(int j=b; j<h; j++)
{
if(valid_move(grid,0,j,couleur))
{
bot.x=0;
bot.y=j;
return bot;
}
if(valid_move(grid,7,j,couleur))
{
bot.x=7;
bot.y=j;
return bot;
}
}
for(int i=1;i<7;i++)
{
if(valid_move(grid,i,a,couleur))
{
bot.x=i;
bot.y=a;
return bot;
}
if(valid_move(grid,i,h,couleur))
{
bot.x=i;
bot.y=h;
return bot;
}
}
//sinon jouer un coup à l'intérieur(la colonne c,f et la ligne 3,6)
for(int j=c;j<=f;j++)
{
if(valid_move(grid,2,j,couleur))
{
bot.x=2;
bot.y=j;
return bot;
}
if(valid_move(grid,5,j,couleur))
{
bot.x=5;
bot.y=j;
return bot;
}
}
for(int i=3;i<=4;i++)
{
if(valid_move(grid,i,c,couleur))
{
bot.x=i;
bot.y=c;
return bot;
}
if(valid_move(grid,i,f,couleur))
{
bot.x=i;
bot.y=f;
return bot;
}
}
//sinon jouer un coup dans les cases qui restent
for(int j=c;j<g;j++)
{
if(valid_move(grid,1,j,couleur))
{
bot.x=1;
bot.y=j;
return bot;
}
if(valid_move(grid,6,j,couleur))
{
bot.x=6;
bot.y=j;
return bot;
}
}
for(int i=2;i<6;i++)
{
if(valid_move(grid,i,b,couleur))
{
bot.x=i;
bot.y=b;
return bot;
}
if(valid_move(grid,i,g,couleur))
{
bot.x=i;
bot.y=g;
return bot;
}
}
if(valid_move(grid,1,b,couleur))
{
 bot.x=1;
 bot.y=b;
 return bot;
}
if(valid_move(grid,6,b,couleur))
{
 bot.x=6;
 bot.y=b;
 return bot;
}
if(valid_move(grid,1,g,couleur))
{
 bot.x=1;
 bot.y=g;
 return bot;
}
if(valid_move(grid,6,g,couleur))
{
 bot.x=6;
 bot.y=g;
 return bot;
}
}
