
## Redis

scan 
字符串类型：它的big体现在单个value值很大，一般认为超过10KB就是bigkey。
非字符串类型：哈希、列表、集合、有序集合，它们的big体现在元素个数太多。一次性取出时
redis-cli --bigkeys  有风险! 在slave 本机执行，避免网络开销
可以使用 --i 0.1 代表100毫秒执行一次

debug object ${key}命令获取键值的相关信息

String, Set, Hash, List, SortedSet 

### Redis做异步队列么
使用list结构作为队列，rpush生产消息，lpop消费消息。当lpop没有消息的时候，要适当sleep一会再重试。  
可不可以不用sleep呢？list还有个指令叫blpop，在没有消息的时候，它会阻塞住直到消息到来。 
能不能生产一次消费多次呢？使用pub/sub主题订阅者模式，可以实现1:N的消息队列。    
pub/sub有什么缺点？在消费者下线的情况下，生产的消息会丢失，得使用专业的消息队列如rabbitmq等。

### redis如何实现延时队列
使用sortedset，拿时间戳作为score，消息内容作为key调用zadd来生产消息，消费者用zrangebyscore指令获取N秒之前的数据轮询进行处理。



## LevelDB & RocksDb 