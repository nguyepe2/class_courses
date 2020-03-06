import math
print(a)
x=0
while(x<10):
	w=int(input("input the weight of the spehere in pounds: "))
	r=int(input("input the radius of the sphere in feet: "))
	V=(4/3)*math.pi*r**3
	water=62.4
	F=V*water
	if F>w:
		print("This sphere will float")
	else: 
		print("This sphere will sink")
	x=x+1
