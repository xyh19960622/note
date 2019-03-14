def debug(func):
    def wrapper(*args, **kwargs):  # 指定宇宙无敌参数
        print("[DEBUG]: enter {}()".format(func.__name__))
        print('Prepare and say...')
        return func(*args, **kwargs)
    return wrapper  # 返回

@debug
def say(something,a,b):
    print("hello {}!".format(something))

def singontong(func): 
    def wrapper(*args,**kwargs):
        print("方法名：{}".format(func.__name__))
        print(**kwargs)
        print("prepare and say...")
        return func(*args,**kwargs)
    return wrapper

@singontong
def fun_name(arg1,arg2,arg3):
    print("123")

if __name__ == '__main__':
    # d = {"s":1,"z":2}
    # fun_name("xx",'a',d)
    print(int(7/3))

