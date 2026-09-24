#!/bin/bash

Xvfb :99 -screen 0 1400x1050x24 &
sleep 1

cd /opt/visualizer/build
DISPLAY=:99 ./bin/visualizer &

x11vnc -display :99 -forever -shared -nopw -rfbport 5900 -quiet &

exec websockify --web=/usr/share/novnc/ 3000 localhost:5900
