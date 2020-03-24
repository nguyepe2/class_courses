import sys
import time

start_time=time.time()

#print('Number of arguments:', len(sys.argv), 'arguments.')
#print('Argument List:', str(sys.argv))

args=len(sys.argv)
if(args!=3):
   sys.exit("invalid number of arguments, must be formated in the form: align.py cost_file input_file")

cost_file=open(sys.argv[1], "r")
#print(cost_file.read())
input_file=open(sys.argv[2], "r")
#print(input_file.readline())

f=open("imp2output.txt", "a")


while True:

    line=input_file.readline()

    if not line:
        break

    sequences=line.split(",")
    #print(sequences)

    sequence1=sequences[0]
    seq2=sequences[1]
    secondSequence=seq2.split("\n") #removes the newline char from the second sequence
    sequence2=secondSequence[0]
    #print(sequence1)
    #sequence2.strip('\n')
    #print(sequence2)

    end1=len(sequence1)-1
    end2=len(sequence2)-1

    #print(sequence1[end1])
    #print(sequence2[end2])

    #creates a list of the possible char values
    chk1=cost_file.readline()

    if not chk1:
        cost_file.close()
        cost_file=open(sys.argv[1], "r")

        chk1=cost_file.readline()

    check1=chk1.split(",")
    #print(check1)
    endLineRemover=check1[5]
    newFive=endLineRemover.split("\n")
    fifth=newFive[0]
    check1[5]=fifth
    #print(check1)

    lines=cost_file.readlines()
    i=0
    j=0
    inc=0
    summation=0
    sumHolder=float("inf")

    #----------------------------------------------------------------
    a=len(sequence1)
    b=len(sequence2)

    if(a<b):
       s=a
       L=b
    else:
       s=b
       L=a
    #print("small", s)
    #print("large", L)
    newSequence1=["-"] * (2*s + L) #creates an array of '-'
    newSequence2=newSequence1.copy()
    #print(len(newSequence1))
    #print("len s1: ", newSequence1)
    #print("len s2: ", newSequence2)
    #print(newSequence1)

    #This is probably where the while loop will go
    #print("length: ", len(newSequence1)-s-1)
    while inc < s+1:
        #print("inc num: ", inc)
        #print("length: ", len(newSequence1)-s)
        #print("s val: ", s)
        #print("length of newSequence1:", len(newSequence1))

        summation=0
        a=len(sequence1)
        b=len(sequence2)

        if(a<b):
           s=a
           L=b
        else:
           s=b
           L=a
        newSequence2=["-"] * (2*s + L) #creates an array of '-'
        for y in range(s): #copies smallest sequence into the new list
           if(a<b):
              newSequence2[y+inc]=sequence1[y]
           else:
              newSequence2[y+inc]=sequence2[y]
        smallCount=y
        #print(newSequence2)

        #s=0
        for y in range(L): #copies largest sequence into the new list
           if(a>b):
              newSequence1[s]=sequence1[y]
              s=s+1
           else:
              newSequence1[s]=sequence2[y]
              s=s+1
        #print(newSequence1)
        #s=0
        #L=0

        #------------------------------------------------------------

        for counter in range(len(newSequence1)):
           #get cost of alignment
           #print("iteration: ",counter)
           #print("small count: ", smallCount)
           #print(i)
           #print("sequence letter", sequence1[x])
           for x in range(len(check1)):
              if(newSequence1[i]==check1[x]):
               rows=x #the row that cost is on
              #i=i+1

               #print("row: ", rows)
           #if(x==len(newSequence1)-1):
           #print(x)
           #i=0
          # print("sequence2 letter", sequence2[x])
           for x in range(len(check1)):
              if(newSequence2[j]==check1[x]):
               cols=x #the column that the cost is on
              #j=j+1

               #print("col: ", cols)
           #print(lines)
           charRow=lines[rows-1]
           values=charRow.split(",")
           #print(values)
           part=values[cols] #part is the cost of the alignment for that index
           #print("part value: ", part)
           #j=0
           i=i+1
           j=j+1

           summation=summation+int(part)

           if(counter==len(newSequence1)-1 and summation < sumHolder):
               optSequence1=newSequence1.copy()
               optSequence2=newSequence2.copy()
               sumHolder=summation
               #print("new min sum: ", sumHolder)
               #summation=0 #reset the sum
               #print(s)
               #print(L)
               #newSequence2=["-"] * (2*s + L) #creates an array of '-'

               i=0
               j=0
               inc=inc+1

           elif(counter==len(newSequence1)-1):
               #newSequence2=["-"] * (2*s + L) #creates an array of '-'

               inc=inc+1
               i=0
               j=0
               #print("Not new sum: ", summation)
               #summation=0


       #print("value of next iteration of i: ", i, '\n')
    f.write(str(sequence1) + ", " + str(sequence2) + ":" + str(sumHolder) + '\n')
#print("%s seconds " %(time.time()-start_time))
