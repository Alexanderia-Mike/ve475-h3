/* [FILE]:          ADD_ROUND_KEY_LAYER_C
 
 * [Author]:        Alexanderia

 * [DESCRIPTION]:   implement the ShiftRows layer

 * [DATE]:          June 11, 2021 

 */

#include "add_round_key_layer.h"

void Add_Round_Key( unsigned char * inputs, const unsigned char * key )
{
    for ( int i = 0; i < 16; ++i )
    {
        inputs[i] ^= key[i];
    }
    return;
}

void Generate_Key( const unsigned char * initial_key, unsigned char * whole_key )
{
    for ( int column_num = 0; column_num < 44; ++column_num )
    {
        /* for the first round, directly take the initial key */
        if ( column_num < 4 )
        {
            for ( int row_num = 0; row_num < 4; ++row_num )
            {
                whole_key[Whole_Key_Flatten_2_Dimension_To_1( row_num, column_num )] = 
                initial_key[Single_Key_Flatten_2_Dimension_To_1( row_num, column_num )];
            }
            continue;
        }
        /* for rest columns, if <column_num> is not a multiple of 4, K[:, col] = K[:, col-4] ^ K[:, col-1] */
        if ( column_num % 4 != 0 )
        {
            for ( int row_num = 0; row_num < 4; ++row_num )
            {
                whole_key[Whole_Key_Flatten_2_Dimension_To_1( row_num, column_num )] =
                whole_key[Whole_Key_Flatten_2_Dimension_To_1( row_num, column_num - 4 )] ^ 
                whole_key[Whole_Key_Flatten_2_Dimension_To_1( row_num, column_num - 1 )];
            }
            continue;
        }
        /* else if <column_num> is indeed a multiple of 4, K[:, col] = K[:, col-4] ^ T(K[:, col-1]) */
        unsigned char original_column[4] = 
        {
            whole_key[Whole_Key_Flatten_2_Dimension_To_1( 0, column_num - 1 )],
            whole_key[Whole_Key_Flatten_2_Dimension_To_1( 1, column_num - 1 )],
            whole_key[Whole_Key_Flatten_2_Dimension_To_1( 2, column_num - 1 )],
            whole_key[Whole_Key_Flatten_2_Dimension_To_1( 3, column_num - 1 )]
        };

        unsigned char transformed_column[4] = { 0 };
        Transformation( original_column, transformed_column, column_num );

        for ( int row_num = 0; row_num < 4; ++row_num )
        {
            whole_key[Whole_Key_Flatten_2_Dimension_To_1( row_num, column_num )] =
            whole_key[Whole_Key_Flatten_2_Dimension_To_1( row_num, column_num - 4 )] ^ 
            transformed_column[row_num];
        }
    }
}

unsigned int Whole_Key_Flatten_2_Dimension_To_1( const unsigned int first_coordinate, const unsigned int second_coordinate )
{
    /* check the validity of two inputs */
    if ( first_coordinate > 3 )
    {
        printf( 
            "Flatten_2_Dimension_To_1: first_coordinate (%d) exceeds the boundary (0-3)!\n", 
            first_coordinate 
        );
        exit( 0 );
    }
    if ( second_coordinate > 43 )
    {
        printf( 
            "Flatten_2_Dimension_To_1: second_coordinate (%d) exceeds the boundary (0-43)!\n", 
            second_coordinate 
        );
        exit( 0 );
    }

    /* calculate the linear coordinate */
    return first_coordinate * 44 + second_coordinate;
}

unsigned int Single_Key_Flatten_2_Dimension_To_1( const unsigned int first_coordinate, const unsigned int second_coordinate )
{
    /* check the validity of two inputs */
    if ( first_coordinate > 3 )
    {
        printf( 
            "Flatten_2_Dimension_To_1: first_coordinate (%d) exceeds the boundary (0-3)!\n", 
            first_coordinate 
        );
        exit( 0 );
    }
    if ( second_coordinate > 3 )
    {
        printf( 
            "Flatten_2_Dimension_To_1: second_coordinate (%d) exceeds the boundary (0-3)!\n", 
            second_coordinate 
        );
        exit( 0 );
    }

    /* calculate the linear coordinate */
    return first_coordinate * 4 + second_coordinate;
}

void Transformation( const unsigned char * input_column, unsigned char * output_column, unsigned int column_num )
{
    /* top shift by 1 */
    output_column[0] = input_column[1];
    output_column[1] = input_column[2];
    output_column[2] = input_column[3];
    output_column[3] = input_column[0];

    /* SubBytes operation */
    for ( int i = 0; i < 4; ++i )
    {
        output_column[i] = Sub_Single_Entry( output_column[i] );
    }

    /* XOR first bit with r(col) = 00000010^{(col-4)/4} */
    unsigned char r_i;
    if ( column_num == 4 )
    {
        r_i = 0;
    }
    else
    {
        r_i = 2;
    }
    for ( int i = 0; i < ( ( (int) column_num ) - 4) / 4 - 1; ++i )
    {
        r_i = Multiply_Entries( r_i, 2 );   /* should repeat power-1 times */
    }
    output_column[0] ^= r_i;
    return;
}

void Extract_Ith_Key( const unsigned char * whole_key, const unsigned int key_round, unsigned char * ith_key )
{
    for ( int i = 0; i < 16; ++i )
    {
        unsigned int whole_key_row_num = i % 4;
        unsigned int whole_key_column_num = 4 * key_round + i / 4;
        ith_key[i] = whole_key[Whole_Key_Flatten_2_Dimension_To_1( whole_key_row_num, whole_key_column_num )];
    }
    return;
}