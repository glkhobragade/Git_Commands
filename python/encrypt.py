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

