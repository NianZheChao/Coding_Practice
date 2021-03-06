## 第三章 存储器

### 存储器分类

- 按存储介质
  - 半导体存储器：内存/U盘；TTL逻辑/MOS逻辑
  - 磁表面存储器：磁盘；磁头、磁载体
  - 磁芯存储器：core memory；硬磁材料、环状元件
  - 光盘存储器：激光、磁光材料
- 按存取方式
  - 存取时间与物理地址无关（随机访问）
    - 随机存储器：在程序执行过程中可读可写（RAM）
    - 只读存储器：在程序执行过程中只读（ROM）
  - 存取时间与物理地址有关（串行访问）
    - 顺序存取存储器（如磁带）
    - 直接存取存储器（如磁盘）
- 按在计算机中的作用
  - 主存储器
    - RAM：静态/动态 RAM
    - ROM：MROM/PROM/EPROM/EEPROM
  - 辅助存储器：磁盘、磁带、光盘
  - Flash Memory：U盘、固态硬盘
  - 高速缓冲存储器（Cache）

### 存储器的层次结构

![1587366946373](../images/1587366946373.png)

 ![2](../images/2.png)

### 主存储器的基本组成

主要包括：MAR、MDR、存储体 三大部分

**MAR**中保存了需要访问的存储单元的地址，经过**译码器**进行选定之后，才可以访问选的的存储单元，同样，**MDR**中保存了需要读出或写入的数据，其中读/写操作的判断通过**读写电路**和**控制电路**完成，

### 主存与CPU的联系

MDR与主存由双向的数据总线连接，用于读出和写入；MAR与主存由单向通向主存的地址总线连接，用于给出需要访问的内存单元地址；CPU与主存之间由单向通向主存的读/写线连接，用于控制信号的传输。

### 主存中存储单元地址分配

 编址单位：字节；每个字节都有一个地址；

大端大尾方式：高位字节地址为字存储地址；

小端小尾方式：低位字节地址为字存储地址；（x86机器都采用该方式）

两种机器进行通讯时需要进行调整。

![1595122617206](../images/1595122617206.png)



### 主存的技术指标

存储容量：主存中存放二进制代码的总位数。

存储速度：存取时间：存储器的访问时间；存取周期：连续两次独立的存储器操作所需的最小时间间隔。

存储器的带宽：位/秒

### 半导体芯片简介

#### 半导体芯片的基本结构

半导体芯片 = 存储矩阵 + 读写电路 + 译码驱动 + 外部接口（地址线（单向） + 数据线（双向） + 片选线 + 读/写控制线）

**地址线和数据线**描述了芯片的容量：例如10位地址线与4位数据线的芯片容量为$2^{10}×4$ 即1K×4​位

**读/写控制线**，可用一根WE线表示，低电平写，高电平读；也可用两根信号线表示，OE线低电平输出（从存储矩阵输出至数据线，即允许读），WE线低电平输入（将数据线上的数据写入指定的存储单元当中）。

**片选线**即芯片选择线，所访问的信息位于哪个芯片中，就是由片选线确定的。一般由两种管脚组成：CS(chip select)线，当该线低电平时表示该芯片有效；CE(chip enable)线，芯片允许信号。

用8个16K×1位芯片同时存取组成一组16K×8位存储器，并且可以用4组芯片组成64K×8位的存储器，其中每组16K×8位存储器同时工作。使用片选线将它们连接，并且按顺序进行编号，即可进行片选读写。例如，当地址为65535时，片选线选择第四组芯片，即最后8片的片选有效。

#### 半导体芯片的译码驱动方式

##### 线选法

##### 重合法



