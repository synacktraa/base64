//=================================================_
//      Base64 Encoding and Decoding Tool          |_ 
//         Author: @SynActktraa [Mikey]             |_
//  (Cli Wizard) base64 algorithm implemented in C.  |_
//      © This tool is based on ASCII charset.        |_
//=======================================================


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"


void encode(char* plaintext, char* flag, char* out){

    int buffer_len;
    buffer_len = Strlen(plaintext);
    // calculates space for base64 encoded string
    int base64_val_space = (0.4*(buffer_len+1))+buffer_len+2;
    // calculates space for binary dump of input string
    int bin_dump_space = (buffer_len * 8)+1;

    char six_bit_bin[7], Ox49_val_bin[9]; 

    char *base64_val = (char*)malloc(sizeof(char) * base64_val_space);
    char *bin_dump = (char*)malloc(sizeof(char) * bin_dump_space);

    int i, j, k, bin_dump_len;
    
    memset(Ox49_val_bin, 0, Strlen(Ox49_val_bin));
    memset(bin_dump, 0, Strlen(bin_dump));

    for( i=0; plaintext[i] != '\0'; ++i ) {
        /*
            charValidate checks for non-ascii characters
        */
            if( charValidate(plaintext[i]) == -1 ){
                fprintf(stderr, "InputError: can't take non-ascii characters");
                putchar(ch);
                exit(1);
            }

        strcpy(Ox49_val_bin, decToBin(plaintext[i]));
		while( Strlen(Ox49_val_bin)%8 != 0 ){
        /*
            checks for 8 bit binary, if not it starts
            adding zeroes from the 0th index until it's
            8 bit binary value.
        */
        	k = insert(Ox49_val_bin, 0, '0', Strlen(Ox49_val_bin), Strlen(Ox49_val_bin)+1);
        	Ox49_val_bin[k] = '\0';
        }
        //concatenates the 8 bit binary in bin_dump to create
        //a binary dump which will be manipulated later   
        strcat(bin_dump, Ox49_val_bin);
        memset(Ox49_val_bin, 0, Strlen(Ox49_val_bin));
    
    }
    if(!strcmp(flag, "-f"))
        free(plaintext);
    
    bin_dump_len = Strlen(bin_dump);
    while( bin_dump_len%6 != 0 )
    /*
        checks if the length of binary dump is in the
        multiplication of 6, coz base64 -> 2^6 = 64
    */
        bin_dump_len = insert(bin_dump, bin_dump_len, '0', bin_dump_len, Strlen(bin_dump)+1);

    i = 0, j = 0;  
    while( i[bin_dump]!='\0' ){
    /*
        moves 6 bits from bin_dump to six_bit_bin,
        converts the 6 bit binary to decimal and stores
        it in ascii_val and do some comparisions, then
        adds accordingly and stores it in base64_val string
        and increments i by 6.
    */
        memset(six_bit_bin, 0, Strlen(six_bit_bin));
        memmove(six_bit_bin, bin_dump+i, 6);
        six_bit_bin[6] = 0;
        int ascii_val = binToDec(six_bit_bin);
        if( ascii_val>=0 && ascii_val<=25 )
            base64_val[j] = ascii_val+65;
        else if( ascii_val>=26 && ascii_val<=51 )
            base64_val[j] = ascii_val+71;
        else if( ascii_val>=52 && ascii_val<=61 )
            base64_val[j] = ascii_val-4;
        else if( ascii_val==62 )
            base64_val[j] = ascii_val-19;
        else if( ascii_val==63 )
            base64_val[j] = ascii_val-16;
        
        j++; i += 6;

    }
    base64_val[j] = '\0';
    free(bin_dump);
    while( Strlen(base64_val)%4 != 0 )
    /*
        inserts '=' at the end of the base64 encoded string until
        the length is in the multiplication of 4.
    */
        insert(base64_val, Strlen(base64_val), 0x3d, Strlen(base64_val), base64_val_space);

    if ( out == NULL ){
    /*
        if outfile is not given, print the output
        in cli/terminal
    */
        fwrite(base64_val, 1, Strlen(base64_val), stdout);
        putc(ch, stdout);
    } else {
    /*
        else writes the ouput to the file
    */
        FILE * fp = fopen(out, "w");
        fputs(base64_val, fp);
    }
    free(base64_val); 

}


void decode(char* base64_data, char* flag, char* out){

	int i, j;
    int buffer_len;

    buffer_len = Strlen(base64_data);
    
    // calculates space for base64 encoded string
    int decData_val_space = (buffer_len+2)-(0.15*buffer_len);
    // calculates space for binary dump of input string
    int bin_dump_space = (buffer_len * 6)+1;

    char Ox49_val_bin[9], byte_bin[9];
    char *bin_dump = (char*)malloc(sizeof(char) * bin_dump_space);
    char *decodeData = (char*)malloc(sizeof(char) * decData_val_space);
    
    delspace(base64_data);
    buffer_len = Strlen(base64_data);
	while(*(base64_data+(buffer_len-1)) == '='){
    /*
        checks for '=' from the end of the input encoded string
        and deletes the padding 
    */
		buffer_len = delete(base64_data, buffer_len-1, buffer_len);
	}

    memset(bin_dump, 0, Strlen(bin_dump));
    memset(Ox49_val_bin, 0, Strlen(Ox49_val_bin));

    for( i=0; base64_data[i]!=0; ++i ){

        if (base64Validate(base64_data[i]) == -1) {

            fprintf(stderr, "InputError: the string to be decoded is not correctly encoded");
            putc(ch, stdout);
            exit(1);
        }
    /*
        checks for encoded data simultaneously, then subtracts
        and evaluated decimal to binary function, then copies it
        in Ox49_val_bin
    */
        if( base64_data[i]>='B' && base64_data[i]<='Z' )
            strcpy(Ox49_val_bin, decToBin(base64_data[i]-65));
        else if( base64_data[i]>='a' && base64_data[i]<='z' )
            strcpy(Ox49_val_bin, decToBin(base64_data[i]-71));
        else if( base64_data[i]>='0' && base64_data[i]<='9' )
            strcpy(Ox49_val_bin, decToBin(base64_data[i]+4));
        else if( base64_data[i]=='+')
            strcpy(Ox49_val_bin, decToBin(base64_data[i]+19) );
        else if( base64_data[i]=='/' )
            strcpy(Ox49_val_bin, decToBin(base64_data[i]+16) );
        else if( base64_data[i] == 'A' )
            strcpy(Ox49_val_bin, "000000");

        int k = Strlen(Ox49_val_bin);
        while( k%6 != 0 ){
        /*
            checks if the length of binary is in the
            multiplication of 6, coz base64 -> 2^6 = 64
        */
            k = insert(Ox49_val_bin, 0, '0', k, sizeof(Ox49_val_bin));
        }
        
        strcat(bin_dump, Ox49_val_bin);
        memset(Ox49_val_bin, 0, Strlen(Ox49_val_bin));
    }
    if(!strcmp(flag, "-f"))
        free(base64_data);
    
    int bin_dump_len = Strlen(bin_dump);
    while( bin_dump_len%8 != 0 ){
    /*
        checks for 8 bit binary, if not it starts
        adding zeroes from the 0th index until it's
        8 bit binary value.
    */
        bin_dump_len = insert(bin_dump, bin_dump_len , '0', bin_dump_len, bin_dump_space);
    }
    *(bin_dump+bin_dump_len) = '\0';

    i = 0, j = 0;
    while( bin_dump[i]!='\0' ){
    /*
        moves 1 byte from bin_dump to byte_bin,
        converts that byte binary to decimal and stores
        it in decodeData and increments i by 8.
    */
        memset(byte_bin, 0, Strlen(byte_bin));
        memmove(byte_bin, bin_dump+i, 8);
        byte_bin[8] = 0;

        decodeData[j] = binToDec(byte_bin);
        j++; i += 8;
    }
    decodeData[j] = '\0';

    free(bin_dump);

    if( out == NULL){
    /*
        if outfile is not given, print the output
        in cli/terminal
    */
        fwrite(decodeData, 1, Strlen(decodeData), stdout);
        putc(ch, stdout);
    } else {
    /*
        else writes the ouput to the file
    */
        FILE * fp = fopen(out, "w");
        fputs(decodeData, fp);
    }
    free(decodeData);

}

int main(int argc, char* argv[]){
    
    char *string=NULL, *file=NULL, *out=NULL, *flag=NULL, *exe = basename(argv[0], slash);
    int e_flag = 0, d_flag = 0, o_flag = 0, i_flag = 0, f_flag = 0,i = 0;

    if ( argc==2 && !strcmp(argv[1], "-h") ) {
            fprintf(stdout, "[Imp]: Put space separated data in quotes.\
            \nUsage: %s [-e|-d] [-i|-f] [string|file]\n|CLI options|:-\
            \n   -e  encodes the data string\
            \n   -d  decodes the data string\
            \n   -i  specify data string for manipulation\
            \n   -f  specify filename for manipulation\
            \n   -o  specify filename to store the result\
            \n       [if filename isn't specified, it defaults to base64Out]", exe);
            putc(ch, stdout);
			free(exe);
			exe = NULL;

    }else if ( argc >= 4 && argc <= 6 ) {

        for(; i < argc; ++i){

            if(!strcmp(argv[i], "-i")){
                i_flag = 1;
                flag="-i";
                if( argv[i+1] == NULL ){
                    fprintf(stderr, "InputError: no data detected");
                    putc(ch, stdout);
                    return 1;
                }
                string = argv[i+1];
            }
        }
        for(i=0; i < argc; ++i){

            if(!strcmp(argv[i], "-f")){
                f_flag = 1;
                flag="-f";
                if( argv[i+1] == NULL ){
                    fprintf(stderr, "FileError: no file detected");
                    putc(ch, stdout);
                    return 1;
                }
                file = argv[i+1];
            }
        }

        if (!i_flag && !f_flag){

            fprintf(stderr, "FlagError: data or file flag not detected");
            putc(ch, stdout);
            return 1;
        }
        if (i_flag && f_flag){

            fprintf(stderr, "FlagError: can't manipulate two data at once.");
            putc(ch, stdout);
            return 1;
        }
        
        for(i = 0; i < argc; ++i) {
            if(!strcmp(argv[i], "-e")){
                e_flag += 1;
            }
        }

        for(i = 0; i < argc; ++i) {
            if(!strcmp(argv[i], "-d")){
                d_flag += 1;
            }
        }

        if(e_flag == 0 && d_flag == 0){

            fprintf(stderr, "MethodError: conversion method not specified");
            putc(ch, stdout);
            return 1;
        }
        
        if(e_flag > 1 || d_flag > 1){

            fprintf(stderr, "FlagError: can't use same flags more than once");
            putc(ch, stdout);
            return 1;
        }

        if(e_flag && d_flag){

            fprintf(stderr, "MethodError: specify only one conversion method");
            putc(ch, stdout);
            return 1;
        }

        for( i = 0; i < argc; ++i) {
            
            if(!strcmp(argv[i], "-o")) {
                o_flag = 1;
                if( argv[i+1] == NULL ){
                    out = "base64Out";
                } else out = argv[i+1];
                break;   
            }
        }

        if(o_flag == 0) 
            out=NULL;

        if(f_flag){
            string=retrieve(file);
        }
        if ( e_flag ) {
            encode(string, flag, out);
        } else if ( d_flag ) {
            decode(string, flag, out);
        }

	} else {
        fprintf(stderr, "\nUsage: %s -e/-d -i/-f <data>/<file>\
        \nFor more, check help section:\
        \n    %s -h\n", exe, exe);
		free(exe);
		exe = NULL;
        putc(ch, stdout);

    }
	free(exe);
	exe = NULL;
    return 0;
}


// https://dev.to/rdentato/utf-8-strings-in-c-1-3-42a4
