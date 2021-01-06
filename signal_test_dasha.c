#include <stdio.h>  
#include <signal.h>
#include <unistd.h> 

void f( int );

int main () {
    int i = 0;
    signal(SIGINT, f);

   while (i < 10)
    {
        printf ( "hello \n" );
        sleep (1);
        i++;
    }
}

void f( int signum )
{
    //signal ( SIGINT , f) ;
    printf ( " OUCH !\n ") ;
}