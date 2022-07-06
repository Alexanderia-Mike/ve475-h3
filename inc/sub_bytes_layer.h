/* [FILE]:          SUB_BYTES_LAYER_H
 
 * [Author]:        Alexanderia

 * [DESCRIPTION]:   implement the SubBytes layer

 * [DATE]:          June 11, 2021 

 */

#ifndef SUB_BYTES_LAYER_H
#define SUB_BYTES_LAYER_H

#include <stdio.h>
#include <stdlib.h>

/*************************************************************************************
 *  implement the SubButes layer
 *  @param inputs: the header pointer of the 128 bits input texts
 *                  <inputs>[i] (i=0-15) represents one byte
 *                  <inputs>[4k] (k=0-3) represents the header for the kth row
 *************************************************************************************/
void Sub_Bytes( unsigned char * inputs );

/* helper functions */
/*************************************************************************************
 *  substitute a single entry using S_box
 *  @param entry: the entry to be substituted
 *************************************************************************************/
unsigned char Sub_Single_Entry( const unsigned char entry );

#endif