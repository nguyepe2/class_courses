#Definition: keeps track of score
#prectondition: none
#postcondition: none
#return: number of wins
def main():
	win1=0
	win2=0
	tie=0
#Definition: game starts the program
#precondition: Players much choose a character for their piece
#postconditions: none
#Return: Prompts for inputs and  score count
	def game():
		run=True
		while run:
			piece1=input("What character do you want?: ")
			piece2=input("What character do you want?: ")
			if piece2==piece1:
				print("Piece1 is the same as piece2. Please select another character for piece2")
				piece2=input("What character do you want?: ")
			board= ['','','',
				'','','',
				'','','']
#Definition: prints the tic tac toe board
#precondition: a board exists
#postcondition: none
#Return: updated board
			def show():
				print(board[0], '|',board[1], '|',board[2])
				print("-------")	
				print(board[3], '|',board[4], '|',board[5])
				print("-------")
				print(board[6], '|',board[7], '|',board[8])
				print("-------")
			show()
			while True:
				location1=int(input("Where would you like to put your "+piece1+"(0-8 from left to right and top to bottom)?: "))
				if location1 <0 or location1 >8:
					print("That spot doesn't exist on the board")
					location1=int(input("Where yould you like to put your "+piece1+"?: "))
					board[location1]=piece1
				elif board[location1] !=piece1 and board[location1] !=piece2:
					board[location1]=piece1
				else:
					print("That spot is taken")
					location1=int(input("Where yould you like to put your "+piece1+"?: "))
					board[location1]=piece1
			
				if piece1==board[0] and piece1==board[1] and piece1==board[2] or piece1==board[3] and piece1==board[4] and piece1==board[5] or piece1==board[6] and piece1==board[7] and piece1==board[8] or piece1==board[0] and piece1==board[3] and piece1==board[6] or piece1==board[1] and piece1==board[4] and piece1==board[7] or piece1==board[2] and piece1==board[5] and piece1==board[8] or piece1==board[0] and piece1==board[4] and piece1==board[8] or piece1==board[2] and piece1==board[4] and piece1==board[6]:
					show()
					print("Player 1 won!")
					return 1
				if '' not in board:
					print("It's a tie")
					return 3
					show()
				show()
				location2=int(input("Where would you like to put your "+piece2+"?: "))
				if location2 <0 or location2 >8:
					print("That spot doesn't exist on the board")
					location2=int(input("Where yould you like to put your "+piece2+"?: "))
					board[location2]=piece2
				elif board[location2] !=piece2 and board[location2] !=piece1:
					board[location2]=piece2
				else:
					print("That spot is taken")
					location2=int(input("Where would you like to put your "+piece2+"?: "))
					board[location2]=piece2

				if piece2==board[0] and piece2==board[1] and piece2==board[2] or piece2==board[3] and piece2==board[4] and piece2==board[5] or piece2==board[6] and piece2==board[7] and piece2==board[8] or piece2==board[0] and piece2==board[3] and piece2==board[6] or piece2==board[1] and piece2==board[4] and piece2==board[7] or piece2==board[2] and piece2==board[5] and piece2==board[8] or piece2==board[0] and piece2==board[4] and piece2==board[8] or piece2==board[2] and piece2==board[4] and piece2==board[6]:
					show()
					print("Player 2 won!")
					return 2
				show()
	rematch="y"
	while rematch=="y":
		game_count=game()
		if game_count==1:
			win1 += 1
		elif game_count==2:
			win2 += 1
		elif game_count==3:
			tie += 1
		rematch=input("Would you like to play again? (y/n): ")
	print("Player 1 wins: "+str(win1))
	print("Player 2 wins: "+str(win2))
	print("Ties: "+str(tie))
		
main()
