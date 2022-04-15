#include <libc.h>

int stop(char t){
    return (t ==';') ? 1 : 0;
}

int strlenn(char * tab){                                 //str len compte la longueur du mot ou phrase
    int a = 0;
    for(int i = 0; tab[i] !='\0';i++){
        a++;
    }
    return a;
}

char *at(char * tab1, int l){
    int acc = 0;
    int inc = 0;

    char *nom = malloc(sizeof (char) * strlenn(tab1));
    for(int i = 0; tab1[i] != '\0';i++) {
        acc += (tab1[i] == ';') ? 1 : 0;
        if (acc == l) {
            switch (l) {
                case 0:
                    nom[inc] = tab1[i];
                    break;
                case 1:
                    i += stop(tab1[i]);
                    nom[inc] = tab1[i];
                    break;
                case 2:
                    i += stop(tab1[i]);
                    nom[inc] = tab1[i];
                    break;
                case 3:
                    i += stop(tab1[i]);
                    nom[inc] = tab1[i];
                    break;
                case 4:
                    i += stop(tab1[i]);
                    nom[inc] = tab1[i];
                    break;
            }
            inc++;
        }
    }
    return nom;
}

int main() {
    char tab1[] = "Pikachu;42;10;42;42";
    char tab2[] = "Raichu;84;20;84;84";
    //variable pour les valeurs alea
    int randd;
    int randd2;
    //permet d'avoir des valeurs aleatoire
    srand(time(NULL));

    printf("Pokemon %s has %s attack, %s defense, %s speed and %s health\n",at(tab1,0),at(tab1,1),at(tab1,2),at(tab1,3),at(tab1,4));
    printf("Pokemon %s has %s attack, %s defense, %s speed and %s health\n",at(tab2,0),at(tab2,1),at(tab2,2),at(tab2,3),at(tab2,4));
    int nop = 0;
    int heal1 = atoi(at(tab1,4));
    int heal2 = atoi(at(tab2,4));
    //printf("%s a %d\n",at(tab1,0),heal1);
    //printf("%s a %d\n",at(tab2,0),heal2);

    while(heal1 >0 && heal2 >0){
        //si pokemon1  plus rapide que pokemon2 alors tout le combat se fait dans la boucle if,
        //sinon en dehors
        if( at(tab1,2) <= at(tab2,2)){
            switch(nop){
                case 0:
                    nop = 1;
                    heal1 -= 20;
                    //on attribue une valeur aleatroire
                    randd2 = rand() % atoi(at(tab1,1));
                    printf("%s attacks for %d damage\n",at(tab2,0),randd2);
                    printf("%s blocks %d damage\n",at(tab1,0),atoi(at(tab1,2)));
                    (randd2 >= atoi(at(tab1,2)))? (heal1 -=randd2 - (atoi(at(tab1, 2)))):  (heal1 = heal1);
                    (heal1 <0) ? (heal1 = 0) : (heal1 = heal1);
                    switch(heal1){
                        case 0:
                            printf("%s loses %d health (%d left)\n",at(tab1,0),((atoi(at(tab1,2)) - randd2)> 0 ) ? 0 : (randd2 - atoi(at(tab1,2))),0);
                            printf("%s is KO\n",at(tab1,0));
                            printf("%s wins the fight\n",at(tab2,0));
                            break;
                        default:
                            printf("%s loses %d health (%d left)\n", at(tab1, 0),(randd2 > (atoi(at(tab1, 2)))) ? (randd2 - (atoi(at(tab1, 2)))) : 0, heal1);
                            break;
                    }

                case 1:
                    //printf("s1\n");
                    nop = 0;
                    //on attribue une valeur aleatroire
                    randd = rand() % atoi(at(tab1,1));
                    printf("%s attacks for %d damage\n",at(tab1,0),randd);
                    printf("%s blocks %s damage\n",at(tab2,0),at(tab2,2));
                    (randd >= atoi(at(tab2,2)))? (heal2 -=randd - (atoi(at(tab2, 2)))):  (heal2 = heal2);
                    (heal2 <0) ? (heal2 = 0) : (heal2 = heal2);
                    switch(heal2){
                        case 0:
                            printf("%s loses %d health (%d left)\n",at(tab2,0),((atoi(at(tab2,2)) - randd)> 0 ) ? 0 : (randd - atoi(at(tab2,2))),0);
                            printf("%s is KO\n",at(tab2,0));
                            printf("%s wins the fight\n",at(tab1,0));
                            break;
                        default:
                            printf("%s loses %d health (%d left)\n", at(tab2, 0),(randd > (atoi(at(tab2, 2)))) ? (randd - (atoi(at(tab2, 2)))) : 0, heal2);
                            break;
                    }
            }
        }
        //printf("%s commence avec %s de speed",at(tab2,0),at(tab2,2));
        switch(nop){
            case 0:
                //printf("s1\n");
                nop = 1;
                //on attribue une valeur aleatroire
                randd = rand() % atoi(at(tab1,1));
                printf("%s attacks for %d damage\n",at(tab1,0),randd);
                printf("%s blocks %s damage\n",at(tab2,0),at(tab2,2));
                (randd >= atoi(at(tab2,2)))? (heal2 -=randd - (atoi(at(tab2, 2)))):  (heal2 = heal2);
                (heal2 <0) ? (heal2 = 0) : (heal2 = heal2);
                switch(heal2){
                    case 0:
                        printf("%s loses %d health (%d left)\n",at(tab2,0),((atoi(at(tab2,2)) - randd)> 0 ) ? 0 : (randd - atoi(at(tab2,2))),0);
                        printf("%s is KO\n",at(tab2,0));
                        printf("%s wins the fight\n",at(tab1,0));
                        break;
                    default:
                        printf("%s loses %d health (%d left)\n", at(tab2, 0),(randd > (atoi(at(tab2, 2)))) ? (randd - (atoi(at(tab2, 2)))) : 0, heal2);
                        break;
                }
            case 1:
                nop = 0;
                heal1 -= 20;
                //on attribue une valeur aleatroire
                randd2 = rand() % atoi(at(tab1,1));
                printf("%s attacks for %d damage\n",at(tab2,0),randd2);
                printf("%s blocks %d damage\n",at(tab1,0),atoi(at(tab1,2)));
                (randd2 >= atoi(at(tab1,2)))? (heal1 -=randd2 - (atoi(at(tab1, 2)))):  (heal1 = heal1);
                (heal1 <0) ? (heal1 = 0) : (heal1 = heal1);
                switch(heal1){
                    case 0:
                        printf("%s loses %d health (%d left)\n",at(tab1,0),((atoi(at(tab1,2)) - randd2)> 0 ) ? 0 : (randd2 - atoi(at(tab1,2))),0);
                        printf("%s is KO\n",at(tab1,0));
                        printf("%s wins the fight\n",at(tab2,0));
                        break;
                    default:
                        printf("%s loses %d health (%d left)\n", at(tab1, 0),(randd2 > (atoi(at(tab1, 2)))) ? (randd2 - (atoi(at(tab1, 2)))) : 0, heal1);
                        break;
                }
        }
    }
    return 0;
}
