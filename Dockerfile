FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential cmake git ca-certificates \
    libgl1-mesa-dev libglu1-mesa-dev libgl1-mesa-dri \
    libx11-dev libxrandr-dev libxcursor-dev libudev-dev libfreetype-dev \
    xvfb x11vnc novnc websockify \
    && rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/o-reo/push_swap_visualizer.git /opt/visualizer \
    && cd /opt/visualizer && git checkout 0e7e2a9bfa229e517c8e853e466819823131bc68 \
    && rm -f /opt/visualizer/push_swap \
    && mkdir build && cd build \
    && cmake .. -DCMAKE_BUILD_TYPE=Release \
    && make -j"$(nproc)" visualizer

WORKDIR /app
COPY . .
RUN make re

RUN cp /opt/visualizer/imgui.ini /opt/visualizer/build/imgui.ini \
    && ln -s /app/push_swap /opt/push_swap

COPY start.sh /start.sh
RUN chmod +x /start.sh

EXPOSE 3000
CMD ["/start.sh"]
