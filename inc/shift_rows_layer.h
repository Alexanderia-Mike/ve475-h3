/* [FILE]:          SHIFT_ROWS_LAYER_H
 
 * [Author]:        Alexanderia

 * [DESCRIPTION]:   implement the ShiftRows layer

 * [DATE]:          June 11, 2021 

 */

#ifndef SHIFT_ROWS_LAYER_H
#define SHIFT_ROWS_LAYER_H

#include <stdio.h>
#include <stdlib.h>

/*************************************************************************************
 *  implement the ShiftRows layer
 *  @param inputs: the header pointer of the 128 bits input texts
 *                  <inputs>[i] (i=0-15) represents one byte
 *                  <inputs>[4k] (k=0-3) represents the header for the kth row
 *************************************************************************************/
void Shift_Rows( unsigned char * inputs );

/* helper functions */
/*************************************************************************************
 *  shift the row pointed by <row_pointer> elements to the left by <shiift_unit> units
 *  @param row_pointer: the pointer to the specific row. <row_pointer>[i] (i=0-3) is 
 *                  the four entries in that row.
 *  @param shift_unit: the unit by which the elements are shifted to left.
 *************************************************************************************/
void Shift_Ith_Row( unsigned char * row_pointer, unsigned int shift_unit );

#endif