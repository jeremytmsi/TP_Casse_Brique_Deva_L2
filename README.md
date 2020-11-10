# TP DEVA

Ce repository sert à stocker les avancées liés au projet de Deva
du groupe n°2 en L2 Informatique à l'Université Polytechnique Hauts-de-France.

Si vous compilez avec GCC, il faut (pour le moment) compiler à l'aide de cette commande :

```shell script
gcc main.c -o TP
```

Si vous utlisez CMake, il faut éxécuter ces commandes :

```shell script
mkdir build
cmake . -B build
cd build
make TP
```

Une fois le programme compilé, vous l'éxécutez via la commande :

```shell script
./TP
```