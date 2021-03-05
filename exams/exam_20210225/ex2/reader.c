#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Copy characters received from a named pipe to stdout
// using open, read and write
// Compile with:
//     make reader

int main( int argc, char *argv[] ) {
    int inFd = -1;
    int exitStatus = 0;
    if( argc == 2 ) {
	// Set standard out as unbuffered
	setvbuf( stdout, NULL, _IONBF, 0 );
	// Open input pipe
        inFd = open( argv[1], O_RDONLY );
        if( inFd >= 0 ) {
	    // Endless loop to copy pipe stream to stdout
	    while( 1 ) {
                char ch;
		if( read( inFd, &ch, 1 ) == 1 ) {
		    write( 1, &ch, 1 );
		}
	    }
	} else {
	    exitStatus = 2;
	}
    } else {
	exitStatus = 1;
    }
    if( exitStatus != 0 ) {
	fprintf( stderr, "Usage: %s pipename\n", argv[0] );
    }
    exit( exitStatus );
}
