FROM gcc
ADD . /aplication
WORKDIR /aplication
RUN gcc --std=gnu11 main.c -o fileWriter
CMD ["./fileWriter"]
