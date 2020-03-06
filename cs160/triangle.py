num=1
x=int(input("Input the number of stars, which must be an ood number: "))
space=int((x-1)/2)
while(num<=x):
	print(" "*space+"*"*num)
	space=space-1
	num=num+2
