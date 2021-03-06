# 开闭原则

## 开闭原则的定义
> 一个软件实体如类 模块和函数应该对扩展开发 对修改关闭

开闭原则对扩展开发 对修改关闭 并不意味着不做任何修改 底层模块的变更 必然要有高层模块进行耦合 否则就是一个孤立无意义的代码片段

##### 变化分为三种类型
 1. 逻辑变化 ：只变环一个逻辑  而不涉及其他模块
 2. 子模块变化
 3. 可见视图变化

 
### 为什么采用开闭原则
 
 1. 开闭原则对测试的影响 开闭原则能够减少我们需要修改的地方 通过扩展来实现业务逻辑的变化 而不是修改
 2. 开闭原则则可以提高复用性  提高复用率 缩小逻辑粒度 直到一个逻辑不可再拆分为止
 这样避免日后的维护人员为了修改一个微小的缺陷或增加新功能而要在整个项目到处查找相关的代码
 3. 开闭原则可以提高可维护性
 4. 面向对象开发的要求 需要在设计之初就考虑到所有变化的因素 然后留下接口 等待“可能”转变为“现实”
 
### 如何使用开闭原则

-----
 - 抽象约束 通过接口或抽象类可以约束这一组变化的行为 并能够对外开放 包含三层含义
> - 第一  通过接口或抽象类约束扩展 对扩展进行边界限定 不允许出现在接口或抽象类中不存在的public方法
> - 第二  参数类型 引用对象尽量使用接口或者抽象类 而不是实现类
> - 第三  抽象层尽量保持稳定 一旦确定既不允许修改

- 元数据控制模板行为  尽量使用元数据来控制行为 减少重复开发 元数据是用来描述环境和数据的数据 通俗的说就是配置参数

- 指定项目章程

- 封装变化 有俩层含义 第一 将相同的变化封装到一个接口或抽象类中 第二 将不同的变化封装到不同的接口和抽象类中
不应该有俩个相同的变化出现在同一个接口或抽象类中  封装变化 也就是受保护的变化 找出预计有变化或不稳地的点
我们为这些变化点创建稳定的接口
23个设计模式都是从各个不同的角度对变化进行封装的