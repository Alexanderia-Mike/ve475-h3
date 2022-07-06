/* [FILE]:          SHIFT_ROWS_LAYER_C
 
 * [Author]:        Alexanderia

 * [DESCRIPTION]:   implement the ShiftRows layer

 * [DATE]:          June 11, 2021 

 */

#include "shift_rows_layer.h"

void Shift_Rows( unsigned char * inputs )
{
    /* check whether the input is valid */
    if ( inputs == NULL )
    {
        printf( "Shift_Rows: the input is nullptr!\n" );
        exit( 0 );
    }

    /* shift each row in a loop */
    for ( int i = 0; i < 4; ++i )
    {
        Shift_Ith_Row( inputs + i * 4, i );
    }
    return;
}

void Shift_Ith_Row( unsigned char * row_pointer, unsigned int shift_unit )
{
    /* <new_positions>[i] means the new position of the entry i */
    unsigned int new_positions[4];
    for ( int i = 0; i < 4; ++i )
    {
        new_positions[i] = (i - shift_unit) % 4;
    }

    /* stored the shifted row in <temp_row> */
    unsigned char temp_row[4];
    for ( int i = 0; i < 4; ++i )
    {
        temp_row[new_positions[i]] = row_pointer[i];
    }

    /* assign the values in <temp_row> back to <row_pointer> */
    for ( int i = 0; i < 4; ++i )
    {
        row_pointer[i] = temp_row[i];
    }
    return;
}