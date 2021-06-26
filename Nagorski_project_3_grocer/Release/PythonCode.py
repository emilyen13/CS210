import re
import string


def ListQuantity():
    text = open("U:/Nagorski_project_3_grocer/Release/grocerstats.txt", "r") #accesses file location
    d = dict()
        
    for line in text:
        # Remove the leading spaces and newline character
        line = line.strip()
        # Convert the characters in line to 
        # lowercase to avoid case mismatch
        line = line.lower()
        # Split the line into words
        words = line.split(" ")
        # Iterate over each word in line
        for word in words:
        # Check if the word is already in dictionary
            if word in d:
        # Increment count of word by 1
                d[word] = d[word] + 1
            else:
        # Add the word to dictionary with count 1
                d[word] = 1
    return d  
     
def ItemCount():
    count = ListQuantity()
    f = open("frequency.dat", "w")
    # Print the contents of dictionary
    for key in list(count.keys()):
        f.write(key)
        f.write(" ")
        f.write(str(count[key]))
        f.write('\n')
        print(key, ":", count[key])
    f.close()
    

def ItemFrequency(userItem):
    count = ListQuantity() #calls ListQuantity def to avoid code redundancy 
    total = count.get(userItem) #locates specifc user inputted item
    print("Number of", userItem, "purchased today:", total) #print item and its quantity
    
    
#this is how I originally had my histogram being displayed until I realized we needed to read a txt file in C++ to do it, I decided to leave it in because I still feel its a better way than doing it in C++ 
def ItemHistogram(): 
    count = ListQuantity() #calls ListQuantity def to avoid code redundancy
    for key in list(count.keys()): #locates number of each item in dictionary 
        print(key, ":", "*" * count[key]) #prints * number of times that item was purchased 
    





    
