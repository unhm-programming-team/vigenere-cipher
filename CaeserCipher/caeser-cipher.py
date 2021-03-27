#Karl Miller
#CSC-125-WB
#Project 1 - Caeser Cypher 

def getProgramCommand():
    cmd = ''
    while(cmd != 'q'):
        cmd = input("Enter command. Valid inputs are e, d, and q. >> ")
        if(cmd == 'e'):
            encode()
        elif(cmd == 'd'):
            decode()

def encode():
    encodeString = ''
    while(len(encodeString) <= 0):
            encodeString = input("Enter a string to encode: ")
    encodeRotation = -1
    while(encodeRotation >= 25 or encodeRotation < 1):
            encodeRotation = input("Enter a rotation: ")
            while(not str.isdigit(encodeRotation)):
                print("Not a number.")
                encodeRotation = input("Enter a rotation: ")
            encodeRotation = int(encodeRotation)
            if(encodeRotation >= 25):
                print("Rotation must be less than 25.")
            if(encodeRotation < 1):
                print("Rotation must 1 or greater.")
    print('~---> rotate', encodeRotation, ': ', rotate(encodeRotation, encodeString))
    
def rotate(n, s):
    new = ''
    for c in range(0, len(s)):
        if(s[c].islower()):
            new = new + chr((ord(s[c]) - 97 + n)%25+97)
        else:
            new = new + s[c]
    return new

def decode():
    decodeString = False
    while(decodeString == False):
        decodeString = input("Enter string to be decoded: ")
        if(len(decodeString)<2):
            print("String must be at least two characters to be cracked.")
            decodeString = False;
    decodeWord = False
    while(decodeWord == False):
        decodeWord = input("Enter a known word in the encrypted string: ")
        if(len(decodeWord)<2):
            print("Word must be at least two characters to be cracked.")
            decodeWord = False;
    possibleMatches = []
    for i in range(0, 25):
        testStr = rotate(i, decodeString)
        if(decodeWord in testStr):
            possibleMatches.append( (i,testStr) )
    print('Found', len(possibleMatches),'possible matche(s)')
    for m in possibleMatches:
        print('\tRotation =', 25-m[0],"\tResult =",m[1])
        

#main program loop
print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
print("~Caeser Cipher by Karl Miller~");
print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
getProgramCommand()
print("Goodbye.")