FROM nginx
USER root
COPY /nginx/nginx.conf /etc/nginx/nginx.conf
WORKDIR /home/
COPY hello.c /home/hello.c
COPY run.sh /home/run.sh

RUN apt-get update
RUN apt-get install -y gcc spawn-fcgi libfcgi-dev

ENTRYPOINT ["bash", "run.sh"]