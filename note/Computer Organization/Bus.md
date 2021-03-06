## 第二章 总线

总线就是连接各个部件的信息传输线，是各个部件共享的传输介质。

总线上信息传送方式有**串行**和**并行**两种。其中并行传输距离较近。

### 总线结构

1. 单总线结构：CPU、主存、多个I/O设备之间，共用同一条系统总线。
2. 面向CPU的双总线结构：在CPU与主存之间有M总线，CPU与其他I/O设备之间有一条I/O总线。
3. 以存储器为中心的双总线结构：CPU、主存、I/O设备共用一条系统总线，而CPU与主存之间挂接有一条存储总线。
4. I/O总线与主存总线构成的双总线结构：主存总线连接CPU与主存，并通过通道（具有特殊功能的处理器，由通道对I/O统一管理，一般在操作系统中具体描述）连接I/O总线，I/O总线连接各个I/O接口，至各个设备。
5. 三总线结构：CPU与主存通过主存总线连接，主存与高速外部设备通过DMA总线连接，CPU通过I/O总线与所有外部设备连接。

### 总线分类

1. 片内总线：芯片内部的总线。
2. 系统总线：计算机各个部件之间的信息传输线。
   1. 数据总线：双向，与机器字长、存储字长相关。
   2. 地址总线：单向，与存储地址、I/O地址有关。
   3. 控制总线：有出（中断请求、总线请求）有入（存储器读写、总线允许、中断确认）。
3. 通信总线：用于计算机系统之间 或 计算机系统与其它系统之间的通信。

### 总线控制

#### 总线判优控制

- 主设备（模块）：对总线有控制权。
- 从设备（模块）：响应从主设备发来的总线命令。
- 总线判优控制
  - 集中式：将总线判优逻辑置于一个设备上
    - 链式查询
    - 计数器定时查询
    - 独立请求方式
  - 分布式

#### 总线通信控制

1. **目的**：解决通信双方协调配合问题。
2. 总线**传输周期**：
   - 申请分配阶段：主模块申请，总线仲裁决定
   - 寻址阶段：主模块向从模块给出地址和命令
   - 传数阶段：主模块和从模块交换数据
   - 结束阶段：主模块撤销有关信息
3. 总线通信的四种方式
   - **同步通信**：由统一时标控制数据传送；由定宽定距的时钟来控制整个数据输入输出的过程，在给定的时间上要完成相应的操作。
   - **异步通信**：采用应答方式，没有公共时钟标准；不互锁/半互锁/全互锁。
   - **半同步通信**：同步、异步结合；**同步**指发送方用系统时钟前沿发信号，接收方用系统时钟后沿判断、识别；**异步**指允许不同速度的模块和谐工作，增加一条“等待”相应信号 *WAIT*。
   - **分离式通信**：充分挖掘系统总线每个瞬间的潜力；将一个总线传输周期分为两个子周期，在子周期1中，主模块申请占用总线，使用完后放弃总线的使用权，在子周期2中从模块申请占用总线，将各种信息送至总线上。