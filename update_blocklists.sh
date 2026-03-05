#!/bin/bash
# update_blocklists.sh - Download and update community blocklists for Project Sentinel
# Usage: ./update_blocklists.sh

BLOCKLIST_DIR="$(dirname "$0")/blocklists"
COMMUNITY_LISTS=(
    "https://raw.githubusercontent.com/StevenBlack/hosts/master/hosts"
    "https://adaway.org/hosts.txt"
    "https://someonewhocares.org/hosts/hosts"
)

mkdir -p "$BLOCKLIST_DIR"

for url in "${COMMUNITY_LISTS[@]}"; do
    fname=$(basename "$url")
    echo "Fetching $url ..."
    curl -fsSL "$url" -o "$BLOCKLIST_DIR/$fname" || echo "Failed to fetch $url"
done

echo "Blocklists updated in $BLOCKLIST_DIR."
