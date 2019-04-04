import time as t
class MyTimer:
    def start(self):
        self.begin = t.localtime()#把t.localtime得到的当前时间返回给变量
        print('计时开始...\n开始时间为：')
        print(t.strftime('%Y-%m-%d-%H-%M-%S', self.begin))
    def stop(self):
        if self.begin==0:
            print('请先调用start()开始计时')
        else:
            self.end = t.localtime()
            print('计时结束...\n结束时间为：')
            print(t.strftime('%Y-%m-%d-%H-%M-%S', self.end))
            self._calc()
    #函数名前面加_下划线表示内部方法,可在类内部调用
    def _calc(self):
        self.exerted = [] #定义一个元组存放时间
        self.tip = '运行时间为'
        for i in range(6):
            self.exerted.append(self.end[i] - self.begin[i])
            self.tip=self.tip+str(self.exerted[i])
        # print(self.tip)
    def __str__(self):
        return self.tip
    def __repr__(self):
        return self.tip
    def __init__(self):
        self.tip = '未开始计时'
        self.begin = 0
    def __add__(self,other):
        tip = '总共运行了'
        result = []
        for i in range(6):
            result.append(self.exerted[i]+other.exerted[i])
        return result



