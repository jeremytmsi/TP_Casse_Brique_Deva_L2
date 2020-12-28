# TP Développement d'applications 2020-2021 (Groupe 2)

Ce repository sert à stocker les avancées liés au projet de Deva
du groupe n°2 en L2 Informatique à l'Université Polytechnique Hauts-de-France.

## Règles du jeu
Vous avez un tableau de briques, une raquette et une balle à votre disposition. Le but du
jeu est de casser ces briques afin d'avoir le maximum de points. (1 brique cassée = 1 point).
Lorsque vous êtes en mode solo, vous devez faire bouger la raquette avec les flèches directionnelles
gauche ou droite (ne surtout pas appuyer sur les touches "q" et "d" en mode solo sous peine de faire planter
le jeu).

Lorsque vous êtes en mode duo, vouis pouvez contrôler une raquette à l'aide des flèches directionnelles
et l'autre raquette peut être contrôlée via les touches "q" (pour la gauche) et "d" (pour la droite).

## Compilation

### Prérequis :
- Avoir GCC et Make installés sur le système

Une fois ces prérequis satisfaits, il suffit d'éxécuter cette commande (fonctionne uniquement avec Windows) :

```shell script
make all
```

## Exécution du jeu
Une fois le programme compilé, si vous voulez jouer en mode solo, il faut le lancer via cette commande :

```shell script
.\Casse_brique.exe solo
```
Pour le mode duo, il suffit de taper cette commande :
```shell script
.\Casse_brique.exe duo
```
