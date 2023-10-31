#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int cantidadLetras(const char*);
int __esAnagrama(const char* , const char* );
char esLetra(char);
char myToLower(char);

char myToLower(char c)
{
    if(c >= 65 && c <= 90){
        return (c + 32);
    }
    return c;
}

char esLetra(char c)
{
    if(((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
        return 1;

    return 0;
}


int cantidadLetras(const char* cad)
{
    int i = 0;
    while(*cad)
    {
        if(!esLetra(*cad))
            cad++;
        else
        {
            i++;
            cad++;
        }
    }
    return i;
}


int main()
{
    int letras = 0 , anagrama;
    char cad1[] = "Roma";
    char cad2[] = "Amor";


    letras = cantidadLetras(cad1);
    printf("las letras son: %d\n",letras);

    anagrama = __esAnagrama(cad1,cad2);

    if (anagrama)
        printf("es anagrama\n");
    else
        printf("no es anagrama\n");

    return 0;
}



int __esAnagrama(const char* cad1, const char* cad2)
{
    int i, cantletras1, cantletras2, vec1[26] = {0} , vec2[26] = {0};

    cantletras1 = cantidadLetras(cad1);
    cantletras2 = cantidadLetras(cad2);


    if(cantletras1 != cantletras2)
        return 0;

    while(*cad1 && *cad2)
    {
        while(!esLetra(*cad1))
            cad1++;
        while(!esLetra(*cad2))
            cad2++;

        vec1[myToLower(*cad1)- 97] ++;

        vec2[myToLower(*cad2)- 97] ++;

        cad1++;
        cad2++;
    }

    for(i=0 ; i<26 ; i++)
    {
        if(vec1[i] != vec2[i])
            return 0;
    }

    return 1;
}
