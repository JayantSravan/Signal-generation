import matplotlib.pyplot as plt
#file = open("data.txt", "r")
with open("smooth.txt", "r") as f:
	data= f.readlines()

#n = data[0]
data = data[1:]
#print n
plt.plot(data)
plt.ylabel('count')
plt.xlabel('time')	
#plt.draw()

plt.show()
