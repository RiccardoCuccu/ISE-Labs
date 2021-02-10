#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

// Get characters from stdin and copy them to a named pipe
// using fopen, fread and fwrite
// Compile with:
//     make writer

int main( int argc, char *argv[] ) {
    int exitStatus = 0;
    struct termios old_tio, new_tio;
    // Set input terminal as unbuffered using termios functions
    // Get the terminal settings for stdin
    tcgetattr( STDIN_FILENO, &old_tio );
    // Save old settings
    new_tio = old_tio;
    // Disable canonical mode
    new_tio.c_lflag &=( ~ICANON );
    // Set the new settings immediately
    tcsetattr( STDIN_FILENO, TCSANOW, &new_tio );
    // Check args
    if( argc == 2 ) {
	// Open output pipe
        FILE *outFp = fopen( argv[1], "wb" );
        if( outFp != NULL ) {
            // Endless loop to copy stdin to pipe
	    // Use setvbuf to disable I/O buffering
            setvbuf( stdin, NULL, _IONBF, 0 );
            setvbuf( outFp, NULL, _IONBF, 0 );
	    while( 1 ) {
                char ch;
		fread( &ch, sizeof( ch ), 1, stdin );
		fwrite( &ch, sizeof( ch ), 1, outFp );
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
    // Restore former stdin settings
    tcsetattr( STDIN_FILENO, TCSANOW, &old_tio );
    // Exit
    exit( exitStatus );
}
