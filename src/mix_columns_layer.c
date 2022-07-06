/* [FILE]:          SHIFT_ROWS_LAYER_C
 
 * [Author]:        Alexanderia

 * [DESCRIPTION]:   implement the ShiftRows layer

 * [DATE]:          June 11, 2021 

 */

#include "mix_columns_layer.h"

/* the factor C(x) in MixColumns layer */
const unsigned char C_x[4][4] =
{
    { 2, 3, 1, 1 },
    { 1, 2, 3, 1 },
    { 1, 1, 2, 3 },
    { 3, 1, 1, 2 }
};

/* define bool types */
const unsigned int true = 1;
const unsigned int false = 0;

void Mix_Columns( unsigned char * inputs )
{
    /* declaration */
    unsigned char inputs_buffer[16] = { 0 };

    /* calculate the result matrix using matrix multiplication rules */
    for ( int i = 0; i < 16; ++i )
    {
        unsigned int c_x_row_num = i / 4;
        unsigned int inputs_column_num = i % 4;

        /* inputs_buffer[i] = sum_{j=0}^3 C_x[row_num][j] * inputs[j][column_num] */
        for ( int j = 0; j < 4; ++j )
        {
            inputs_buffer[i] ^= Multiply_Entries( C_x[c_x_row_num][j], inputs[4 * j + inputs_column_num] );
        }
    }

    /* assign values in buffer back to <inputs> */
    for ( int i = 0; i < 16; ++i )
    {
        inputs[i] = inputs_buffer[i];
    }
    return;
}

unsigned char Multiply_Entries( const unsigned char entry_1, const unsigned char entry_2 )
{
    /* declaration */
    unsigned char product = 0;
    unsigned char temporary_term;

    /* multiply <entry_1> with bits in <entry_2> one by one */
    for ( int i = 0; i < 8; ++i )
    {
        unsigned int bit = Take_Ith_Bit( entry_2, (unsigned int) i );
        if ( bit == 0 )
        {
            continue;
        }
        /* multiply <entry_1> by x^i */
        temporary_term = Multiply_Entry_With_X_Power( entry_1, i );
        product ^= temporary_term;
    }
    return product;
}

unsigned int Take_Ith_Bit( const unsigned char entry, unsigned int bit_num )
{
    /* check the validity of <bit_num> */
    if ( bit_num > 7 )
    {
        printf( "Take_Ith_Bit: bit num (%d) exceeds the range (0-7)!\n", bit_num );
        exit( 0 );
    }

    /* calculate the bit */
    unsigned char shifted_entry = entry >> bit_num;
    unsigned char bit = shifted_entry & 01;
    if ( bit == 0 )
    {
        return false;
    }
    else
    {
        return true;
    }
}

unsigned char Multiply_Entry_With_X_Power( const unsigned char entry, unsigned int power )
{
    /* declaration */
    unsigned char product = entry;

    /* iteratively multiply <entry> with x */
    for ( int i = 0; i < power; ++i )
    {
        product = Multiply_Entry_With_X( product );
    }
    return product;
}

unsigned char Multiply_Entry_With_X( const unsigned char entry )
{
    /* check whether the polynomial would overflow */
    if ( Take_Ith_Bit( entry, 7 ) == 0 )
    {
        return entry << 1;
    }
    return ( entry << 1 ) ^ 0x1b;
}