import random


f=open("100000.txt", "w") #change the file name to change the file to print to
num=random.sample(range(1,300000), 200000) #change the second number to change the maximum range of random numbers, and change the third number to change the amount of numbers you want to generate

#print(num)
#print(num[0]);

for x in range(200000): #change this number to change how many numbers you want to print to the file
   f.write(str(num[x]))
   f.write(" ")
   if x % 2 == 1:
      f.write('\n')
#print(num)
