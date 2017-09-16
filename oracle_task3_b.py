from __future__ import print_function
from Crypto.Cipher import AES
import sys
from Crypto import Random
import base64

IV =  "\x11\x22\x33\x44\x55\x66\x77\x88\x99\xAA\xBB\xCC\xDD\xEE\xFF\x00"
KEY = "\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B\x6B"

# =========================== Oracle Attack Starts ========================================
def ATT(c, v):
    list_I = ['\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00','\0x00']
    round = 1;
    list_p = []
    last_byte = 0
    pos = 0
    C0 = v
    comp_plain = ""


	## We have to break the cihhertext, block by block and each block is of 16 byte.

    for block in range(no_of_blocks):
        #print ("I am in block number: ", block)
        temp = c[pos:pos+16]
        #print("temp var=", temp)

        for j in range(16):
            #print ("I am in round number: ", (j+1))
            c_prefix = ""
            c_posfix = ""

            for k in range(15-j):
                c_prefix += chr(0) 	        ## for each round, the dynamic prefix of 0's will be created.

            for m in range(j):
                c_posfix += chr(list_I[16-j+m]^(j+1))

            pos=0
            for i in range(256):							## This loop for changing 1 byte change, to get the corresponding plain text.
                c_ = c_prefix + chr(i) + c_posfix   		## the manipulated ciphertext created for oracle attack.

                #print("our c_ block is", c_)
                #print("the length is = ", len(c_))
                cipher_ = c_ + temp
                #print("manipulated ciphertext is: ", cipher_)
                #print("length= ", len(cipher_))
                plain_ = obj2.decrypt(cipher_)
                #print("new decrypted text is =", plain_)
                #print("new decrypted text length is =", len(plain_))

                if plain_[32-j-1] == chr(j+1):
                    #print ("I got the corresponding plaintext")
                    #last_byte = plain_[31]^chr(i)^IV[0]
                    #print ("plain 31= ", plain_[31])
                    #print(int(plain_[31].encode('hex')))
                    #print(i)
                    #print(int(IV[15-j].encode('hex'), 16))
                    last_byte = int(plain_[31].encode('hex'), 16)^i^int(C0[15-j].encode('hex'), 16)
                    list_I[15-j] = i^(j+1)
                    round-=1
                    #print ("last byte = ", last_byte)
                    list_p.append(chr(last_byte))				## decrypting 1 byte at a time from right to left
                    break
        plain_text_computed = list_p[::-1] 						# reversing the complete block of broken plaintext
        plain_text_computed_ = "".join(plain_text_computed)		# storing list of broken plaintext char into string
        comp_plain += plain_text_computed_						# appending complete 1 block of broken plaintext computed into global string to show complete output.
        list_p = []
        C0 = temp
        pos +=16


    last = comp_plain[len(comp_plain)-1]
    p= int(last.encode('hex'), 16)
    return comp_plain[:len(comp_plain)-p]

# ============= Function AES_Padding ============================

def AES_Padding(p, n, v):
    pad_lenth = (16 - (n%16))
    print ("Bytes of padding needs to be added is :", pad_lenth)


    padding = ""
    for i in range(pad_lenth):
	padding += (chr(pad_lenth))

    print("pad length= ", len(padding))
    print("## padding string is =", padding)


    p += padding

    ciphertext = obj.encrypt(p)
    print ("##ciphertext C is = ", sep=' ', end=' ')
    for char in ciphertext:
        mm = int(char.encode('hex'), 16)
        print(hex(mm), sep=' ', end=' ' )

    return ciphertext






# ================= Program starts Here =========================

obj = AES.new(KEY, AES.MODE_CBC, IV)    ## Initialise the encryption object.
obj2 = AES.new(KEY, AES.MODE_CBC, IV)	## Initialise the decryption object.
message = raw_input('Please Enter the plain text here:')
msg_len = len(message)
print ("length of plain text is == ", msg_len)
ciphertext = AES_Padding(message, msg_len, IV)
no_of_blocks= len(ciphertext)/16
print ("number of ciphertext blocks  =", len(ciphertext)/16)


## ============ start the oracle attack =======================
pt_broken = ATT(ciphertext, IV)
print ("done and broken plain text is ", pt_broken)
