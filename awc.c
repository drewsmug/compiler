/********************************************************************
 * This is the main harness for Andrew Wall's Compiler [awc]
 *******************************************************************/

#include <stdio.h>
#include <unistd.h>

void main(int argc, char *argv[], char **env_var_ptr)
{
    int preProcessorFlag = 0;
    int verboseFlag      = 0;
    char *outputFile;

    opterr = 0;
    int c;
    while((c = getopt(argc, argv, ":vEo:")) != -1)
        switch(c)
        {
            case 'v':
                verboseFlag = 1;
                break;
            case 'E':
                preProcessorFlag = 1;
                break;
            case 'o':
                outputFile = optarg;
                break;
            case ':':
                printf("Option -%c requires an argument\n", optopt);
                break;
            case '?':
            default:
                printf("-%c is not a valid optoin\n", optopt);
        }

    if(preProcessorFlag && verboseFlag)
        printf("Pre-Processor flag set\n");
}
