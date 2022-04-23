//=================================================_
//      Base64 Encoding and Decoding Tool          |_ 
//         Author: @SynActktraa [Mikey]             |_
//  (Cli Wizard) base64 algorithm implemented in C.  |_
//      © This tool is based on ASCII charset.        |_
//=======================================================


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base64_utils.h"


char* get_file_data(char*file, char ch) {

/*
    Checks if file exists on the system, if yes
    stores the file size in buffer_len var
    by evaulating get_filesize function which 
    retrieves the file size and then reads the
    file line by line and stores it in buffer 
    and then concatenate it to data_storage
    and finally frees the buffer and return data_storage
*/
    if(!checkIfFileExists(file)) {
        fprintf(stderr, "FileError: can't open %s file.", file);
        putc(ch, stdout);
        exit(1);
    }

    int buffer_len = get_filesize(file)+2;
    
    FILE * file_in = fopen(file, "r");
    char* data_storage = (char*)malloc(sizeof(char) * buffer_len);
    char* buffer = (char*)malloc(sizeof(char) * buffer_len);

    memset(data_storage, 0, Strlen(data_storage));
    while (fgets(buffer, buffer_len, file_in))
        strcat(data_storage, buffer);

    free(buffer);
    return data_storage;
}


void encode(char*data, char*md, char ch, char* out){

    int buffer_len;
    char* plaintext;
/*
    compares md var, if it's '-f' it evaluates
    get_file_data and gets the file content and stores
    it in plaintext, else if it's '-i' it duplicates 
    the data and stores it in plaintext.    
*/
    if( !strcmp(md, "-f") ) {
        plaintext = get_file_data(data, ch);

    } else if( !strcmp(md, "-i") ) {
        plaintext = strdup(data);

    } else plaintext = "";
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
        label:
        /*
            charValidate checks for non-ascii characters
        */
            if( charValidate(plaintext[i]) == -1 ){
                fprintf(stderr, "InputError: can't take non-ascii characters.");
                putc(ch, stdout);
                exit(1);
            }
        /*
            checks for CR(carriage return) [this problem occurs in unix 
            systems] if present it deletes CR at the current
            index and proceeds to continue from label.
        */
            if (plaintext[i] == 13){
                delete(plaintext, i, Strlen(plaintext));
                goto label;    
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


void decode(char*data, char*md, char ch, char* out){

	int i, j;
    int buffer_len;
    char* base64_data;
/*
    compares md var, if it's '-f' it evaluates
    get_file_data and gets the file content and stores
    it in base64_data, else if it's '-i' it duplicates 
    the data and stores it in base64_data.    
*/
    if( !strcmp(md, "-f") ) {
        base64_data = get_file_data(data, ch);

    } else if( !strcmp(md, "-i") ) {
        base64_data = strdup(data);

    }  else base64_data = "";
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

            fprintf(stderr, "InputError: the string to be decoded is not correctly encoded.\n");
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
    
    char *store = "", *flag = "", *out = "", slash = '/';
    int ch = 0, i = 0;

    /*
        checks for operating system, if it detects windows
        ch is set null, if it's unix/linux ch is set to new
        line
    */
    #ifdef _WIN32
        ch = 0;
        slash = '\\';
    #elif __unix__
        ch = 10;
        slash = '/';
    #endif
    
    int e_flag = 0, d_flag = 0, o_flag = 0, s_flag = 0;

    if ( argc==2 && !strcmp(argv[1], "-h") ) {
            fprintf(stdout, "\n*IMP*: Put space separated data in quotes.\
            \nUsage: %s -e/-d -i/-f <data>/<file>\n|CLI options|:-\
            \n\t-e - Encodes the data string\
            \n\t-d - Decodes the data string\
            \n\t-i - takes next argument as data string\
            \n\t-f - takes next argument as filename\
            \n\t-o - takes next argument as filename and saves the output in file\
            \n\t     (if filename is not given, it defaults to base64Out)", basename(argv[0], slash));
            putc(ch, stdout);

    }else if ( argc >= 4 && argc <= 6 ) {

        for(; i < argc; ++i){

            if(!strcmp(argv[i], "-i") || !strcmp(argv[i], "-f")){
                s_flag = 1;
                flag = argv[i];
                if( argv[i+1] == NULL ){
                    fprintf(stderr, "InputError: no data or file detected");
                    putc(ch, stdout);
                    return 1;
                }
                store = argv[i+1];
            }
        }

        if (s_flag == 0){

            fprintf(stderr, "FlagError: data or file flag not detected");
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

            fprintf(stderr, "FlagError: same flag repeated");
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
            out = NULL;

        if ( e_flag ) {
            encode(store, flag, ch, out);
        } else if ( d_flag ) {
            decode(store, flag, ch, out);
        }

	} else {
        fprintf(stderr, "\nUsage: %s -e/-d -i/-f <data>/<file>\
        \nFor more, check help section:\
        \n    %s -h\n", basename(argv[0], slash), basename(argv[0], slash));
        putc(ch, stdout);

    }
    return 0;
}


// https://dev.to/rdentato/utf-8-strings-in-c-1-3-42a4