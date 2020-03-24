import random

sequence1=""
sequence2=""
letters=["A", "T", "C", "G"]

for x in range(0, 500):
    num=random.randint(0,3)
    sequence1=sequence1+letters[num]
    num=random.randint(0,3)
    sequence2=sequence2+letters[num]

#print(sequence1)
f=open("500", 'w')
f.write(sequence1 + "," + sequence2 + '\n')
sequence1=""
sequence2=""
f.close()

for x in range(0, 1000):
    num=random.randint(0,3)
    sequence1=sequence1+letters[num]
    num=random.randint(0,3)
    sequence2=sequence2+letters[num]

#print(sequence1)
f=open("1000", 'w')
f.write(sequence1 + "," + sequence2 + '\n')
sequence1=""
sequence2=""
f.close()

for x in range(0, 2000):
    num=random.randint(0,3)
    sequence1=sequence1+letters[num]
    num=random.randint(0,3)
    sequence2=sequence2+letters[num]

#print(sequence1)
f=open("2000", 'w')
f.write(sequence1 + "," + sequence2 + '\n')
sequence1=""
sequence2=""
f.close()

for x in range(0, 4000):
    num=random.randint(0,3)
    sequence1=sequence1+letters[num]
    num=random.randint(0,3)
    sequence2=sequence2+letters[num]

#print(sequence1)
f=open("4000", 'w')
f.write(sequence1 + "," + sequence2 + '\n')
sequence1=""
sequence2=""
f.close()

for x in range(0, 5000):
    num=random.randint(0,3)
    sequence1=sequence1+letters[num]
    num=random.randint(0,3)
    sequence2=sequence2+letters[num]

#print(sequence1)
f=open("5000", 'w')
f.write(sequence1 + "," + sequence2 + '\n')
sequence1=""
sequence2=""
f.close()
