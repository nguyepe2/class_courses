# Function Name: main
# Description: Runs the program
# Paramaters: None
# Pre-conditions: None
# Post-conditions: None
# Return: Percent of matching characters
run=True
def main():
	if len(string1) > len(string2):
		short=len(string2)
		longer=len(string1)
	else:
		short=len(string1)
		longer=len(string2)
	a=sum([x==y for (x, y) in zip(string1, string2)])
	percent=int(a)/int(longer)
	print(str(percent*100)+str(" percent matching"))
while run:	
	string1=str(input("Please input the first word or type 'quit' to end the loop: "))
	string2=str(input("Please input the second word or type 'quit' to end the loop: "))
	if string1=="quit" or string2=="quit":
		break
	main()
