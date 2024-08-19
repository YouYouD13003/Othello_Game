#ifndef SDLIA_H_INCLUDED
#define SDLIA_H_INCLUDED
// contient les prototypes des fonctions du fichier .c et le tableau qui représente la grid 8x8
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

int grid[8][8];
void show_move_and_result(SDL_Surface *ecran);
void show_move_propose(SDL_Surface *ecran);
void show_winner(SDL_Surface *ecran);
void play(SDL_Surface *ecran,int reprendre);
void play_vs_bot(SDL_Surface *ecran,int reprendre);

#endif // SDLIA_H_INCLUDED
