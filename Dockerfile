FROM gcc
ADD . /aplication
WORKDIR /aplication
RUN gcc -o cfile main.c
CMD ["./cfile"]
