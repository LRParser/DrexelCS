rm .gdbinit
ln -s gdbinit3 .gdbinit
gdb -e sploit3 -s /tmp/target3
rm .gdbinit
