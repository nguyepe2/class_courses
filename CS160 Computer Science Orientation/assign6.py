# n = number of rectangles and/or trapezoids
# a = beginning x value
# b = ending x value
# w = width of each rectangle/trapezoid, (b-a)/n
# f(x) = height of rectangle
# (f(x1)+f(x2))/2 = height of trapezoid
# Area = width*height
run=True
def start():
	shape=str(input("For the area calculation, would you like to use a rectangle, trapezoid, or both: "))
	if "1" in function:
		if "rectangle" in shape:
			n=float(input("How many "+str(shape)+"s do you want?: "))
			a=int(input("Please select a starting point: "))
			b=int(input("Please select a ending point: "))
			f1=str(5*a**4 + 3*a**3 - 10*a + 2)
			f2=str(5*b**4 + 3*b**3 - 10*b + 2)
			h=float(f2)
			w=float((b-a)/n)
			print("The area under 5x**4 + 3x**3 - 10x + 2 between "+str(a) + " and " +str(b) +" is: " +str(w*h))

		elif "trapezoid" in shape:
			n=float(input("How many "+str(shape)+"s do you want?: "))
			a=int(input("Please select a starting point: "))
			b=int(input("Please select a ending point: "))
			f1=float(5*a**4 + 3*a**3 - 10*a + 2)
			f2=float(5*b**4 + 3*b**3 - 10*b + 2)
			h=float(((f1+f2)/2))
			w=float((b-a)/n)
			print("The area under 5x**4 + 3x**3 - 10x + 2 between "+str(a) + " and " +str(b) +" is: " +str(w*h))

		elif "both" in shape:
			n1=float(input("How many rectangles do you want?: "))
			n2=float(input("How many trapezoids do you want: "))
			a=int(input("Please select a starting point: "))
			b=int(input("Please select a ending point: "))
			f1=float(5*a**4 + 3*a**3 - 10*a + 2)
			f2=float(5*b**4 + 3*b**3 - 10*b + 2)
			h1=float(f2)
			h2=float(((f1+f2)/2))
			w1=float((b-a)/n1)
			w2=float((b-a)/n2)
			print("The area of the rectangles under 5x**4 + 3x**3 - 10x + 2 between "+str(a) + " and " +str(b) +" is: " +str(w1*h1))	
			print("The area of the trapezoids  under 5x**4 + 3x**3 - 10x + 2 between "+str(a) + " and " +str(b) +" is: " +str(w2*h2))

	if "2" in function:
		if "rectangle" in shape:
			n=float(input("How many "+str(shape)+"s do you want?: "))
			a=int(input("Please select a starting point: "))
			b=int(input("Please select a ending point: "))
			f1=float(a**2 - 10)
			f2=float(b**2 - 10)
			h=float(f2)
			w=float((b-a)/n)
			print("The area under x**2 - 10 between "+str(a) + " and " +str(b) +" is: " +str(w*h))

		elif "trapezoid" in shape:
			n=float(input("How many "+str(shape)+"s do you want?: "))
			a=int(input("Please select a starting point: "))
			b=int(input("Please select a ending point: "))
			f1=float(a**2 - 10)
			f2=float(b**2 - 10)
			h=float(((f1+f2)/2))
			w=float((b-a)/n)
			print("The area under x**2 - 10 between "+str(a) + " and " +str(b) +" is: " +str(w*h))
		elif "both" in shape:
			n1=float(input("How many rectangles do you want?: "))
			n2=float(input("How many trapezoids do you want: "))
			a=int(input("Please select a starting point: "))
			b=int(input("Please select a ending point: "))
			f1=float(a**2 - 10)
			f2=float(b**2 - 10)
			h1=float(f2)
			h2=float(((f1+f2)/2))
			w1=float((b-a)/n1)
			w2=float((b-a)/n2)
			print("The area of the rectangles under x**2 - 10 between "+str(a) + " and " +str(b) +" is: " +str(w1*h1))
			print("The area of the trapezoids under x**2 - 10 between "+str(a) + " and " +str(b) +" is: " +str(w2*h2))

	if "3" in function:
		if "rectangle" in shape:
			n=float(input("How many "+str(shape)+"s do you want?: "))
			a=int(input("Please select a starting point: "))
			b=int(input("Please select a ending point: "))
			f1=float(40*a + 5)
			f2=float(40*b + 5)
			h=float(f2)
			w=float((b-a)/n)
			print("The area under 40x + 5 between "+str(a) + " and " +str(b) +" is: " +str(w*h))

		elif "trapezoid" in shape:
			n=float(input("How many "+str(shape)+"s do you want?: "))
			a=int(input("Please select a starting point: "))
			b=int(input("Please select a ending point: "))
			f1=float(40*a + 5)
			f2=float(40*b + 5)
			h=float(((f1+f2)/2))
			w=float((b-a)/n)
			print("The area under 40x + 5 between "+str(a) + " and " +str(b) +" is: " +str(w*h))
		elif "both" in shape:
			n1=float(input("How many rectangles do you want?: "))
			n2=float(input("How many trapezoids do you want: "))
			a=int(input("Please select a starting point: "))
			b=int(input("Please select a ending point: "))
			f1=float(40*a + 5)
			f2=float(40*b + 5)
			h1=float(f2)
			h2=float(((f1+f2)/2))
			w1=float((b-a)/n1)
			w2=float((b-a)/n2)
			print("The area of the rectangles under 40x + 5 between "+str(a) + " and " +str(b) +" is: " +str(w1*h1))
			print("The area of the trapezoids under 40x + 5 between "+str(a) + " and " +str(b) +" is: " +str(w2*h2))

	if "4" in function:
		if "rectangle" in shape:
			n=float(input("How many "+str(shape)+"s do you want?: "))
			a=float(input("Please select a starting point: "))
			b=float(input("Please select a ending point: "))
			f1=float(a**3)
			f2=float(b**3)
			h=float(f2)
			w=float((b-a)/n)
			print("The area under x**3 between "+str(a) + " and " +str(b) +" is: " +str(w*h))

		elif "trapezoid" in shape:
			n=float(input("How many "+str(shape)+"s do you want?: "))
			a=float(input("Please select a starting point: "))
			b=float(input("Please select a ending point: "))
			f1=float(a**3)
			f2=float(b**3)
			h=float(((f1+f2)/2))
			w=float((b-a)/n)
			print("The area under x**3 between "+str(a) + " and " +str(b) +" is: " +str(w*h))
		elif "both" in shape:
			n1=float(input("How many rectangles do you want?: "))
			n2=float(input("How many trapezoids do you want: "))
			a=float(input("Please select a starting point: "))
			b=float(input("Please select a ending point: "))
			f1=float(a**3)
			f2=float(b**3)
			h1=float(f2)
			h2=float(((f1+f2)/2))
			w1=float((b-a)/n1)
			w2=float((b-a)/n2)
			print("The area of the rectangles under x**3 between "+str(a) + " and " +str(b) +" is: " +str(w1*h1))
			print("The area of the trapezoids under x**3 between "+str(a) + " and " +str(b) +" is: " +str(w2*h2))

	if "5" in function:
		if "rectangle" in shape:
			n=float(input("How many "+str(shape)+"s do you want?: "))
			a=float(input("Please select a starting point: "))
			b=float(input("Please select a ending point: "))
			f1=float(20*a**2 + 10*a - 2)
			f2=float(20*b**2 + 10*b - 2)
			h=float(f2)
			w=float((b-a)/n)
			print("The area under 20x*a**2 + 10*x - 2 between "+str(a) + " and " +str(b) +" is: " +str(w*h))

		elif "trapezoid" in shape:
			n=float(input("How many "+str(shape)+"s do you want?: "))
			a=float(input("Please select a starting point: "))
			b=float(input("Please select a ending point: "))
			f1=float(20*a**2 + 10*a - 2)
			f2=float(20*b**2 + 10*b - 2)
			h=float(((f1+f2)/2))
			w=float((b-a)/n)
			print("The area under 20x*a**2 + 10*x - 2 between "+str(a) + " and " +str(b) +" is: " +str(w*h))
		elif "both" in shape:
			n1=float(input("How many rectangles do you want?: "))
			n2=float(input("How many trapezoids do you want: "))
			a=float(input("Please select a starting point: "))
			b=float(input("Please select a ending point: "))
			f1=float(20*a**2 + 10*a - 2)
			f2=float(20*b**2 + 10*b - 2)
			h1=float(f2)
			h2=float(((f1+f2)/2))
			w1=float((b-a)/n1)
			w2=float((b-a)/n2)
			print("The area of the rectangles under 20x*a**2 + 10*x - 2 between "+str(a) + " and " +str(b) +" is: " +str(w1*h1))
			print("The area of the trapezoids under 20x*a**2 + 10*x - 2 between "+str(a) + " and " +str(b) +" is: " +str(w2*h2))
while run:
	function=str(input("Choose a function (1,2,3,4,5, quit): "))
	if function=="quit":
		break
	start()
