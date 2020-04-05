from os import listdir
from os.path import isfile, join
from os import walk
import os
import time
import random
from color import *
import shutil

def execute(msg, key, dest, cycles, crypt):
    if crypt:
        command_line = "./crypto " + msg + " " + key + " " + str(cycles) + " CRYPT" + " 1>" + dest
    else:
        command_line = "./crypto " + msg + " " + key + " " + str(cycles) + " UNCRYPT" + " 1>" + dest
    print(command_line)
    answer = os.system(command_line)
    return answer

def diff(file_1, file_2, on):
    columns = shutil.get_terminal_size().columns
    columns = columns - (columns // 5)
    if on:
        command_line = "diff -ay --width=" + str(columns) + " --color=always --suppress-common-lines " + file_1 + " " + file_2
    else:
        command_line = "diff -ay --width=" + str(columns) + " --color=always " + file_1 + " " + file_2
    print(command_line)
    print(RED, "\n", "~" * columns, RESET)
    #print("DIIF IS:")
    answer = os.system(command_line)
    print(RED, "\n", "~" * columns, RESET)
    return answer

def read_file(path):
    file=open(path, "r")
    if file.mode == 'r':
        content = file.read()
    file.close()
    return content

def write_file(path, content):
    file=open(path, "w+")
    file.write(content)
    file.close()



directory = "./test/"
path_to_tests = directory + "unit_test/"
path_to_crypt = directory + "crypted/"
path_to_uncrypt = directory + "uncrypted/"



class Testor():
    def __init__(self):
        self.max_len = -1
        self.get_list_of_files()

    def new_test(self):
        self.select_msg_and_key()
        self.cycles = random.randint(0, 500)
        self.file_3 = self.file_1 + "_" + self.file_2
        self.msg = path_to_tests + self.file_1
        self.key = path_to_tests + self.file_2
        self.cypher = path_to_crypt + self.file_3
        self.uncrypted = path_to_uncrypt + self.file_3

    def select_msg_and_key(self):
        self.file_1 = self.list_of_files[random.randint(0, len(self.list_of_files) - 1)]
        self.file_2 = self.list_of_files[random.randint(0, len(self.list_of_files) - 1)]

    def get_list_of_files(self):
        self.list_of_files = []
        for (dirpath, dirnames, filenames) in walk(path_to_tests):
            for file in filenames:
                if self.max_len < len(file):
                    self.max_len = len(file)
                self.list_of_files.append(file)
        self.max_len = (self.max_len * 2) + 1 + len(path_to_uncrypt)

    def test_me(self):
        #Crypt
        self.display(1)
        start = time.time()
        res = execute(self.msg, self.key, self.cypher, self.cycles, 1)
        time_took = time.time() - start
        diff(self.msg, self.cypher, 0)
        print(PURPLE, "\n Time to crypt    ", str(time_took)[0:5])
        print(          " Time for a cycle ", str((time_took) / self.cycles)[0:7], RESET)
        print("Need more details ? Feel free to copy next line")
        print("cat -e ", self.msg, " && ", "cat -e ", self.cypher)
        print("\n\n\n")
    
        #Uncrypt
        self.display(0)
        start = time.time()
        res = execute(self.cypher, self.key, self.uncrypted, self.cycles, 0)
        time_took = time.time() - start
        diff(self.msg, self.uncrypted, 0)
        print(PURPLE, "\n Time to uncrypt  ", str(time_took)[0:5])
        print(          " Time for a cycle ", str((time_took) / self.cycles)[0:7], RESET)
        print("Need more details ? Feel free to copy next line")
        print("cat -e ", self.msg, " && ", "cat -e ", self.uncrypted)
        print("\n\n\n")


    def display(self, crypt = 1):
        columns = shutil.get_terminal_size().columns
        n = columns // 4
        if crypt:
            print(PURPLE, ("=" * n) + " " * 5 + "CRYPT" + " " * 5 + ("=" * n))
            print(RED,    "Message ", self.msg)
            print(YELLOW, "Key     ", self.key)
            print(BLUE,   "Cycles    ", self.cycles)
            print(GREEN,  "to file ", self.cypher, RESET)
        else:
            print(PURPLE, ("=" * (n - 1))  + " " * 5 + "UNCRYPT"  + " " * 5 + ("=" * (n - 1)))
            print(RED,    "Message ", self.cypher)
            print(YELLOW, "Key     ", self.key)
            print(BLUE,   "Cycles    ", self.cycles)
            print(GREEN,  "to file ", self.uncrypted, RESET)
        print("")

def reset_folders():
    os.system("rm -rf " + path_to_crypt)
    os.system("mkdir -p " + path_to_crypt)
    print("Cypher    folder has been reset !")
    os.system("rm -rf " + path_to_uncrypt)
    os.system("mkdir -p " + path_to_uncrypt)
    print("Uncrypted folder has been reset !")
    os.system("make")


if __name__ == "__main__":
    reset_folders()
    testor = Testor()
    for i in range(1):
        testor.new_test()
        testor.test_me()


#get directory
#for each file
    #crypt it // check if different
    #uncrypt it // check if identical


#test
    #varier:
        #cycles -> rand
        #msg -> dossier
        #key -> 
    #tests:
        #original == uncrypted
            #faire un diff 
        #original != crypted
            #show un diff
            #check each character ?




