
# Etcd 和 Zookeeper

更轻量级(Etcd基于GO语言开发,Zookeeper基于Java开发)  
高负载下的稳定读写  
数据模型的多版本并发控制  
稳定的watcher功能，通知订阅者监听值的变化(Zookeeper基于数据的监听是一次性的，每次监听完成还需重新注册)  
客户端协议使用GRPC协议，支持语言更广泛  