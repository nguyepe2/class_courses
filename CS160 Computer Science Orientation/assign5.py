run=True
def start():
	mode=input("To choose a calculator mode, please type 'programmer' or 'scientific', and press enter: ")	
	if "programmer" in mode:
		deci=int(input("Please input a decimal number that you would like to be converted to binary: "))

		bit10=0
		bit9=0
		bit8=0
		bit7=0
		bit6=0
		bit5=0
		bit4=0
		bit3=0
		bit2=0
		bit1=0

		bit10=deci%2
		deci=deci//2
		bit9=deci%2
		deci=deci//2
		bit8=deci%2
		deci=deci//2
		bit7=deci%2
		deci=deci//2
		bit6=deci%2
		deci=deci//2
		bit5=deci%2
		deci=deci//2
		bit4=deci%2
		deci=deci//2
		bit3=deci%2	
		deci=deci//2
		bit2=deci%2
		deci=deci//2
		bit1=deci%2
		deci=deci//2

		binary=str(bit1)+str(bit2)+str(bit3)+str(bit4)+str(bit5)+str(bit6)+str(bit7)+str(bit8)+str(bit9)+str(bit10)
		print(binary.lstrip("0"))
	if "scientific" in mode:
		operator=input("Please select one of the following operators. +, -, *, /, ** : ")
		num1=float(input("Pleace input the first number: "))
		num2=float(input("Please input the second number: "))
		if "+" is operator:
			print(num1+num2)
		elif "-" is operator:
			print(num1-num2)
		elif "*" is operator:
			print(num1*num2)
		elif "/" is operator:
			print(num1/num2)
		elif "**"==operator:
			print(num1**num2)
		else:
			print("That is not a proper operator")
while run:
	stop=input("If you would like to end the loop, type 'quit', otherwise hit enter to continue to the calculator modes: ")
	if stop=="quit":
		break
	start()
