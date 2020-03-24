import sys


#print('Number of arguments:', len(sys.argv), 'arguments.')
#print('Argument List:', str(sys.argv))

args=len(sys.argv)
if(args!=3):
   sys.exit("invalid number of arguments, must be formated in the form: align.py cost_file input_file")

cost_file=open(sys.argv[1], "r")
#print(cost_file.read())
input_file=open(sys.argv[2], "r")
#print(input_file.readline())

line=input_file.readline()
sequences=line.split(",")
print(sequences)

sequence1=sequences[0]
seq2=sequences[1]
secondSequence=seq2.split("\n") #removes the newline char from the second sequence
sequence2=secondSequence[0]
print(sequence1)
#sequence2.strip('\n')
print(sequence2)

end1=len(sequence1)-1
end2=len(sequence2)-1

print(sequence1[end1])
print(sequence2[end2])

#creates a list of the possible char values
chk1=cost_file.readline()
check1=chk1.split(",")
print(check1)
endLineRemover=check1[5]
newFive=endLineRemover.split("\n")
fifth=newFive[0]
check1[5]=fifth
print(check1)

lines=cost_file.readlines()
i=0
j=0
inc=0

#----------------------------------------------------------------
a=len(sequence1)
b=len(sequence2)

if(a<b):
   s=a
   L=b
else:
   s=b
   L=a
print("small", s)
print("large", L)
newSequence1=["-"] * (2*s + L) #creates an array of '-'
newSequence2=newSequence1.copy()
print(len(newSequence1))
#print("len s1: ", newSequence1)
#print("len s2: ", newSequence2)
#print(newSequence1)

for y in range(s): #copies smallest sequence into the new list
   if(a<b):
      newSequence2[y+inc]=sequence1[y]
   else:
      newSequence2[y]=sequence2[y]
smallCount=y
print(newSequence2)

for y in range(L): #copies largest sequence into the new list
   if(a>b):
      newSequence1[s]=sequence1[y]
      s=s+1
   else:
      newSequence1[s]=sequence2[y]
      s=s+1
print(newSequence1)

#------------------------------------------------------------

for x in range(len(newSequence1)):
   #get cost of alignment
   #print(x)
   #print(smallCount)
   #print("sequence letter", sequence1[x])
   for x in range(len(check1)):
      if(newSequence1[i]==check1[x]):
       rows=x #the row that cost is on
       #print("row: ", rows)
   #if(x==len(newSequence1)-1):
   #print(x)

  # print("sequence2 letter", sequence2[x])
   for x in range(len(check1)):
      if(newSequence2[j]==check1[x]):
       cols=x #the column that the cost is on
       #print("col: ", cols)
   #print(lines)
   charRow=lines[rows-1]
   values=charRow.split(",")
   #print(values)
   part=values[cols] #part is the cost of the alignment for that index
   print("part value: ", part)

   i=i+1
   j=j+1
   #print("value of next iteration of i: ", i, '\n')

#Next steps:
#DONE 1. replace end1 and end2 with actual index variables (maybe have a var)
#that only increments after part is calculated?
#
#2. Use my psuedo-code to allow for the two sequences to be compared to each
# other
#2b. Need to find a way to shift smaller sequence
#
#3. Increment a sum variable using the part variable to keep track of the min score
#
#4. keep track of the min sum by replacing the sum when a lower sum is found
#
#5. When a new min is found, copy the sequences into different lists to hold
# onto them
