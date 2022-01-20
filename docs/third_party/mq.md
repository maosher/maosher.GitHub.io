
# Kafka vs RabbitMQ

在实际生产应用中，通常会使用kafka作为消息传输的数据管道，rabbitmq作为交易数据作为数据传输管道，主要的取舍因素则是是否存在丢数据的可能；rabbitmq在金融场景中经常使用，具有较高的严谨性，数据丢失的可能性更小，同事具备更高的实时性；而kafka优势主要体现在吞吐量上，虽然可以通过策略实现数据不丢失，但从严谨性角度来讲，大不如rabbitmq；而且由于kafka保证每条消息最少送达一次，有较小的概率会出现数据重复发送的情况；

RabbitMQ：支持消息的可靠的传递，支持事务，不支持批量操作，基于存储的可靠性的要求存储可以采用内存或硬盘，吞吐量小。
kafka：内部采用消息的批量处理，数据的存储和获取是本地磁盘顺序批量操作，消息处理的效率高，吞吐量高。

RabbitMQ：本身不支持负载均衡，需要loadbalancer的支持

kafka：采用zookeeper对集群中的broker，consumer进行管理，可以注册topic到zookeeper上，通过zookeeper的协调机制，producer保存对应的topic的broker信息，可以随机或者轮询发送到broker上，producer可以基于语义指定分片，消息发送到broker的某个分片上。

## RabbitMq


## Nats

