import random

#to run program, type python3 mypython.py

#initializes strings
aString=""
bString=""
cString=""
letters = ["a", "b", "c", "d", "e", "f", "g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]

for x in range(0,10):
    num=random.randint(0, 25)
    aString=aString+letters[num]
    num=random.randint(0, 25)
    bString=bString+letters[num]
    num=random.randint(0, 25)
    cString=cString+letters[num]

print(aString)
print(bString)
print(cString)

f=open("file1", 'w');
f.write(aString)
f=open("file1", 'a');
f.write('\n')

f=open("file2", 'w');
f.write(bString)
f=open("file2", 'a');
f.write('\n')

f=open("file3", 'w');
f.write(cString)
f=open("file3", 'a');
f.write('\n')

factor1=random.randint(1,42)
print(factor1)
factor2=random.randint(1,42)
print(factor2)

print(factor1*factor2)
