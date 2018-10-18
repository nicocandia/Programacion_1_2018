#include "User.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidNombre(char *nombre);
static int isValidEmail(char* email);

User*user_new(void)
{

    return (User*) malloc(sizeof(User));
}

void user_delet(User*this)
{
    free(this);
}

int user_setNombre(User*this,char*nombre)
{
    int retorno=-1;
    if(this!=NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int user_getNombre(User*this,char*nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

static int isValidNombre(char *nombre)
{
    return 1;
}



int user_setEmail(User*this,char*email)
{
    int retorno=-1;
    if(this!=NULL && isValidEmail(email))
    {
        strcpy(this->email,email);
        retorno=0;
    }
    return retorno;
}

int user_getEmail(User*this,char*email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(this->email,email);
        retorno=0;
    }
    return retorno;
}

static int isValidEmail(char* email)
{
    return 1;
}

int user_compareNombre(User* thisA,User*thisB)
{
    return strcmp(thisA->nombre,thisB->nombre);

}

void print_user(User*this)
{
    if(this!=NULL)
    {
        printf("\n%s -- %s -- %d\n ",this->nombre,this->email,this->id);
    }
}

User* user_newParametros(char* nombre,char* email)
{

    User*pUser=NULL;
    pUser=user_new();

    if(pUser==NULL ||
        user_setNombre(pUser,nombre)||
        user_setEmail(pUser,email))
    {
        user_delet(pUser);
        pUser=NULL;
    }

    return pUser;
}
