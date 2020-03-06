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
summation=0
sumHolder=float("inf")




def editDistance(sequence1, sequence2, a, b):
    table=[[0 for x in range(b+1)] for x in range(a+1)]

    for i in range(a+1):
        for j in range(b+1):

            if i==0:
                table[i][j]=j

            elif j==0:
                table[i][j]=i

            elif sequence1[i-1]==sequence2[j-1]:
                table[i][j]=table[i-1][j-1]

            else:
                table[i][j]=1 + min(table[i][j-1], table[i-1][j], table[i-1][j-1])


            #print(table[i][j])
    return table[a][b]

print(editDistance(sequence1, sequence2, len(sequence1), len(sequence2)))
