#! /bin/sh
# $Id: iptables_flush.sh,v 1.1 2007/09/13 09:04:18 ken_chiang Exp $
IPTABLES=iptables

#flush all rules owned by miniupnpd
$IPTABLES -t nat -F MINIUPNPD
$IPTABLES -t filter -F MINIUPNPD

