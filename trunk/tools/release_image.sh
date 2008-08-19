#!/bin/sh

#if [ -z $TFTPPATH ]; then
#echo "TFTPPATH is not defined! "
#exit 1
#fi

PRJ_PATH=$PRJ_PATH
# check the text file to cat into image
if [ -f hwid.txt ]; then
        rm -f hwid.txt
fi

PLATFORM=`grep WL_PLATFORM= /home/AthSDK/.config | cut -f 2 -d '='`


if [ $PLATFORM == ap61 ]; then
cd $IMG_PATH
rm -rf $1image.bin
dd if=vmlinux.$1.bin.l7 of=$1image.bin bs=1k 
dd if=jffs2.$1.bin of=$1image.bin bs=1k seek=576
#dd if=jffs2.$1.bin of=$1image.bin bs=1k seek=640
#dd if=jffs2.$1.bin of=$1image.bin bs=1k seek=512
echo -n $HARDWARE_ID >> $1image.bin
#rm -rf vmlinux*
#rm -rf jffs2.*
cp $1image.bin $TFTPPATH
elif [ $PLATFORM == AR7100 ]; then  
echo $PLATFORM 
cd $IMG_PATH
dd if=vmlinux.lzma of=$1image.bin bs=1k 
dd if=pb42-squash_l of=$1image.bin bs=1k seek=1024
echo -n $HARDWARE_ID >> $1image.bin
cp $1image.bin $TFTPPATH
else 
echo $PLATFORM 
cd $IMG_PATH
dd if=vmlinux.lzma.ub of=$1image.bin bs=1k 
dd if=pb42-squash_l of=$1image.bin bs=1k seek=1024
echo -n $HARDWARE_ID >> $1image.bin
cp $1image.bin $TFTPPATH
rm pb42-squash*
fi
