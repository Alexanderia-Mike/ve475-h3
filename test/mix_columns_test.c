#include "mix_columns_layer.h"
#include "test.h"

int main()
{
    unsigned char plain_text[] = 
    {
        '0', '1', '2', 0xd4,
        '4', '5', '6', 0xbf,
        '8', '9', 'a', 0x5d,
        'c', 'd', 'e', 0x30,
    };
    print_matrix_in_int( plain_text );
    Mix_Columns( plain_text );
    print_matrix( plain_text );
    print_matrix_in_int( plain_text );

    /* test helper functions */
    /* Multiply_Entries */
    unsigned char entry_1 = 52; /* 00110100 */
    unsigned char entry_2 = 3;  /* 00000011 */
    printf( 
        "multiplying 00110100 and 00000011 gives %d\n", 
        Multiply_Entries( entry_1, entry_2 ) 
    );  /* should be 01011100 = 92 */

    /* Take_Ith_Bit */
    printf( "the 0th bit of 00110100 is %d\n", Take_Ith_Bit( entry_1, 0 ) );    /* should be 0 */
    printf( "the 2th bit of 00110100 is %d\n", Take_Ith_Bit( entry_1, 2 ) );    /* should be 1 */

    /* Multiply_Entry_With_X_Power */
    printf( 
        "multiplying 00110100 with x gives %d\n", 
        Multiply_Entry_With_X_Power( entry_1, 1 )
    );  /* should be 01101000 = 104 */
    printf( 
        "multiplying 00110100 with x^2 gives %d\n", 
        Multiply_Entry_With_X_Power( entry_1, 2 )
    );  /* should be 11010000 = 208 */
    printf( 
        "multiplying 00110100 with x^3 gives %d\n", 
        Multiply_Entry_With_X_Power( entry_1, 3 )
    );  /* should be 10100000 XOR 00011011 = 10111011 = 187 */

    /* Multiply_Entry_With_X */
    printf(
        "multiplying 00110100 with x gives %d\n",
        Multiply_Entry_With_X( entry_1 )
    );  /* should be 01101000 = 104 */

    return 0;
}