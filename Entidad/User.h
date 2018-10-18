#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
typedef struct
{
    int id;
    char nombre[33];
    char email[65];

}User;

User*user_new(void);

void user_delet(User*this);

int user_setNombre(User*this,char*nombre);

int user_getNombre(User*this,char*nombre);

int user_setEmail(User*this,char*email);


int user_getEmail(User*this,char*email);

int user_compareNombre(User* thisA,User*thisB);

void print_user(User*this);

User* user_newParametros(char* nombre,char* email);




#endif // USER_H_INCLUDED
