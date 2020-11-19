# TP DEVA

Ce repository sert à stocker les avancées liés au projet de Deva
du groupe n°2 en L2 Informatique à l'Université Polytechnique Hauts-de-France.

Si vous compilez avec GCC, il faut (pour le moment) compiler à l'aide de cette commande :

Compilation pour Windows :

```shell script
gcc -L lib/SDL2 -I include/SDL2 main.c src/create_app.c src/render.c -o TP -lmingw32 -lSDL2main -lSDL2
```

Une fois le programme compilé, vous l'éxécutez via la commande :

```shell script
./TP
```