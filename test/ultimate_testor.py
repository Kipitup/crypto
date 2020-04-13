from os import listdir
from os.path import isfile, join
from os import walk
import os
import time
import random
from color import *
import shutil

def execute(msg, key, dest, cycles, crypt=True):
    start = time.time()
    if crypt:
        command_line = "./crypto " + msg + " " + key + " " + str(cycles) + " CRYPT" + " 1>" + dest
    else:
        command_line = "./crypto " + msg + " " + key + " " + str(cycles) + " DECRYPT" + " 1>" + dest
    os.system(command_line)
    time_took = time.time() - start
    return time_took, command_line

def diff(file_key, file_msg, on):
    temp_file = "./test/tmp_diff"
    columns = shutil.get_terminal_size().columns
    columns = columns - (columns // 5)
    if on:
        temp_file = "./test/tmp_diff"
        command_line = "diff -a --suppress-common-lines " + file_key + " " + file_msg + " >" + temp_file
        os.system(command_line)
        return len(read_file(temp_file))
    else:
        command_line = "diff -ay --width=" + str(columns) + " --color=always " + file_key + " " + file_msg
    print(command_line)
    print(RED, "\n", "~" * columns, RESET)
    #print("DIIF IS:")
    answer = os.system(command_line)
    print(RED, "\n", "~" * columns, RESET)
    return answer

def read_file(path):
    file=open(path, "rb")
    if file.mode == 'rb':
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
        self.select = "ALL_COMBINAISONS"
        self.get_list_of_files()
        self.tests_to_do = (len(self.list_of_files) * len(self.list_of_files)) - 1 

    def make_file_path(self, add_folders=True):
        if add_folders:
            self.file_crypto = self.file_msg + "_" + self.file_key
            self.msg = path_to_tests + self.file_msg
            self.key = path_to_tests + self.file_key
            self.cypher = path_to_crypt + self.file_crypto
            self.uncrypted = path_to_uncrypt + self.file_crypto
        else:
            self.file_crypto = self.file_msg + "_" + self.file_key
            self.msg = self.file_msg
            self.key = self.file_key
            self.cypher = self.file_crypto
            self.uncrypted = self.file_crypto

    def new_test(self):
        self.select_msg_and_key()
        self.cycles = random.randint(0, 300)

    def next_file_combinaison(self):
        self.file_msg = self.list_of_files[self.tests_to_do // len(self.list_of_files)]
        self.file_key = self.list_of_files[self.tests_to_do % len(self.list_of_files)]
        
    def select_msg_and_key(self):
        if self.select == "ALL_COMBINAISONS":
            self.next_file_combinaison()
            self.make_file_path(add_folders=True)
        elif self.select == "RANDOM":
            len_rand = len(self.list_of_files) - 1
            choice = lambda x : random.randint(0, x)
            self.file_key = self.list_of_files[choice(len_rand)]
            self.file_msg = self.list_of_files[choice(len_rand)]
            self.make_file_path(add_folders=True)
        elif self.select == "USER_FILES":
            self.msg = "msg"
            self.key = "key"
            self.make_file_path(add_folders=False)

    def get_list_of_files(self):
        self.list_of_files = []
        for (dirpath, dirnames, filenames) in walk(path_to_tests):
            for file in filenames:
                if self.max_len < len(file):
                    self.max_len = len(file)
                self.list_of_files.append(file)
        self.max_len = (self.max_len * 2) + 1 + len(path_to_uncrypt)

    def similarity_test(self, file_1, file_2):
        temp_file = "./test/tmp_diff"
        grep_out = " | grep -av \"\\ No newline at end of file\""
        command_line = "diff -a --suppress-common-lines " + file_1 + " " + file_2 + " " + grep_out + " > " + temp_file
        os.system(command_line)
        len_diff = len(read_file(temp_file))
        len_1 = len(read_file(file_1))
        self.len_in = len_1
        len_2 = len(read_file(file_2))
        self.len_out = len_2
        self.len_diff = len_diff
        result = (len_diff / (len_1 + len_2))
        return (result)

    def test_crypt(self):
        self.cry_sim = self.similarity_test(self.msg, self.cypher)
        if self.cry_sim > 0.75:
            self.correct_crypt = True
        else:
            self.correct_crypt = False
        #print("\nRESULT: ", "DIFF", self.diff_len, " -- ", "ORIG ", self.orig_len, " -------> ", correctness, "%")

    def test_decrypt(self):
        self.decry_sim = self.similarity_test(self.msg, self.uncrypted)
        if self.decry_sim == 0:
            self.correct_decrypt = True
        else:
            self.correct_decrypt = False

    def investigate(self):
        diff(self.msg, self.cypher, 0)
        self.display_time(crypt=True)
        diff(self.msg, self.uncrypted, 0)
        self.display_time(crypt=False)

    def one_round(self):
        self.new_test()
        columns = shutil.get_terminal_size().columns
        print("\n\n\n\t", BOLD, UNDERLINE, "Test n*", self.tests_to_do, RESET)
        #Crypt
        self.time_took_cry, self.cmd_cry = execute(self.msg, self.key, self.cypher, self.cycles, crypt=True)
        self.test_crypt()
        self.display(crypt=True)

        #Uncrypt
        self.time_took_decry, self.cmd_decry = execute(self.cypher, self.key, self.uncrypted, self.cycles, crypt=False)
        self.test_decrypt()
        self.display(crypt=False)
        if self.correct_decrypt == False or self.correct_crypt == False:
            self.investigate()
        self.tests_to_do -= 1

    def display_time(self, crypt=True):
        if crypt:
            print("Need more details ? Feel free to copy next line")
            print("cat -e ", self.msg, " && ", "cat -e ", self.cypher)
            print("\n\n\n")
        else:
            print("Need more details ? Feel free to copy next line")
            print("cat -e ", self.msg, " && ", "cat -e ", self.uncrypted)
            print("\n\n\n")

    def display(self, crypt = True):
        columns = shutil.get_terminal_size().columns
        n = 10
        if crypt:
            print(PURPLE, ("=" * n) + " " * 5 + "CRYPT" + " " * 5 + ("=" * n))
            print(PURPLE, "Message    ", RED, self.msg) 
            print(PURPLE, "Key        ", RED, self.key)
            print(PURPLE, "Cycles       ", YELLOW, self.cycles)
            print(PURPLE, "to file    ", GREEN, self.cypher, RESET)
            print(PURPLE, "Command    ", RESET, self.cmd_cry)
            print(PURPLE, "Time         ", RESET, str(self.time_took_cry)[0:5], end="")
            print(PURPLE, "\tTime cycle ", RESET, str((self.time_took_cry) / self.cycles)[0:7], RESET)
            print(PURPLE, "               Len original   ", self.len_in)
            print(PURPLE, "               Len out crypto ", self.len_out)
            print(PURPLE, "               Len diff       ", self.len_diff)
            print(PURPLE, "File difference       ", (self.cry_sim) // 0.01, "%")
            if self.correct_crypt == False:
                print(RED,"\tFAILURE", RESET)
            else:
                print(GREEN, "\tSUCCESS", RESET)
        else:
            print(BLUE, ("=" * n)  + " " * 4 + "UNCRYPT"  + " " * 4 + ("=" * n))
            print(BLUE, "Message    ", RED, self.cypher)
            print(BLUE, "Key        ", RED, self.key)
            print(BLUE, "Cycles       ", YELLOW, self.cycles)
            print(BLUE, "to file    ", GREEN, self.uncrypted, RESET)
            print(BLUE, "Command    ", RESET, self.cmd_decry)
            print(BLUE, "Time         ", RESET, str(self.time_took_decry)[0:5], end="")
            print(BLUE, "\tTime cycle ", RESET, str((self.time_took_decry) / self.cycles)[0:7], RESET)
            print(BLUE,"               Len original   ", self.len_in)
            print(BLUE,"               Len out crypto ", self.len_out)
            print(BLUE,"               Len diff       ", self.len_diff)
            print(BLUE, "File difference       ", (self.decry_sim) // 0.01, "%")
            if self.correct_decrypt == False:
                print(RED,"\tFAILURE", RESET)
            else:
                print(GREEN, "\tSUCCESS", RESET)
        #print("")

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
    while testor.tests_to_do:
        testor.one_round()


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




