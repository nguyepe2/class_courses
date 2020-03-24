try:
  a=int(input("Input a positive number that is less than 256: "))
  b=bin(a)
  print(b)
except ValueError:
  print("Error: The input is not a whole number. Please input a whole number this time")
