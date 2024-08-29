FROM nginx:latest
USER root
COPY /nginx/nginx.conf /etc/nginx/nginx.conf
WORKDIR /home/
COPY hello.c /home/hello.c
COPY run.sh /home/run.sh

RUN apt-get update && apt-get install -y gcc spawn-fcgi libfcgi-dev; \
    chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /var/cache/nginx; \
    chown -R nginx:nginx /home; \
    touch /var/run/nginx.pid; \
    chown -R nginx:nginx /var/run/nginx.pid; \
    chmod u-s /usr/bin/su /usr/bin/umount /usr/bin/chsh /usr/bin/newgrp /usr/bin/mount /usr/bin/passwd /usr/bin/gpasswd /usr/bin/chfn; \
    chmod g-s /usr/sbin/unix_chkpwd /usr/bin/expiry /usr/bin/wall /usr/bin/chage; \
    rm -rf /var/lib/apt/lists

USER nginx


HEALTHCHECK --interval=30s --timeout=30s --start-period=5s --retries=3 CMD curl -f http://localhost:80/ || exit 1
ENTRYPOINT ["bash", "run.sh"]


