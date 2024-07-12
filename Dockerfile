FROM debian:latest

WORKDIR /tmp

RUN apt-get update && apt-get install -y valgrind && apt-get install -y vim && apt-get install -y gcc && apt-get install -y clang && apt-get install -y make && apt-get install -y git

CMD ["bash"]
