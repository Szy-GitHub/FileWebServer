#!/bin/bash

#Step 1
echo
echo ============= Copy nginx.conf =============
# 将旧的nginx配置文件重命名
sudo mv /usr/local/nginx/conf/nginx.conf /usr/local/nginx/conf/nginx.conf.old
# 拷贝nginx的配置文件nginx.conf到默认目录
sudo cp ./nginx.conf /usr/local/nginx/conf

#Step 2
echo
echo ============= fastdfs ==============
# 关闭已启动的 tracker 和 storage
./fastdfs.sh stop
# 启动 tracker 和 storage
./fastdfs.sh all

#Step 3
echo
# 重启所有的 cgi程序
echo ============= fastCGI ==============
./fcgi.sh

#Step 4
echo
echo ============= nginx ==============
# 关闭nginx
./nginx.sh stop
# 启动nginx
./nginx.sh start

#Step 5
echo
echo ============= redis ==============
# 关闭redis
./redis.sh stop
# 启动redis
./redis.sh start
