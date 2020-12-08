//
// Created by lucas on 01/12/2020.
//

FILE * f;
f = fopen("deplac.don", "r" );
char TopNom[99][19] = {0};
for(int i = 0; i < 99;i++){
TopNom[i][0] = ' ';
}
int TopScore[99][0] = {0};
for(int i = 0; i < 99;i++){
TopScore[i][0] = 0;
}

for (int i=0; i<=100; i++){
if (score>TopScore[i][0]){
TopScore[i][0] = score1;
TopNom[i]=nom1;
}

for (int i=0; i<=99; i++){
if (TopScore[i][0]>0){
printf ("%c %d\", TopNom[i][0], TopScore[i][0]);
}
}
fclose(f);

}