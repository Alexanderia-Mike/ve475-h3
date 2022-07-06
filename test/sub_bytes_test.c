#include "sub_bytes_layer.h"
#include "test.h"

int main()
{
    unsigned char plain_text[] = 
    {
        '0', '1', '2', '3',
        '4', '5', '6', '7',
        '8', '9', 'a', 'b',
        'c', 'd', 'e', 'f',
    };
    print_matrix_in_int( plain_text );
    Sub_Bytes( plain_text );
    print_matrix( plain_text );
    printf( "\n" );
    print_matrix_in_int( plain_text );
    return 0;
}