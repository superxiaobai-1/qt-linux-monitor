FROM  ubuntu:18.04

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Shanghai

SHELL ["/bin/bash", "-c"]

RUN apt-get clean && \
    apt-get autoclean
COPY apt/sources.list /etc/apt/

RUN apt-get update  && apt-get upgrade -y  && \
    apt-get install -y \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    libboost-all-dev \
    vim

RUN apt-get install -y libc-ares-dev  libssl-dev gcc g++ make 

RUN apt-get install -y \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    xorg libprocps-dev gdb





