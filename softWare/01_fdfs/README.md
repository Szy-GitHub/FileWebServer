一、fastDFS安装
libfastcommon-master
	./make.sh
	./make.sh install
fastdfs-5.10
tar zxvf xxx.tar.gz
	./make.sh
	./make.sh install


二、fastDFS测试
fdfs_test


三、fastDFS配置文件
	tracker 配置文件
	# 将追踪器和部署的主机的IP地址进程绑定, 也可以不指定, 会自动绑定当前主机IP
	bind_addr=192.168.247.135
	# 追踪器监听的端口
	port=22122
	# 追踪器存储日志信息的目录, xxx.pid文件, 必须是一个存在的目录
	base_path=/home/yuqing/fastdfs


	storage配置文件
	# 当前存储节点对应的主机属于哪一个组
	group_name=group1
	# 当前存储节点和所应该的主机进行IP地址的绑定, 如果不写, 有fastdfs自动绑定
	bind_addr=
	# 存储节点绑定的端口
	port=23000
	# 存储节点写log日志的路径
	base_path=/home/yuqing/fastdfs
	# 存储节点提供的存储文件的路径个数
	store_path_count=2
	# 具体的存储路径
	store_path0=/home/yuqing/fastdfs
	store_path1=/home/yuqing/fastdfs1
	# 追踪器的地址信息
	tracker_server=192.168.247.135:22122
	tracker_server=192.168.247.136:22122


	客户端配置文件
	# 客户端写log日志的目录, 该路径必须存在
	base_path=/home/yuqing/fastdfs
	# 要连接的追踪器的地址信息
	tracker_server=192.168.247.135:22122
	tracker_server=192.168.247.136:22122