# Alex Casse-brique

Un jeu de casse-briques classique développé avec **Visual Studio Code**.  
Le but est de détruire toutes les briques à l’aide d’une balle, sans la laisser tomber.

---

## Règles du jeu

- Le joueur contrôle une raquette en bas de l’écran avec soit les touches fléchées, soit les touches **Q, D, Z**  
- La balle rebondit sur les murs, la raquette et les briques  
- Chaque brique détruite rapporte des points  
- La partie est perdue si la balle touche le bas de l’écran  
- La partie est gagnée lorsque toutes les briques sont détruites

---

## Technologies utilisées

- **IDE** : Visual Studio Code  
- **Langage** : C  

---

## Lancer le jeu

### Commande de compilation

```
gcc -I C:/Users/Lenovo/Documents/projet_casse_brique/SDL2-devel-2.32.4-mingw/SDL2-2.32.4/x86_64-w64-mingw32/include \
    main.c game.c galaxie.c astronaute.c paddle_img.c balle_img.c brique_img.c vie_img.c score.c message_debut.c message_fin.c \
    -L C:/Users/Lenovo/Documents/projet_casse_brique/SDL2-devel-2.32.4-mingw/SDL2-2.32.4/x86_64-w64-mingw32/lib \
    -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -mwindows -o main.exe
```
