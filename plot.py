import numpy as np
import matplotlib.pyplot as plt

t=np.arange(0.,5.,0.2)

f=open('out','r')

v1=list()
v2=list()
v3=list()

for x in f:
	a,b,c=map(int,x.split())
	v1.append(a)
	v2.append(b)
	v3.append(c)


#plt.plot(t,t,t,t**2,t,t**3)
#plt.show()

#plt.plot(range(len(v1)),v1,'r',range(len(v2)),v2,'g',range(len(v3)),v3,'b');
plt.plot(range(len(v1)),v1,'r',range(len(v2)),v2,'g');
plt.show()
