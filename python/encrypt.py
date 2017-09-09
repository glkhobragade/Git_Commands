from Crypto.Cipher import AES
import sys
from Crypto import Random
import base64

KEY = "\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B"

def AES_padding(p, v, n):
    obj = AES.new(KEY, AES.MODE_CBC, v)

    print("##The input string is: ", p)
    ptext_len = len(p)
    print ('message length= ',ptext_len)
    pad_lenth = (16 - (ptext_len%16))
    print ("Bytes of padding needs to be added is :", pad_lenth)


    ##  ============== padding done ==================
    padding = ""
    for i in range(pad_lenth):
        #padding += ("\\0x"+str(pad_lenth))
        padding += (chr(pad_lenth))


    print("pad length= ", len(padding))
    print("## padding string is =", padding)


    p += padding

    ##  ============== Encryption done ==================
    global ciphertext
    ciphertext = obj.encrypt(p)
    print ("##ciphertext C is =", ciphertext)

    no_of_blocks= len(ciphertext)/16
    print ("ciphertext blocks  =", len(ciphertext)/16)



def AES_valid_padding(c, v, b):
    isValid = False
    print ("##ciphertext C is =", c)
    ##  ============== Decrpytion done ==================

    obj2 = AES.new(KEY, AES.MODE_CBC, v)
    plain = obj2.decrypt(c)
    print ("decrypted plain text is:", plain)


    ##  ============== Padding Removed ==================
    last = plain[len(plain)-1]
    #p = (len(plain)-int(last, 16));
    p= int(last.encode('hex'), 16)
    print ("p=", p)
    print ("last byte of paintext = ", last)
    print ("text after padding removed", plain[:len(plain)-p])

    for i in range(p):
        x = plain[(16*b)-i-1]
        if int(x.encode('hex'), 16) != p:
            return False
    return True




ciphertext = ""
IV =  "\x11\x22\x33\x44\x55\x66\x77\x88\x99\xAA\xBB\xCC\xDD\xEE\xFF\x00"
message = raw_input('Please Enter the plain text here:')
msg_len = len(message)
AES_padding(message, IV, msg_len)
result = AES_valid_padding(ciphertext, IV, len(ciphertext)/16)
if result:
    print("It is valid PKCS padding")
else:
    print("It is not a valid PKCS padding")


'''
print ("ciphertext length=", len(ciphertext))

list_I = ['\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00']
round = 1;
list_p = []
last_byte = 0
pos = 0
C0 = IV
comp_plain = ""

## Third round
for block in range(no_of_blocks):
    print ("I am in block number: ", block)
    temp = ciphertext[pos:pos+16]
    print("temp var=", temp)

    for j in range(16):
        print ("I am in round number: ", (j+1))
        c_prefix = ""
        c_posfix = ""

        for k in range(15-j):
            c_prefix += chr(0)

        for m in range(j):
            c_posfix += chr(list_I[16-j+m]^(j+1))

        pos=0
        for i in range(256):
            c_ = c_prefix + chr(i) + c_posfix
            #print("our c_ block is", c_)
            #print("the length is = ", len(c_))
            cipher_ = c_ + temp
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
                last_byte = int(plain_[31].encode('hex'), 16)^i^int(C0[15-j].encode('hex'), 16)
                list_I[15-j] = i^(j+1)
                round-=1
                print ("last byte = ", last_byte)
                list_p.append(chr(last_byte))
                break
    plain_text_computed = list_p[::-1]
    plain_text_computed_ = "".join(plain_text_computed)
    comp_plain += plain_text_computed_
    list_p = []
    C0 = temp
    pos +=16


print ("done and broken plain text is ", comp_plain)
'''
