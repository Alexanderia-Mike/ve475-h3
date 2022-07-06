#include "test.h"

void print_matrix( unsigned char * plain_text )
{
    if ( plain_text == NULL )
    {
        printf( "print_matrix: empty matrix!\n" );
        exit( 0 );
    }
    for ( int i = 0; i < 16; ++i )
    {
        printf( "%c", plain_text[i] );
        if ( i % 4 == 3 )
        {
            printf( "\n" );
        }
    }
    return;
}

void print_matrix_in_int( unsigned char * plain_text )
{
    if ( plain_text == NULL )
    {
        printf( "print_matrix: empty matrix!\n" );
        exit( 0 );
    }
    for ( int i = 0; i < 16; ++i )
    {
        printf( "%d\t", (unsigned int) plain_text[i] );
        if ( i % 4 == 3 )
        {
            printf( "\n" );
        }
    }
    return;
}

void print_whole_key( unsigned char * whole_key )
{
    if ( whole_key == NULL )
    {
        printf( "print_whole_key: empty input pointer!\n" );
        exit( 0 );
    }
    for ( int i = 0; i < 4*44; ++i )
    {
        printf( "%d\t", (unsigned int) whole_key[i] );
        if ( i % 44 == 43 )
        {
            printf( "\n" );
        }
        else if ( i % 4 == 3 )
        {
            printf( "|\t" );
        }
    }
    return;
}