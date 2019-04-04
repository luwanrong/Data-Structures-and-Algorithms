from numpy import *  
import operator
import os



# create a dataset which contains 3 samples with 2 classes  
def createDataSet():  
    # create a matrix: each row as a sample  
    group = array([[3,3], [4,3], [1,1]])  
    labels = [1, 1, -1] # four samples and two classes  
    return group, labels

#classify using perceptron
def perceptronClassify(trainGroup,trainLabels):
    global w, b
    isFind = False  #the flag of find the best w and b
    numSamples = trainGroup.shape[0]
    mLenth = trainGroup.shape[1]
    w = [0]*mLenth
    b = 0
    while(not isFind):
        for i in xrange(numSamples):
            if cal(trainGroup[i],trainLabels[i]) <= 0:
                print（w,b）
                update(trainGroup[i],trainLabels[i])
                break    #end for loop
            elif i == numSamples-1:
                print w,b
                isFind = True   #end while loop


def cal(row,trainLabel):
    global w, b
    res = 0
    for i in xrange(len(row)):
        res += row[i] * w[i]
    res += b
    res *= trainLabel
    return res
def update(row,trainLabel):
    global w, b
    for i in xrange(len(row)):
        w[i] += trainLabel * row[i]
    b += trainLabel
