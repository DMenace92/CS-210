import re
import string

import os.path
from os import path
from pathlib import Path



def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v




def WordCount():
   try:
        wordList = open("InputFile.txt","r")
        orderList = dict()
        for x in wordList:
            #the strip function eleminates the whitespace or extra space between the values.
            x = x.strip()
            if x in orderList:
               orderList[x] = orderList[x]+1
            else:
               orderList[x]=1
               #using the for in loop with the bultin method keys to return the collection of data values like the map function in javascript.
        for i in (orderList.keys()):
            print(i.capitalize(), " ", orderList[i])
   except:
        print("the file path is not connected")
   wordList.close()
        
    
    
def ItemSearch(v):
     v = v.lower()
     count = 0
     #using a try catch/except to run if true
     try:
         wordList = open("InputFile.txt","r")
         for x in wordList:
             x = x.strip()
             i = x.lower()
             if i == v:
                 count +=1
     except:
         print("Not connected to the list!")
     print(v.capitalize() , " ", count)
     
   # v = v.lower()
  #  try:
    #   wordList = open("InputFile.txt","r")
   #    orderList = dict()
  #     numCount = 0
       #for x in wordList:
           #x = x.strip()
          # i = x.lower()
         #  if i in orderList:
           #    print(orderList, "test output")
          #     if orderList[i] == v:
         #          print(orderList[i], "test output")
        #           numCount += 1
       #            print(numCount)
      #     else:
     #          return "No Item Exists!"   
    #except:
    #    print("the file path is not connected")
    
   # wordList.close()

def displayHistogram():
    try:
        wordList = open("InputFile.txt","r")
        orderList = dict()
        
       # newChar = '*'
       #loop through the object 
        for i in wordList:
            i = i.strip()
            if i in orderList:
                orderList[i] = orderList[i]+1
            else:
                orderList[i] = 1
        for i in (orderList.keys()):
           # print(i.capitalize(), ":", orderList[i])
            newNum = orderList[i]-1
            print(i.capitalize(), "", newNum)
            #because we are working with an intiger we are using the range method
            for i in range(newNum):
                charHold=''
                newNum="*"
                #charHold=" "
                charHold+=newNum
                
                print(charHold)
               

                
                
        
    except:
        print("histogram did not work")

   
    wordList.close()