#include <stdio.h>

    func(char *sm)
    {
            char buffer[256];
            int i;
            for(i=0;i<=256;i++)
                    buffer[i]=sm[i];
    }

    main(int argc, char *argv[])
    {
            if (argc < 2) {
                    printf("missing args\n");
                    exit(-1);
            }

            func(argv[1]);
    }
