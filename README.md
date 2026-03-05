# Project Sentinel

A lightweight, server-optimized firewall and network filter with a web UI, inspired by PFsense and AdGuard Home.

## Features (Initial Version)
- Lightweight C HTTP server for web UI (sentinel_server.c)
- Shell script for basic firewall management (sentinel_fw.sh)
- Designed for practical server use and easy extensibility

## Usage

### 1. Build and Run the Web UI Server
```sh
gcc -o sentinel_server sentinel_server.c
./sentinel_server
```

Then open http://localhost:8080 in your browser.

### 2. Manage Firewall
```sh
chmod +x sentinel_fw.sh
./sentinel_fw.sh start   # Start firewall
./sentinel_fw.sh status  # Show firewall status
./sentinel_fw.sh stop    # Stop firewall
```

## Next Steps
- Add web UI controls for firewall rules
- Integrate ad-blocking/filtering logic
- Optimize for performance and security