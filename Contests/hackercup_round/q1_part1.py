import sys, os
ct_nspam = {}
ct_spam = {}
for x in os.listdir("./bare/part1/"):
    with open("./bare/part1" + x, "r") as file:
        for line in file.readlines():
            word_list = line.split()
            for words in word_list :
                if x[0:3] == "spm":
                    ct_spam[word] += 1
                else:
                    ct_nspam[word] += 1;
for i, j in ct_spam.items():
    print i, j
for i, j in ct_nspam.items():
    print i, j
                        
                
        