import magic
import os
import shutil


key = 0b00101101
otherKey = 45

def scramble(toRead):
    folderPath = os.path.dirname(__file__)
    toRead = os.path.join(folderPath, toRead)
    toWrite = os.path.join(folderPath, 'temp')
    with open(toRead, 'rb') as fin, open(toWrite, 'wb') as fout:
        byte = fin.read(1)
        while byte != b"":
            otherByte = ord(byte)^key
            fout.write(bytes([otherByte]))
            byte = fin.read(1)
    os.remove(toRead)
    os.rename(toWrite, toRead)

def unscramble(toRead):
    folderPath = os.path.dirname(__file__)
    toRead = os.path.join(folderPath, toRead)
    outputFolder = os.path.join(folderPath, 'outputFolder/')
    # shutil.rmtree(outputFolder)
    if not os.path.exists(outputFolder):
        os.mkdir(outputFolder)
    toWrite = os.path.join(folderPath, 'temp')
    toWriteTemp = os.path.join(folderPath, 'tempTwo')
    startMimeType = magic.from_file(toRead, mime=True)
    shouldContinue = False
    #I create two files, write only 2048 bytes into one of them, then close the stream and check
    #the file's mime type with "magic" documentation
    for x in range(256):
        with open(toRead, 'rb') as fin, open(toWrite, 'wb') as fout:
            shouldwritetocheckfile = True
            foutTwo = open(toWriteTemp, 'wb')
            bytesRead = 1
            byte = fin.read(1)
            while byte != b"" and not shouldContinue:
                otherByte = ord(byte) ^ x
                fout.write(bytes([otherByte]))
                if shouldwritetocheckfile:
                    foutTwo.write(bytes([otherByte]))
                byte = fin.read(1)
                bytesRead += 1
                #documentation for this library says it's better if we check at least 2kB
                if bytesRead == 2048:
                    shouldwritetocheckfile = False
                    foutTwo.close()
                    if magic.from_file(toWriteTemp, mime=True) == startMimeType:
                        os.remove(toWrite)
                        shouldContinue = True

        if not shouldContinue :
            shutil.copyfile(toWrite, outputFolder + 'file' + str(x))
            print('possible key is: ' + str(x))
        shouldContinue = False



def startProgram():
    scrambleOrNot = input("Would you like to scramble or unscramble a file?(scramble or unscramble)")
    if scrambleOrNot == 'scramble':
        filePath = input("please type name of the file(in current directory): ")
        scramble(filePath)
    elif scrambleOrNot == 'unscramble':
        filePath = input("please type name of the file(in current directory): ")
        unscramble(filePath)
    elif scrambleOrNot == 'skip':
        pass
    else:
        print('invalid input')
        startProgram()

startProgram()





