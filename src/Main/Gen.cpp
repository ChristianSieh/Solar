#include "Gen.h"



void generate()
{
    string filename = "planets.txt";
    openfile( filename ); 
}

void openfile( string filename)
{
    //openfile
    ifstream cin;
    string line, type;

    cin.open( filename , ios::in );
    if(cin.is_open())
    {
	while( !cin.eof() )
	{
	    cin >> type;
            getline( cin, line);
            cerr << "type: " << type << "    : " << line << endl;
//	    genPick( type );
	}
        /*while( getline(cin, line ))
        {
            genPick( line.front() ) ;
        }*/
	cin.close();
    }
    else
    {
	cerr << "Unable to openfile: " << filename << endl;
    }
}


void genPick( function <void ()> &myFunc)
{
    cerr << "in func pick" << endl;
    myFunc();
}

void planet( )
{
   cerr << "gen planets" << endl;
  
}

