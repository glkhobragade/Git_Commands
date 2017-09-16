from __future__ import print_function

genre = ['pop', 'rock', 'jazz']
# iterate over the list using index
for i in range(len(genre)):
        print("I like", genre[i])


pad = ""
for i in range(15):
    pad += (str(hex(i)))

print (pad)


list_iv = []
list_iv.append(7)
list_iv.append(8)
list_iv.append(9)

print(list_iv)

print(hex(111))
print(hex(111^02))
print(chr(111^02))

print("good", chr(0x9e))

print ("0 = ",chr(0))
p = ""
p += chr(0)
p += chr(0)
p += chr(0)
p += chr(0)

print ("p =", p)


#pm = raw_input()
#print (pm)




def squares(n):
    global p
    p = n*n;

p=0
squares(10)
print(p)


str = "Hello World !!"
for char in str:
    mm = int(char.encode('hex'), 16)
    print(hex(mm), sep=':', end=' ' )
