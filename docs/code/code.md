
# 一个游戏服务器设计


## 特点
- 玩家数量大，滚服，频繁开新服
- 战斗，对局开房间式的


## 横向划分
基于服务，每个服务里面的业务处理是单线程的
如果单线程里不能满足业务需求，那么可以采用多服务的模式

***不要通过共享内存来通信，要通过通信来共享内存***

服务的设计


~~~golang 
func (sc* Service) Init() {
    go sc.ioLoop()
    go sc.RunLoop() //简单代码， 没考虑停止/退出时情况
}
func (sc* Service) PostMsg(msg interface{}){
    //简单代码， 没考虑停止/退出时情况
    sc.queue <- msg
}
func (sc* Service) ioLoop() {

}
func (sc* Service) runLoop(){
    defer sc.exitLoop()
    for msg := range sc.queue {
        switch msg.(type){
            case *MsgStop:
                return 
            default:
                sc.ProcessMsg(msg)  
        }
    }
}
func (sc* Service) ProcessMsg(msg){
    switch msg.(type) {
        case *MsgTimer: 
        //msg.TimerFunc(sc, msg.param...)
        case *MsgNetPacket:
        // some logic code
        // processNetMsg(msg)        
             sc.mgr.GetNetService().PostMsg(&NetMsgMsg{ Head:head })

    }
}
~~~

### 消息队列


### 网络服务

### 逻辑服务

### Httpd / grpc, http 服务

### 生态日志

### 



## 纵向划分


### 服务发现


### Gateway 接入
- 负责维护连接，消息分发
- 收敛网络入口
- 动态切换后端服务

### 登录

### 主逻辑
- 主要玩法(养成，任务，活动...)
- 给服务提供基础数据

### 战斗/房间 服务
- 负责核心战斗
- 维护房间，玩家状态

### 数据存储 
- 解耦业务层数据结构
- 适应数据库改变

### GM, 匹配，社交其它服务
- 辅助性
- 
