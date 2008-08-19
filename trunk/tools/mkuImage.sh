#!/bin/sh -x

#
# $1 == u-boot/tools path
# $2 == kernel tree path
#
MKIMAGE=$TOOL_PATH/mkimage
VMLINUX=$1/vmlinux
VMLINUXBIN=$1/arch/mips/boot/vmlinux.bin
LDADDR=0x80060000
TFTPPATH=/tftpboot
IMAGEDIR=$2/vmlinux.lzma

ENTRY=`readelf -a ${VMLINUX}|grep "Entry"|cut -d":" -f 2`

#gzip -f ${VMLINUXBIN}

#${MKIMAGE} -A mips -O linux -T kernel -C gzip \
#        -a ${LDADDR} -e ${ENTRY} -n "Linux Kernel Image"    \
#               -d ${VMLINUXBIN}.gz ${TFTPPATH}/vmlinux.gz.uImage

${MKIMAGE} -A mips -O linux -T kernel -C lzma \
        -a ${LDADDR} -e ${ENTRY} -n "Linux Kernel Image"    \
                -d ${IMAGEDIR} $2/vmlinux.lzma.ub
