#ifndef noSDL_H_INCLUDED
#define noSDL_H_INCLUDED
//contient les prototypes des fonctions du fichier noSDL.h 
void new_grid(int grid[][8]);
int case_existance(int ligne,int colonne);
int valid_move(int grid[][8],int ligne,int colonne,int joueur);
void player_make_a_move(int grid[][8],int ligne,int colonne,int joueur);
void proposer_coup(int grid[][8],int joueur);
void clean_grid(int grid[][8]);
int game_over(int grid[][8]);
int black_pieces_counter(int grid[][8]);
int white_pieces_counter(int grid[][8]);
coup get_coup(int a,int b);
int encore_coup(int grid[][8],int joueur);
coup bot_easy(int grid[][8],int couleur);
coup bot_moyen(int grid[][8],int couleur);

#endif // noSDL_H_INCLUDED
