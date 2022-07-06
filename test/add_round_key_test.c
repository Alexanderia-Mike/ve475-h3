#include "add_round_key_layer.h"
#include "test.h"

int main()
{
    /* key_generation */
    unsigned char initial_key[16] = 
    {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
    };
    unsigned char whole_key[4*44] = { 0 };
    Generate_Key( initial_key, whole_key );
    printf( "the whole key: \n" );
    print_whole_key( whole_key );

    /* Extract_Ith_Key */
    unsigned char zero_th_round_key[16] = { 0 };
    unsigned char one_th_round_key[16] = { 0 };
    unsigned char two_th_round_key[16] = { 0 };
    Extract_Ith_Key( whole_key, 0, zero_th_round_key ) ;
    Extract_Ith_Key( whole_key, 1, one_th_round_key ) ;
    Extract_Ith_Key( whole_key, 2, two_th_round_key ) ;
    printf( "the zeroth key: \n" );
    print_matrix_in_int( zero_th_round_key );
    printf( "the oneth key: \n" );
    print_matrix_in_int( one_th_round_key );
    printf( "the twoth key: \n" );
    print_matrix_in_int( two_th_round_key );

    /* Add_Round_Key */
    unsigned char plain_text[] = 
    {
        '0', '1', '2', 0xd4,
        '4', '5', '6', 0xbf,
        '8', '9', 'a', 0x5d,
        'c', 'd', 'e', 0x30,
    };
    printf( "the plain text is: \n" );
    print_matrix_in_int( plain_text );
    Add_Round_Key( plain_text, one_th_round_key );
    printf( "the cipher text is: \n" );
    print_matrix_in_int( plain_text );

    return 0;
}