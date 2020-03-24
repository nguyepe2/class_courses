import turtle
window=turtle.Screen()
my_turtle=turtle.Turtle()
window.mainloop()
run=True
x=1
while run:
	main=str(input("Please input which shape you want to draw. (triangle, square, hexagon, octagon): "))
	if main=="triangle":
		for x in range(3):
			turtle.forward(100)
			turtle.right(120)

	elif main=="square":		
		for x in range(4):
			turtle.forward(100)
			turtle.right(90)

	elif main=="hexagon":			
		for x in range(6):
			turtle.forward(100)
			turtle.right(60)

	elif main=="octagon":
		for x in range(8):
			turtle.forward(100)
			turtle.right(45)
	else:
		print("Your input is invalid")
	x=x+1
	cont=str(input("Would you like to continue drawing shapes? (yes, no): "))
	if cont=="yes":
		turtle.reset()
	elif cont=="no":
		break
	else:
		print("Your input is invalid")
		break
