FROM ubuntu:latest

COPY requirements.txt .
COPY .env .

RUN apt-get update && \
    apt-get install -y git time libboost-all-dev python3-pip && \
    pip3 install --upgrade pip && pip3 install -r requirements.txt && \
    export $(cat .env | grep -v ^# | xargs) && \
    oj login -u $ATCODER_USERNAME -p $ATCODER_PASSWORD https://atcoder.jp/ && \
    rm requirements.txt .env && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
