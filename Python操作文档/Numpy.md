<!-- TOC -->

- [一.Numpy 基本操作](#一numpy-基本操作)
  - [1. 创建方法](#1-创建方法)
  - [2. 查询方法](#2-查询方法)
  - [3.数学方法](#3数学方法)
  - [4.排序方法](#4排序方法)
- [二.Pandas 基本操作(增，删，改，查，排，读)](#二pandas-基本操作增删改查排读)
  - [Pandas 支持的数据类型（float,int,str,bool,datetime,timedelta,category,object）](#pandas-支持的数据类型floatintstrbooldatetimetimedeltacategoryobject)
  - [1.文件保存读取](#1文件保存读取)
  - [2. 创建结构](#2-创建结构)
  - [3. 查询方法](#3-查询方法)
  - [4. 新增方法](#4-新增方法)
  - [5. 修改方法](#5-修改方法)
  - [6. 删除方法](#6-删除方法)
  - [7. 排序方法](#7-排序方法)
- [三. 数据绘图](#三-数据绘图)

<!-- /TOC -->

# 一.Numpy 基本操作

## 1. 创建方法

1. 创建一维数组(可以理解为一个向量)：`arr = np.array([1,2,3])`
2. 随机生成 x 行 y 列: `np.arange(10,20).reshape((x,y)`)
3. 随机生成 0 到 x-1 的数组：`np.arange(x)`
4. 生成的值全为 x：`np.full((2,2),x)`
5. 生成 x 行 y 列的 v: `np.tile(v,(x,y))`
6. 随机取 x 个，服从正态分布的均值为 m,标准差为 v: `np.random.normal(m,v,x)`
7. 改变数组形状(-1 为自动填充)：`arr.reshape(1,3) arr.reshape(1,-1)`

## 2. 查询方法

1. 得到数组形状：`arr.shape`
2. 矩阵第 2 行以后：`X[2:]`
3. 矩阵前 2 行： `X[:2]`
4. 返回 x 矩阵中满足条件的个数：`np.count_nonzero(x<=3)`
5. 判断 x 矩阵中任何元素是否满足条件：`np.any(x==0)`
6. 判断 x 矩阵中所有元素是否满足条件：`np.all(x>=0)`
7. 矩阵中的最小值： `np.min(x)`
8. 矩阵中的最大值： `np.max(x)`
9. 返回索引值,最小/大值在数组 x 的哪个位置：`np.argmin(x) np.argmax(x)`
10. 返回矩阵维度:`X.ndim`

## 3.数学方法

1.  求和(可以写满足条件)：`arr.sum() arr.sum(x<3)`
2.  平均值：`arr.mean()`
3.  方差：`arr.std()`
4.  标准差：`arr.var()`
5.  点乘：`arr.dot(x)`
6.  中位数: `np.median(x)`
7.  沿着横轴求和：`np.sum(x,axis=1)`
8.  沿着竖轴求和: `np.sum(x,axis=0)`
9.  对矩阵中的每个数进行乘积运算 `np.prod(x)`
10. 矩阵 x 的逆： `np.linalg.inv(x) 原矩阵.dot(逆矩阵)==单位矩阵`
11. 行列变换：`arr.T`
12. 求矩阵 x 占 y 百分位的值：`np.percentile(x,q=y)`
13. 求平方根：`np.sqrt(x)`

## 4.排序方法

1. 排序 (默认按行排序 axis: 0 列 1 行)：`np.sort(x) np.sort(X,axis=1) np.sort(X,axis=0)`
2. 对矩阵 x 进行乱序：`np.random.shuffle(x)`
3. 返回矩阵 x 排序后的下标：`np.argsort(x)`

# 二.Pandas 基本操作(增，删，改，查，排，读)

## Pandas 支持的数据类型（float,int,str,bool,datetime,timedelta,category,object）

## 1.文件保存读取

1. 读取 csv 文件：

```python
    df = pd.read_csv("xxx.csv",encoding="gbk")
    # 更通用的文本读取形式
    df = pd.read_table("xxx.csv",sep=",",encoding="gbk")
```

2. 读取 excel 文件

```python
    df =pd.read_excel(file_path,sheet_name="xxx")
```

3. 读取 SAS 文件

```python
    df = pd.read_sas('xxxxx.sas7bdat')
```

4. 读取数据库文件

```python
    from sqlalchemy import create_engine
    # conn.txt记录数据库名以及密码。格式：用户名:密码@数据库服务地址:端口/库名
    conndf=pd.read_csv("conn.txt",header=None)
    # 得到数据库数据
    connstr=conndf.iloc[0,0]
    # 连接数据库
    eng=create_engine('mysql+pymysql://'+connstr+'?charset=utf8')
    # 执行sql语句获取表单
    df=pd.read_sql("select * from xxxx",con=eng)
```

5. 保存文件

```python
# 保存为CSV文件
    df.to_csv(
        file_path, # 保存路径
        sep=','  # 列分割符
        columns=['xxx','xxx'], #需要导出的列名
        header = ['xxx','xxx'], # 指定新的列名
        index =True, # 是否导出索引(默认为True)
        model = 'w', # python写模式，读写方式:r,r+,w,w+,a,a+
        endcoding = 'utf-8' #默认导出的文件编码格式
        )
# 保存为Excel文件
    df.to_excel(
        file_path, # 保存路径
        sheet_name="xxx" # 要保存的表名
    )
# 保存至数据库
    df.to_sql(
        name = "xxx", # 将要存储数据的表名称
        con = eng, # SQL引擎
        if_exists = 'fail', # 指定表已经存在的处理方式
                    'fail' # 不做任何处理
                    'replace' # 删除原表并重新建立表格
                    'append' # 在原表后插入数据
        index = True # 是否导出索引(默认为True)

    )
```

## 2. 创建结构

1. Create a Series:

```python
   s = pd.Series (data, index)
```

2. Create a Dataframe:

```python
df = DataFrame (data, index, columns)
eg:
df=pd.DataFrame(
    data=[[33,"178cm"],[25,"165cm"],[28,"180cm"],[31,"162cm"]],
    columns=['Age','Hegiht'],
    index=['Tom','Linad','Smith','Susan']
)
```

3. Create a Panel:

```python
p = Panel (data, items, major_axis, minor_axis)
```

## 3. 查询方法

1. 查看数据前 x 行: `df.head(x)`
2. 查看最后几行数据: `df.tail()`
3. 查看列名,返回 list: `df.columns`
4. 筛选变量列,返回 Series: `df.var` 其中的 var 为列名,若想返回类型为 df,则需要使用: `df[['var']]`,多列时: `df[['var1','var2']]`
5. 查看各列的数据类型: `df.dtypes`
6. 根据下标值进行筛选：`df.iloc[0:3]`等同于`df[0:3]`
7. 返回指定下标值的数据行：`df.iloc[[1,3]]` 返回下标为 1 和 3 的行
8. 返回行范围，列范围的数据：`df.iloc[:,:3]` 返回所有行，前 3 列，`df.iloc[:3,[1:3]]` 返回前 3 行，第 2 列到 3 列
9. 条件筛选查询：`df[df.'var'>1]`
10. 列表筛选，返回结果为符合列表的 Bool 值：`df.var.isin([1,5,9])`,159 行为 True 其余为 False,`df[df.var.isin([1,3,5])]`返回 var 为 1,3,5 的行
11. 多重条件筛选：`df[df.var>10][df[df.var>10].var<20]`,筛选 10<var<20 的数据行
12. 用类 SQL 语句进行筛选

```python
    df.query(
        expr: # 类SQL语句表达式可以使用前缀'@'引用环境变量等号为==而不是=
                # 注意：目前还不支持like语句
        inplace=False #是否直接替换数据框
    )
    # 用法举例
    df.query("名次>10 and 名次<90 and 类型!='综合'")

    limit = 5
    df.query("名次>@limit & 类型 == '综合'")

```

13. 数据分组

```python
    df.groupby(
        by: # 用于分组的变量名
        axis = 0,
        level = None,# 指定用于分组的级别
        as_index = True, # 在结果中将组标签作为索引
    )
    eg : dfg = df.groupby('类型')
         dict = dfg.groups   # 返回字典类型
         des = dfg.describe() # 获取分组后详细信息，类型为DF
         dfg.mean() # 计算分组后的的平均值
         dfg.get_group('value') # 返回分组后值为value的数据行
         dfg.get_group('value').mean() # 返回分组后职位value的数据行并进行数学运算
         dfg['var'].max() # 该操作也适用于统计对不同变量列进行不同操作时
         # 通常分完组后会进行汇总
         dfg.agg('count')
         dfg.agg(['mean','median'])
         # 也可引用非内置函数
         dfg.var.agg(np.sum)
         # 也可引用自定义函数
         dfg.agg(my_mean)
         # 可以对照以下的方法图进行选择合适的方法
                ||
                ||
                ||
                \/
```

<img src=".img/agg_methd.png" width="500">

14. 转换为最简格式：`df.stack()` # 转换后的结果可能为 Series

15. 数据查重

```python
    df['dup'] = df.duplicated(['var1','var2','...'])
    # 直接删除重复行
    df.drop_duplicates(['var1','var2'])
    # 利用查重标识直接删除
    df[~df.duplicated(['var1','var2','...'])]
```

16. 变量列统计:

```python
    df.value_counts(
        sort = True,# 默认升序排列
        bins = xx #对数值分段
        dropna = True # 结果中是否包括NAN
    )
    ef: df.var.value_counts(bins=10)

```

## 4. 新增方法

1. 不修改源数据，将计算出的值生成新的一列

```python
    df2 = df.assign(newVar = df.总分.apply(np.sqrt))
```

2. 在指定位置插入新变量列

```python
    #注意：该方法会直接覆盖数据源
    df.insert(
        loc:# 插入位置的索引值    0<=loc<=len(columns)
        column:# 插入的新列名称
        value:# Series或者类数组结构的变量值
    )
    eg: df.insert(1,'newVar','cons')  # 第一列插入newVar,值为cons
```

3.变量分段

```python
    pd.cut(
        x:# 变量列名称
        bins：# 具体的分段范围，每一个分段点
        right = True # 每段是否包括右侧界值
        labels = None # 为每个分段提供自定义标签
        include_lowest = False# 第一段是否包括最左侧界值，需要和right参数配合
    )
    eg: df['new_var'] = pd.cut(df.var,bins=[1,3,5],right=True,include_lowest=True) # 将var列的值进行分段，分为满足bins的范围
```

4. 数据的合并

```python
    # 纵向合并
    df.append(
        other:# 希望添加的DF/Series/字典
        ignore_index = False,# 添加时是否忽略索引
        verify_integrity = False# 是否检查索引值得唯一性，有重复时报错
    )
    eg: df.append(df2)
    # 横向合并
    eg: df.merge(df1,df2)
    # Concat 同时支持纵向横向合并
    pd.concat(
        objs: #需要合并的对象，列表形式
        axis = 0 # 对行还是列方向合并0行一列
        key = None, # 为不同数据源提供合并后的索引值
    )
    eg: dfc = pd.concat([df1,df2],keys=['A','B'],axis=1)
```

5. 时间操作

```python
    # 直接转换
    pd.Timestamp(2015,12,1)
    # 基于所需变量列合成Timestamp类
    pd.to_datetime(df[['Year','Month','Day','Hour']])
```

## 5. 修改方法

1. 修改指定列名:

```python

    df.rename(
        columns={"旧名称":"新名称"},
        inplace =True) # 是否修改源数据框

```

2. 修改数据类型

```python
    # 统一全部修改
    df.astype(
        'str',   # 将数据全部修改为字符串类型
        copy = True, # 是否生成新副本，而不是覆盖源数据
        errors = "raise" #转换出错时是否抛出异常 'raise/ignore'
    )
    # 指定某列修改
    df.var.astype('str')  # 将var列的数据类型修改为字符串
    # 指定多列批量修改
    df[["var1","var2"]].astype('str')
    # 基于数据特征自动进行转换
    df.infer_objects().dtypes
```

3. 将某列变为索引列，以及还原变量列

```python
    # 某列变为索引列
    df.set_index(
        ['var1','var2'], # 列名
        drop = True, # 建立索引后是否删除改列
        append = False, # 是否在原索引基础上增加索引，默认直接替换原索引
        inplace = False, # 是否直接替换原数据框
    )
    # 还原变量列
    df.reset_index(
        drop = False, # 是否将索引删除而不是还原变量列
        inplace = False, # 是否直接修改源数据框
    )
```

4. 基于变量做简单的四则运算

```python
    import numpy as np
    # 求var列的平方根
    df['var'] = np.sqrt(df.var)

    # 基于原变量做函数运算
    df['new'] = df.var.apply(np.sqrt)

```

5. 正确修改变量值:`df.loc[70,'var'] = 'newValue'`

6. 修改变量值

```python
    # 所有列的root_value全部替换new_value
    df.replace('root_value','new_Value')
    # 单个列的值替换
    df.var.replace('root_vaule','newValue')
    # 单个列的多个值替换
    df.var.replace(['root_vaule1','root_value2'],['newValue1','newValue2'])
    # 指定数值范围的替换
    df.var.iloc[0:2] = 10
    df.loc[3:5,'var'] = 10
    # 用loc命令完成范围替换
    df.loc[df.var<10,'var1'] = 10 # 把var小于10的var1列变量=10
    # 直接定位替换
    df.var[df.var1<10] = 10 # 同上，但会有警告，不建议这么做
    # query语句可以用index定位，然后实现数值替换
    df.loc[df.query("名次<=10 and 类型!='综合'").index,'总分'] = 10
```

7. 处理缺失值

```python
    # 处理自定义缺失值
    df_na = df.replace(['value1','value2'],[np.nan,np.nan])
    # 检查相应的数据是否为缺失值
    df.isna()
    # 缺失值填充
    df.fillna('value')
```

## 6. 删除方法

1. 删除变量列:

```python
    df.drop(
        columns = ["var"] # var为列名
    )
```

## 7. 排序方法

1. 用索引排序

```python
    df.sort_index(
        ['index1','index2'], # 指定排序级别顺序号
        ascending = True,# 是否为升序排序
        inplace = False, # 是否直接替换数据源
        na_position = 'last' # 缺失值的排列顺序
    )
```

2. 用变量值排序

```python
    df.sort_values(
        ['var1','var2'], # 需要排序的列
        ascending=True, #是否为升序排列
        inplace = False, # 是否直接替换源数据
        na_position = 'last' #缺失值得排列顺序
    )
```

# 三. 数据绘图

1. 条形图

```python
    # 横向简单条图
    pd.value_counts(df.var).plot.barh()
    # 纵向简单条图
    pd.value_counts(df.var).plot.bar()
    # 分段条图
    df.plot.bar(stacked=True)

```

2. 直方图

```python
    # 简单直方图
    df.var.plot.hist(by=df.var,bins=20)# bins:需要拆分的组数,by:用于分组的变量列
```

3. 饼图

```python
    # 简单饼图
    df.var.value_counts().plot.pie()
```

4. 散点图

```python
    #简单散点图
    df.plot.scatter('总分','名次')
    # 修饰
    df.plot.scatter(x='var1',y='var2',s=df.var2)
    # 重叠散点图
    ax =  df2.plot.scatter(x='var1',y='var2',color='blue',label='Group 1')
    df2.plot.scatter(x='var1',y='var2',color='blue',label='Group 2',ax = ax)
```
