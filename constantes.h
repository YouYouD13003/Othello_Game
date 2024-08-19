//contient les constantes et les variables utilisées
#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED    
#define WINDOW_LENGTH 1280
#define WINDOW_HEIGHT 720
#define SIZE_SQUARE 90
#define X_COORDINATES 280
#define Y_COORDINATES 0
#define FICHIER "sauvgarde.othello" //le fichier qui contient la dernière partie joué
struct coup{
int x;
int y;
};
typedef struct coup coup;
enum{a,b,c,d,e,f,g,h};
enum{VIDE,NOIR,BLANC,NOIR_PROPOSE,BLANC_PROPOSE};
enum{HUMAIN,BOT};
enum{FACILE,MOYEN,DIFFICILE};

#endif // CONSTANTES_H_INCLUDED
