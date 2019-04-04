'''import tkinter as tk
root = tk.Tk()
root.title("FishC Demo")
theLabel = tk.Label(root,text= '我的窗口程序！')

theLabel.pack()#自动凋节label组件的位置，没有这一句可能显示不出来
root.mainloop()

class App:
    def __init__(self,root):

        frame = tk.Frame(root)
        frame.pack()
        self.hi_there = tk.Button(frame,text = "打招呼",fg = "blue",command = self.say_hi)
        self.hi_there.pack(side = tk.LEFT)

    def say_hi(self):
        print('大家好!')
        
        
        



root = tk.Tk()
root.title("hello")
app = App(root)

root.mainloop()'''
from tkinter import *
root = Tk()
GIRLS = ['A','B','C','D']
v = []
for girl in GIRLS:
    v.append(IntVar())
    b=Checkbutton(root,text = girl,variable = v[-1])
    b.pack()

    print(v)

mainloop()
    

