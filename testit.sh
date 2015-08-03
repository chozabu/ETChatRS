make clean
qmake-qt4
make clean
make
kdesudo -u retrotester cp libETChat.so* /home/retrotester/.retroshare/extensions6/
kdesudo -u retrotester ../../retroshare-gui/src/RetroShare
