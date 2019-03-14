# 一.Numpy基本操作

## 1. 创建方法
1. 创建一维数组(可以理解为一个向量)：`arr = np.array([1,2,3])`
2. 随机生成x行y列: `np.arange(10,20).reshape((x,y)`)
3. 随机生成0到x-1的数组：`np.arange(x)`
4. 生成的值全为x：`np.full((2,2),x)`
5. 生成x行y列的v: `np.tile(v,(x,y))`
6. 随机取x个，服从正态分布的均值为m,标准差为v: `np.random.normal(m,v,x)`
7. 改变数组形状(-1为自动填充)：`arr.reshape(1,3) arr.reshape(1,-1)`
## 2. 查询方法
1. 得到数组形状：`arr.shape`
2. 矩阵后2行：`X[2:]`
3. 矩阵前2行： `X[:2]`
4. 返回x矩阵中满足条件的个数：`np.count_nonzero(x<=3)`
5. 判断x矩阵中任何元素是否满足条件：`np.any(x==0)`
6. 判断x矩阵中所有元素是否满足条件：`np.all(x>=0)`
7. 矩阵中的最小值： `np.min(x)`
8. 矩阵中的最大值： `np.max(x)`
9. 返回索引值,最小/大值在数组x的哪个位置：`np.argmin(x) np.argmax(x)`
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
10. 矩阵x的逆： `np.linalg.inv(x) 原矩阵.dot(逆矩阵)==单位矩阵`
11. 行列变换：`arr.T`
12. 求矩阵x占y百分位的值：`np.percentile(x,q=y)`
## 4.排序方法
1. 排序 (默认按行排序 axis: 0 列 1 行)：`np.sort(x) np.sort(X,axis=1) np.sort(X,axis=0)`
2. 对矩阵x进行乱序：`np.random.shuffle(x)`
3. 返回矩阵x排序后的下标：`np.argsort(x)`

```python
def code():
    print("123456")
    print"123456")
    print("123456")
    print("123456")
    print("123456")
    print("python")

```    