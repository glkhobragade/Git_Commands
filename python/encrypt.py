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
round = 16;
last_byte = 0
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
    c_ = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"+ chr(i)+chr(last_byte^02)
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
        print(int(IV[15].encode('hex'), 16))
        last_byte = int(plain_[31].encode('hex'), 16)^i^int(IV[14].encode('hex'), 16)
        list_I[round]=i^02
        round-=1
        print ("last byte = ", last_byte)
        break

print("Hello")

list_I.append(last_byte)
