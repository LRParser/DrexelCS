#!/bin/bash

wget https://www.cs.drexel.edu/~greenie/cs645/etch.sources.list
cat etch.sources.list >> /etc/apt/sources.list
# Add required keys for apt
gpg --keyserver pgpkeys.mit.edu --recv-key 9AA38DCDD55BE302B
gpg -a --export 9AA38DCDD55BE302B | sudo apt-key add -

# Update apt
apt-get update

# Install emacs, vim and git
apt-get install emacs
apt-get install vim
apt-get install git

# Download the assignment

wget http://www.cs.drexel.edu/~greenie/cs475/projects/cs475-pp1.tar.bz2

tar xjvf cs475-pp1.tar.bz2 

cp -r sploits ~user/
chown -R user:user ~user/sploits
cd targets/
make
cp * /tmp
cd /tmp
chown root:root target? ; chmod 4755 target?; chmod a+r target?.c
su user
cd
ls
cd sploits/
ls
cd /tmp
ls

chown root:root target? ; chmod 4755 target? ; chmod a+r target?.c
