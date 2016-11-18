 /************************************************************************
   Program: Solar 
   Author: Charles Bonn and Christian Sieh
   Date: 
   Description:    Shape main class
   Known bugs/missing features:
   Modifications:
   Date                Comment            
   ----    ------------------------------------------------
 ************************************************************************/
#include "Shape.h"

 /************************************************************************
   Function: Shape constructor
   Author: Charles Bonn and Christian Sieh
   Description: Shape Constructor
   Parameters:
 ************************************************************************/
Shape::Shape( float di, float y, float da, string n, string i, float c[4])
{
    distance = di;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i;
    type = "Shape"; 
    copy(c, c + 4, color);
}

 /************************************************************************
   Function: shape Deconstructor
   Author: Charles Bonn and Christian Sieh
   Description: shape deconstructor
   Parameters:
 ************************************************************************/
Shape::~Shape()
{
}

 /************************************************************************
   Function: getNumBytesPerRow
   Author: Charles Bonn And christian Sieh
   Description: Row are word aligned
   Parameters:
	int NumCols - number of columns
 ************************************************************************/
inline int Shape::GetNumBytesPerRow( int NumCols ) const
{
    return ( ( 3 * NumCols + 3 ) >> 2 ) << 2;
}

 /************************************************************************
   Function: readShort
   Author: Charles Bonn and Christian Sieh
   Description: read a 16-bit integer from the input file
   Parameters:
	FILE* infile - the input file
 ************************************************************************/
short Shape::readShort( FILE* infile ) const
{
    unsigned char lowByte, hiByte;
    lowByte = fgetc( infile );			// Read the low order byte (little endian form)
    hiByte = fgetc( infile );			// Read the high order byte

    // Pack together
    short ret = hiByte;
    ret <<= 8;
    ret |= lowByte;
    return ret;
}

 /************************************************************************
   Function: readLong 
   Author: charles Bonn and Christian Sieh
   Description: read a 32-bit integer from the input file
   Parameters:
 ************************************************************************/
int Shape::readLong( FILE* infile ) const
{
    unsigned char byte0, byte1, byte2, byte3;
    byte0 = fgetc( infile );			// Read bytes, low order to high order
    byte1 = fgetc( infile );
    byte2 = fgetc( infile );
    byte3 = fgetc( infile );

    // Pack together
    int ret = byte3;
    ret <<= 8;
    ret |= byte2;
    ret <<= 8;
    ret |= byte1;
    ret <<= 8;
    ret |= byte0;
    return ret;
}

 /************************************************************************
   Function: skipChars
   Author: Charles Bonn and Christian Sieh
   Description: skip over given number of bytes in input file
   Parameters:
	FILE* infile - input file
	int numChars - number of chars
 ************************************************************************/
void Shape::skipChars( FILE* infile, int numChars ) const
{
    for ( int i = 0; i < numChars; i++ )
    {
        fgetc( infile );
    }
}

/* ********************************************************************
 *  LoadBmpFile
 *  Read into memory an RGB image from an uncompressed BMP file.
 *  Return true for success, false for failure.
 *  Author: Sam Buss December 2001.
 **********************************************************************/
 /************************************************************************
   Function: LoadBMPFile
   Author: Charles Bonn and Charles Bonn
   Description: Loads a bitmap file
   Parameters:
	char* filename - file
	int &numrows - number of rows
	int &numcols - number of colums,
	unsigned char 8 &imageprt - image
 ************************************************************************/
bool Shape::LoadBmpFile( const char* filename, int &NumRows, int &NumCols, unsigned char* &ImagePtr ) const
{
    FILE* infile = fopen( filename, "rb" );		// Open for reading binary data
    if ( !infile )
    {
        fprintf( stderr, "LoadBmpFile(): unable to open file: %s\n", filename );
        return false;
    }

    bool fileFormatOK = false;
    int bChar = fgetc( infile );
    int mChar = fgetc( infile );
    // If starts with "BM" for "BitMap"
    if ( bChar == 'B' && mChar == 'M' )
    {			
        // Skip 4 fields we don't care about
        skipChars( infile, 4 + 2 + 2 + 4 + 4 );			
        NumCols = readLong( infile );
        NumRows = readLong( infile );
        // Skip one field
        skipChars( infile, 2 );					
        int bitsPerPixel = readShort( infile );
        // Skip 6 more fields
        skipChars( infile, 4 + 4 + 4 + 4 + 4 + 4 );		

        if ( NumCols > 0 && NumCols <= 100000 && NumRows > 0 && NumRows <= 100000
                && bitsPerPixel == 24 && !feof( infile ) )
        {
            fileFormatOK = true;
        }
    }

    if ( !fileFormatOK )
    {
        fclose ( infile );
        fprintf( stderr, "Not a valid 24-bit bitmap file: %s.\n", filename );
        return false;
    }

    // Allocate memory
    ImagePtr = new unsigned char[ NumRows * GetNumBytesPerRow( NumCols ) ];
    if ( !ImagePtr )
    {
        fclose ( infile );
        fprintf( stderr, "Unable to allocate memory for %i x %i bitmap: %s.\n",
                 NumRows, NumCols, filename );
        return false;
    }

    unsigned char* cPtr = ImagePtr;
    for ( int i = 0; i < NumRows; i++ )
    {
        int j;
        for ( j = 0; j < NumCols; j++ )
        {
            *( cPtr + 2 ) = fgetc( infile );	// Blue color value
            *( cPtr + 1 ) = fgetc( infile );	// Green color value
            *cPtr = fgetc( infile );		// Red color value
            cPtr += 3;
        }
        int k = 3 * NumCols;					// Num bytes already read
        for ( ; k < GetNumBytesPerRow( NumCols ); k++ )
        {
            fgetc( infile );				// Read and ignore padding;
            *( cPtr++ ) = 0;
        }
    }

    if ( feof( infile ) )
    {
        fclose ( infile );
        fprintf( stderr, "Premature end of file: %s.\n", filename );
        return false;
    }

    fclose( infile );	// Close the file

    return true;
}


