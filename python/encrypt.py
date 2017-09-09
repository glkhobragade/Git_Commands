from Crypto.Cipher import AES
import sys
from Crypto import Random
import base64

IV =  "\x11\x22\x33\x44\x55\x66\x77\x88\x99\xAA\xBB\xCC\xDD\xEE\xFF\x00"
KEY = "\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B"

print (AES.key_size[0])
print (AES.block_size)

obj = AES.new(KEY, AES.MODE_CBC, IV)
message = "The answer is no where pres"
msg_len = len(message)

print ('message length= ', msg_len)
pad_lenth = (16 - (msg_len%16))
print ("Bytes of padding needs to be added is :", pad_lenth)

##  ============== padding done ==================
padding = ""
for i in range(pad_lenth):
    #padding += ("\\0x"+str(pad_lenth))
    padding += (chr(pad_lenth))


print("pad length= ", len(padding))
print("padding is =", padding)
message += padding

##  ============== Encryption done ==================

ciphertext = obj.encrypt(message)
#sys.stdout.write(ciphertext)
print ("ciphertext is =", ciphertext)


##  ============== Decrpytion done ==================

obj2 = AES.new(KEY, AES.MODE_CBC, IV)
plain = obj2.decrypt(ciphertext)
print ("\n")
print ("plain text is:", plain)


##  ============== Padding Removed ==================
last = plain[len(plain)-1]
#p = (len(plain)-int(last, 16));
p= int(last.encode('hex'), 16)
print ("last byte of paintext = ", last)
print ("text after padding removed", plain[:len(plain)-p])


print ("ciphertext length=", len(ciphertext))

list_I = ['\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00']
round = 1;
list_p = []
last_byte = 0

'''
for i in range(256):
    c_ = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"+ chr(i)
    #print("our c_ block is", c_)
    print("\n")
    cipher_ = c_ + ciphertext[:16]
    print("manipulated ciphertext is: ", cipher_)
    print("length= ", len(cipher_))
    plain_ = obj2.decrypt(cipher_)
    print("new decrypted text is =", plain_)
    print("new decrypted text length is =", len(plain_))

    if plain_[31] == '\x01':
        print ("I got the corresponding plaintext")
        #last_byte = plain_[31]^chr(i)^IV[0]
        print(int(plain_[31].encode('hex')))
        print(i)
        print(int(IV[15].encode('hex'), 16))
        last_byte = int(plain_[31].encode('hex'), 16)^i^int(IV[15].encode('hex'), 16)
        list_I[15]= i^01
        round-=1
        print ("last byte = ", last_byte)
        break

print ("last plain byte = ", chr(last_byte))
print ("16th byte of actual plain text", plain[15])


## Second round

for i in range(256):
    c_ = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"+ chr(i)+chr(list_I[15]^02)
    print("our c_ block is", c_)
    print("the length is = ", len(c_))
    print("\n")
    cipher_ = c_ + ciphertext[:16]
    print("manipulated ciphertext is: ", cipher_)
    print("length= ", len(cipher_))
    plain_ = obj2.decrypt(cipher_)
    print("new decrypted text is =", plain_)
    print("new decrypted text length is =", len(plain_))

    if plain_[30] == '\x02':
        print ("I got the corresponding plaintext")
        #last_byte = plain_[31]^chr(i)^IV[0]
        print(int(plain_[31].encode('hex')))
        print(i)
        print(int(IV[14].encode('hex'), 16))
        last_byte = int(plain_[31].encode('hex'), 16)^i^int(IV[14].encode('hex'), 16)
        list_I[14]=i^02
        round-=1
        print ("last byte = ", last_byte)
        break

'''

## Third round
for j in range(16):
    print ("I am in round number: ", (j+1))
    c_prefix = ""
    c_posfix = ""

    for k in range(15-j):
        c_prefix += chr(0)

    for m in range(j):
        c_posfix += chr(list_I[16-j+m]^(j+1))

    for i in range(256):
        c_ = c_prefix + chr(i) + c_posfix
        #c_ = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"+ chr(i)+chr(list_I[14]^03)+chr(list_I[15]^03)
        #print("our c_ block is", c_)
        #print("the length is = ", len(c_))
        #print("\n")
        cipher_ = c_ + ciphertext[:16]
        #print("manipulated ciphertext is: ", cipher_)
        #print("length= ", len(cipher_))
        plain_ = obj2.decrypt(cipher_)
        #print("new decrypted text is =", plain_)
        #print("new decrypted text length is =", len(plain_))

        if plain_[32-j-1] == chr(j+1):
            print ("I got the corresponding plaintext")
            #last_byte = plain_[31]^chr(i)^IV[0]
            #print ("plain 31= ", plain_[31])
            #print(int(plain_[31].encode('hex')))
            #print(i)
            #print(int(IV[15-j].encode('hex'), 16))
            last_byte = int(plain_[31].encode('hex'), 16)^i^int(IV[15-j].encode('hex'), 16)
            list_I[15-j] = i^(j+1)
            round-=1
            print ("last byte = ", last_byte)
            list_p.append(chr(last_byte))
            break


'''
## Fourth round

for i in range(256):
    c_ = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"+ chr(i)+chr(list_I[13]^04)+chr(list_I[14]^04)+chr(list_I[15]^04)
    print("our c_ block is", c_)
    print("the length is = ", len(c_))
    print("\n")
    cipher_ = c_ + ciphertext[:16]
    print("manipulated ciphertext is: ", cipher_)
    print("length= ", len(cipher_))
    plain_ = obj2.decrypt(cipher_)
    print("new decrypted text is =", plain_)
    print("new decrypted text length is =", len(plain_))

    if plain_[28] == '\x04':
        print ("I got the corresponding plaintext")
        #last_byte = plain_[31]^chr(i)^IV[0]
        print(int(plain_[31].encode('hex')))
        print(i)
        print(int(IV[12].encode('hex'), 16))
        last_byte = int(plain_[31].encode('hex'), 16)^i^int(IV[12].encode('hex'), 16)
        list_I[12]=i^04
        round-=1
        print ("last byte = ", last_byte)
        break

'''
print ("done and plain text found in reverse order is ", list_p)
