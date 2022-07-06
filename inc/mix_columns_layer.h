/* [FILE]:          MIX_COLUMNS_LAYER_H
 
 * [Author]:        Alexanderia

 * [DESCRIPTION]:   implement the MixColumns layer

 * [DATE]:          June 11, 2021 

 */

#ifndef MIX_COLUMNS_LAYER_H
#define MIX_COLUMNS_LAYER_H

#include <stdio.h>
#include <stdlib.h>

/*************************************************************************************
 *  implement the MixColumns layer
 *  @param inputs: the header pointer of the 128 bits input texts
 *                  <inputs>[i] (i=0-15) represents one byte
 *                  <inputs>[4k] (k=0-3) represents the header for the kth row
 *************************************************************************************/
void Mix_Columns( unsigned char * inputs );

/* helper functions */
/*************************************************************************************
 *  take the multiplication modulo x^8+x^4+x^3+x+1 over the field Z_2
 *  @param entry_1: one entry, which is a byte, representing a polynomial with coefficients
 *                  consisting of elements in the field Z_2 and degree less than 8
 *  @param entry_2: another entry, which is a byte, representing a polynomial with coefficients
 *                  consisting of elements in the field Z_2 and degree less than 8
 *  @return the modulo product
 *************************************************************************************/
unsigned char Multiply_Entries( const unsigned char entry_1, const unsigned char entry_2 );

/*************************************************************************************
 *  calculates the <bit_num>'s bit of the byte <entry>, counted from right
 *  @param entry: one entry, which is a byte, representing a polynomial with coefficients
 *                  consisting of elements in the field Z_2 and degree less than 8
 *  @param bit_num: an integer ranging from 0 to 7, indicating the position of the bit
 *                  that would be returned by the function, counted from right
 *  @return true if <bit_num>'s bit of the byte <entry> counted from right is 1, and
 *                  false otherwise
 *************************************************************************************/
unsigned int Take_Ith_Bit( const unsigned char entry, unsigned int bit_num );

/*************************************************************************************
 *  calculates the product of the polynomial represented by <entry> by x^<power>
 *  @param entry: a byte, representing a polynomial with coefficients consisting of
 *                  elements in the field Z_2 and degree less than 8
 *  @param power: the power of x
 *  @return the modulo product
 *************************************************************************************/
unsigned char Multiply_Entry_With_X_Power( const unsigned char entry, unsigned int power );

/*************************************************************************************
 *  calculates the product of the polynomial represented by <entry> by x
 *  @param entry: a byte, representing a polynomial with coefficients consisting of
 *                  elements in the field Z_2 and degree less than 8
 *  @return the modulo product
 *************************************************************************************/
unsigned char Multiply_Entry_With_X( const unsigned char entry );

#endif