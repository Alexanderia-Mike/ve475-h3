#include "shift_rows_layer.h"
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
    Shift_Rows( plain_text );
    print_matrix( plain_text );
    return 0;
}