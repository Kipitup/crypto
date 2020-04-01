from os import listdir
from os.path import isfile, join
from os import walk
import os

os.system("make")

def execute(msg, key):
    command_line = "./crypto \"" + msg + "\" \"" + key + "\""
    print(command_line)
    answer = os.system(command_line)
    return answer

def diff(file_1, file_2):
    command_line = "diff " + file_1 + " " + file_2
    print(command_line)
    answer = os.system(command_line)
    print(answer)
    answer = os.system(command_line + " | wc -l")
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
            list_of_files.append(path + file)
    return list_of_files


directory = "./test/"
path_to_tests = directory + "unit_test/"
path_to_crypt = directory + "CRYPT/"
path_to_uncrypt = directory + "UNCRYPT/"


def test_me(dir, file_1, file_2):
    res = execute(dir + file_1, dir + file_2)
    #write_file



if __name__ == "__main__":
    list_of_tests = get_list_of_files(path_to_tests)
    for test in list_of_tests:
        res = execute(read_file(test), "test")
        print(res)


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



