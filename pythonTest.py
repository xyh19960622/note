import time

def singelton(cls):
    instance ={}
    def warpper(*args,**kwargs):
        if cls not in instance:
            instance[cls] = cls(*args,**kwargs)
        return instance[cls]
    return warpper

@singelton
def Foo():
    pass
if __name__ == '__main__':
    print([x for x in filter(lambda x: x % 2 == 0, range(10))])
