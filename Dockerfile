FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    time \
    git \
    python3.10 \
    python3-pip && \
    pip3 install --upgrade pip && \
    pip3 install online-judge-tools
