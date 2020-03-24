import random
def main():
	num=random.randint(1,20)
	attempts=[]
#	for i in range(5):
	i=0
	while i < 5:
		guess=input("Guess a number 1-20: ")
		if guess==str(num):
#		if guess==str(num):
			print(str(guess)+" is the right number")
			break
		elif guess in attempts:
#		elif list(attempts)==guess:
			print("You've already guessed that number")
		else:
			i=i+1
			print("nope")
			attempts.append(guess)
#	i=i+1
	print("Your list of incorrect guesses: "+str(attempts))
	def make_multiplication_table():
		n=int(input("How many rows of a multiplication table would you like to see? (1-13): "))
		x=n
		for n in range(x):
			table=[[0,0,0,0,0,0,0,0,0,0,0,0],
			[0,1,2,3,4,5,6,7,8,9,10,11,12],
      			[0,2,4,6,8,10,12,14,16,18,20,22,24],
			[0,3,6,9,12,15,18,21,24,27,30,33,36],
			[0,4,8,12,16,20,24,28,32,36,40,44,48],
			[0,5,10,15,20,25,30,35,40,45,50,55,60],
			[0,6,12,18,24,30,36,42,48,54,60,66,72],
			[0,7,14,21,28,35,42,49,56,63,70,77,84],
			[0,8,16,24,32,40,48,56,64,72,80,88,96],
			[0,9,18,27,36,45,54,63,72,81,90,99,108],
			[0,10,20,30,40,50,60,70,80,90,100,110,120],
			[0,11,22,33,44,55,66,77,88,99,110,121,132],
			[0,12,24,36,48,60,72,84,96,108,120,132,144]]
			m_table=str(table[n])
			n_table=str(m_table.strip('[]'))
			print(n_table)
		x=x+1
	make_multiplication_table()
main()
