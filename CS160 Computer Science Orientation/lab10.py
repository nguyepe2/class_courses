import sys
def main(argv):
	filename=argv[1]
	f=open(filename,'r+')
	line=list(map(int, f.readline().strip().split(',')))
	print(line)
	large=max(line)
	num=line.append(large)
	f.write(str(large))
	print(line)
main(sys.argv)
