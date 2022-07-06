/* [FILE]:          ADD_ROUND_KEY_LAYER_H
 
 * [Author]:        Alexanderia

 * [DESCRIPTION]:   implement the MixColumns layer

 * [DATE]:          June 11, 2021 

 */

#ifndef ADD_ROUND_KEY_LAYER_H
#define ADD_ROUND_KEY_LAYER_H

#include <stdio.h>
#include <stdlib.h>

/*************************************************************************************
 *  implement the AddRoundKey layer
 *  @param inputs: the header pointer of the 128 bits input texts
 *                  <inputs>[i] (i=0-15) represents one byte
 *                  <inputs>[4k] (k=0-3) represents the header for the kth row
 *  @param key: the key used to encrypt <inputs> in this layer. <key> is also
 *                  a header pointer of a 128-bit long text
 *************************************************************************************/
void Add_Round_Key( unsigned char * inputs, const unsigned char * key );

/*************************************************************************************
 *  implement key schedule algorithm that generates the next round of key based on
 *                  the previous round of key
 *  @param initial_key: the initial round of key, namely the master key. <initial_key> 
 *                  is also a header pointer of a 128-bit long text
 *  @param whole_key: the complete set of keys that would be applied to all rounds 
 *                  during AddRoundKey layer. In total the size is 4*44
 *************************************************************************************/
void Generate_Key( const unsigned char * initial_key, unsigned char * whole_key );

/*************************************************************************************
 *  flatten from 2-dimensional coordinates system to linear dimension coordinates in
 *                  matrix. The size of the matrix is 4*44
 *  @param first_coordinate: the row number of the entry in the matrix (0-3)
 *  @param second_coordinate: the column number of the entry in the matrix (0-43)
 *************************************************************************************/
unsigned int Whole_Key_Flatten_2_Dimension_To_1( const unsigned int first_coordinate, const unsigned int second_coordinate );

/*************************************************************************************
 *  flatten from 2-dimensional coordinates system to linear dimension coordinates in
 *                  matrix. The size of the matrix is 4*4
 *  @param first_coordinate: the row number of the entry in the matrix (0-3)
 *  @param second_coordinate: the column number of the entry in the matrix (0-3)
 *************************************************************************************/
unsigned int Single_Key_Flatten_2_Dimension_To_1( const unsigned int first_coordinate, const unsigned int second_coordinate );

/*************************************************************************************
 *  apply the transformation to the column with its index a multiple of 4
 *  @param input_column: the column that needs to be transformed. <input_column> is
 *                  actually a header pointer to the column, with <input_column>[k]
 *                  representing the [:, k] entry in the original matrix
 *  @param output_column: the column that is already transformed. <output_column> is
 *                  actually a header pointer to the column, with <output_column>[k]
 *                  representing the [:, k] entry in the original matrix. This is 
 *                  essentially the output of the function
 *************************************************************************************/
void Transformation( const unsigned char * input_column, unsigned char * output_column, unsigned int column_num );

/*************************************************************************************
 *  function already implemented in SubBytes layer. 
 *  see also: sub_bytes_layer.h
 *************************************************************************************/
unsigned char Sub_Single_Entry( const unsigned char entry );

/*************************************************************************************
 *  function already implemented in MixColumns layer. 
 *  see also: mix_columns_layer.h
 *************************************************************************************/
unsigned char Multiply_Entries( const unsigned char entry_1, const unsigned char entry_2 );

/*************************************************************************************
 *  extract the <key_round>th part of the key from <whole_key>
 *  @param whole_key: the complete set of keys that would be applied to all rounds 
 *                  during AddRoundKey layer. In total the size is 4*44
 *  @param key_round: the round number of the key (0-10). 
 *  @param ith_key: the <key_round>th round of key. <ith_key> is also a header pointer
 *                  of a 128-bit long text, represented in a matrix of size 4*4, 
 *                  which corresponds to <whole_key>[:, 4*<key_round>:4*<key_round>+3]
 *************************************************************************************/
void Extract_Ith_Key( const unsigned char * whole_key, const unsigned int key_round, unsigned char * ith_key );

#endif