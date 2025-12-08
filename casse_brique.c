#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
int main(int argc, char* argv[]) {
    srand(time(NULL));
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur SDL_Init : %s\n", SDL_GetError());
        return 1;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Fond du jeu",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500, 700,0);
    if (!window) {
        printf("Erreur création fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Création du renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur création renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // fond galaxie
    SDL_Surface* imageSurface_galaxie= IMG_Load("galaxy.jpg");
    if (!imageSurface_galaxie) {
        printf("Erreur chargement image : %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    // Création texture
    SDL_Texture* imageTexture_galaxie = SDL_CreateTextureFromSurface(renderer, imageSurface_galaxie);
    SDL_FreeSurface(imageSurface_galaxie);

    if (!imageTexture_galaxie) {
        printf("Erreur texture image : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int x_galaxie = 0;
    int y_galaxie =  0;
    SDL_Rect galaxie = {x_galaxie, y_galaxie, 500, 700}; // x = (1200-200)/2, y = (700-150)/2 57 longueur 20largeur

    // astronaute
    SDL_Surface* imageSurface_astronaute = IMG_Load("astronaute.png");
    if (!imageSurface_astronaute) {
        printf("Erreur chargement image : %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    // Création texture
    SDL_Texture* imageTexture_astronaute = SDL_CreateTextureFromSurface(renderer, imageSurface_astronaute);
    SDL_FreeSurface(imageSurface_astronaute);

    if (!imageTexture_astronaute) {
        printf("Erreur texture image : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int x_astronaute = 300;
    int y_astronaute = 450;
    SDL_Rect astronaute = {x_astronaute, y_astronaute, 200, 200}; // x = (1200-200)/2, y = (700-150)/2 57 longueur 20largeur


    // Raquette au centre en bas
    SDL_Surface* imageSurface = IMG_Load("paddle.png");
    if (!imageSurface) {
        printf("Erreur chargement image : %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    // Création texture
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    if (!imageTexture) {
        printf("Erreur texture image : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    int x_padd=200;
    int y_padd=600;
    SDL_Rect rect = {x_padd, y_padd, 100, 50};





    // brique  
    SDL_Surface* imageSurface_brique = IMG_Load("brique1.png");
    if (!imageSurface_brique) {
        printf("Erreur chargement image : %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    // Création texture
    SDL_Texture* imageTexture_brique = SDL_CreateTextureFromSurface(renderer, imageSurface_brique);
    SDL_FreeSurface(imageSurface_brique);

    if (!imageTexture_brique) {
        printf("Erreur texture image : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int x_brique = 50;
    int y_brique =  100;
    SDL_Rect brique = {x_brique, y_brique, 57, 40}; // x = (1200-200)/2, y = (700-150)/2 57 longueur 20largeur

    int liste[5][7];
    for (int i=0;i<5;i++){
        for (int j=0;j<7;j++){
            liste[i][j]=1;
        }
    }




    // balle
    SDL_Surface* imageSurface_balle = IMG_Load("balle.png");
    if (!imageSurface_balle) {
        printf("Erreur chargement image : %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    // Création texture
    SDL_Texture* imageTexture_balle = SDL_CreateTextureFromSurface(renderer, imageSurface_balle);
    SDL_FreeSurface(imageSurface_balle);

    if (!imageTexture_balle) {
        printf("Erreur texture image : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    //pour la balle
    int x_balle=235;
    int y_balle=570;
    SDL_Rect balle = {x_balle, y_balle, 30,30};


    
    // vie  
    
    SDL_Surface* imageSurface_vie = IMG_Load("love.png");
    if (!imageSurface_vie) {
        printf("Erreur chargement image : %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    // Création texture
    SDL_Texture* imageTexture_vie = SDL_CreateTextureFromSurface(renderer, imageSurface_vie);
    SDL_FreeSurface(imageSurface_vie);

    if (!imageTexture_vie) {
        printf("Erreur texture image : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int x_vie = 380;
    int y_vie =  10;
    SDL_Rect vie = {x_vie, y_vie,30, 30}; // x = (1200-200)/2, y = (700-150)/2 57 longueur 20largeur


    // vie_morte  
    SDL_Surface* imageSurface_vie_morte = IMG_Load("love_morte.png");
    if (!imageSurface_vie_morte) {
        printf("Erreur chargement image : %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    // Création texture
    SDL_Texture* imageTexture_vie_morte = SDL_CreateTextureFromSurface(renderer, imageSurface_vie_morte);
    SDL_FreeSurface(imageSurface_vie_morte);

    if (!imageTexture_vie_morte) {
        printf("Erreur texture image : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int x_vie_morte = 380;
    int y_vie_morte =  10;
    SDL_Rect vie_morte = {x_vie_morte, y_vie_morte,30, 30}; // x = (1200-200)/2, y = (700-150)/2 57 longueur 20largeur

    //global
    int nbr_vie=3;
    int a=0;
    int avancer_balle=0;
    SDL_Event evenement;
    while(a==0){
        SDL_PollEvent(&evenement);
        if (evenement.type==SDL_WINDOWEVENT){// clic sur la croix de la fenêtre
            if (evenement.window.event == SDL_WINDOWEVENT_CLOSE){
                a=3;
            }
        } 
        if (evenement.type==SDL_KEYDOWN){
            if (evenement.key.keysym.sym==SDLK_RETURN){
                a++;
            }
        }
        SDL_RenderCopy(renderer, imageTexture_galaxie, NULL, &galaxie);
        SDL_RenderCopy(renderer, imageTexture_astronaute, NULL, &astronaute);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
    while(a==1 && nbr_vie!=0) {
        SDL_PollEvent(&evenement);
        printf("%d\n", a);
        if (evenement.type==SDL_WINDOWEVENT){// clic sur la croix de la fenêtre
            if (evenement.window.event == SDL_WINDOWEVENT_CLOSE){

            }
        } 
        if (evenement.type==SDL_KEYDOWN){
            if (evenement.key.keysym.sym==SDLK_ESCAPE){
                a++;
            }

            if (evenement.key.keysym.sym==SDLK_UP){
                if (avancer_balle==0){
                    avancer_balle=rand()%2 + 1;
                }
            }
            if(evenement.key.keysym.sym==SDLK_LEFT){
                if(rect.x>0){
                    rect.x-=10;
                }
            }
            if(evenement.key.keysym.sym==SDLK_RIGHT){
                if(400>rect.x){
                    rect.x+=10;
                }
            }
            
        }
    if (avancer_balle==0){
        balle.x=rect.x+35;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, imageTexture_galaxie, NULL, &galaxie);
    SDL_RenderCopy(renderer, imageTexture, NULL, &rect);
    SDL_RenderCopy(renderer, imageTexture_balle, NULL, &balle);

    //creation vie 
    
    for (int m=0;m<3-nbr_vie;m++) {
        SDL_RenderCopy(renderer, imageTexture_vie_morte, NULL, &vie_morte);
        vie.x+=40; // espace entre les icônes de vie
        vie_morte.x+=40;
    }
    vie_morte.x=380;
    
    for (int v=0;v<nbr_vie;v++) {
        SDL_RenderCopy(renderer, imageTexture_vie, NULL, &vie);
        vie.x+=40; // espace entre les icônes de vie
    }
    vie.x=380;
    
    //creation brique
    for (int i=0;i<5;i++){
        for (int j=0;j<7;j++){
            if (liste[i][j]==1){
                SDL_RenderCopy(renderer, imageTexture_brique, NULL, &brique);
            }
            brique.x+=57;
        }
        brique.x=50;
        brique.y+=40;
    }
    brique.y=100;
    
    SDL_RenderPresent(renderer);
    if(avancer_balle==1){
        balle.y-=5;
        for (int i=0;i<5;i++){
            for (int j=0;j<7;j++){
                if(brique.x+57 >=balle.x+15 &&balle.x+15>=brique.x && brique.y+30>= balle.y && balle.y>brique.y-30){
                    if (liste[i][j]==1){
                        liste[i][j]=0;
                        avancer_balle=2;
                    }
                    
                }
                brique.x+=57;
            }
            brique.x=50;
            brique.y+=40;
        }
        brique.y=100;
        if (balle.y==30){
            avancer_balle=2;
        }
    }
    else if(avancer_balle==2){
        balle.y+=5;
        if (rect.y+20>=balle.y && balle.y>=rect.y-30 && rect.x+100>=balle.x && balle.x>=rect.x){
            avancer_balle=1;
        }
        else if (balle.y==670){
            balle.y=570;
            avancer_balle=0;
            nbr_vie--;
        }
    }
        
    // Attendre 3 secondes
    SDL_Delay(10);
    }
    SDL_RenderClear(renderer);
    while(a==1){
        SDL_PollEvent(&evenement);
        if (evenement.type==SDL_WINDOWEVENT){// clic sur la croix de la fenêtre
            if (evenement.window.event == SDL_WINDOWEVENT_CLOSE){

            }
        } 
        if (evenement.type==SDL_KEYDOWN){
            if (evenement.key.keysym.sym==SDLK_ESCAPE){
                a++;
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
    SDL_RenderClear(renderer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}