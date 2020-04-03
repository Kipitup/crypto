from os import listdir
from os.path import isfile, join
from os import walk
import os
import random


def execute(msg, key, dest, cycles, crypt):
    if crypt:
        command_line = "./crypto " + msg + " " + key + " " + str(cycles) + " CRYPT" + " 1>" + dest
    else:
        command_line = "./crypto " + msg + " " + key + " " + str(cycles) + " UNCRYPT" + " 1>" + dest
    print("COMMAND: ", command_line)
    answer = os.system(command_line)
    return answer

def diff(file_1, file_2, on):
    command_line = "diff -a " + file_1 + " " + file_2
    print("COMMAND: ", command_line)
    print("DIIF IS:")
    if not on:
        answer = os.system(command_line)
    else:
        answer = os.system(command_line + " | wc -c")
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

def get_list_of_files(path):
    list_of_files = []
    for (dirpath, dirnames, filenames) in walk(path):
        for file in filenames:
            list_of_files.append(file)
    return list_of_files


directory = "./test/"
path_to_tests = directory + "unit_test/"
path_to_crypt = directory + "crypted/"
path_to_uncrypt = directory + "uncrypted/"


def test_me(file_1, file_2):
    cycles = 50
    file_3 = file_1 + "_" + file_2
    #Crypt
    res = execute(path_to_tests + file_1, path_to_tests + file_2, path_to_crypt + file_3, cycles, 1)
    diff(path_to_tests + file_1, path_to_crypt + file_3, 1)
    
    #Uncrypt
    res = execute(path_to_crypt + file_3, path_to_tests + file_2, path_to_uncrypt + file_3, cycles, 0)
    diff(path_to_tests + file_1, path_to_uncrypt + file_3, 0)



if __name__ == "__main__":
    os.system("make")
    os.system("rm -rf " + directory + path_to_crypt)
    os.system("mkdir -p " + directory + path_to_crypt)
    os.system("rm -rf " + directory + path_to_uncrypt)
    os.system("mkdir -p " + directory + path_to_uncrypt)
    list_of_tests = get_list_of_files(path_to_tests)
    for i in range(1):
        uno = random.randint(0, len(list_of_tests) - 1)
        dos = random.randint(0, len(list_of_tests) - 1)
        test_me(list_of_tests[uno], list_of_tests[dos])


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




