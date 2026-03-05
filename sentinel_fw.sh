#!/bin/bash
# sentinel_fw.sh - Basic firewall management for Project Sentinel
# Usage: ./sentinel_fw.sh [start|stop|status]

FW_CHAIN="SENTINEL_FW"

start_fw() {
    sudo iptables -N $FW_CHAIN 2>/dev/null
    sudo iptables -I INPUT -j $FW_CHAIN
    echo "[+] Sentinel firewall started."
}

stop_fw() {
    sudo iptables -D INPUT -j $FW_CHAIN 2>/dev/null
    sudo iptables -F $FW_CHAIN 2>/dev/null
    sudo iptables -X $FW_CHAIN 2>/dev/null
    echo "[-] Sentinel firewall stopped."
}

status_fw() {
    sudo iptables -L $FW_CHAIN -n 2>/dev/null || echo "Chain $FW_CHAIN does not exist."
}

case "$1" in
    start)
        start_fw
        ;;
    stop)
        stop_fw
        ;;
    status)
        status_fw
        ;;
    *)
        echo "Usage: $0 [start|stop|status]"
        ;;
esac
