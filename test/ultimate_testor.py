from os import listdir
from os.path import isfile, join
from os import walk
import os
import time
import random
from color import *
import shutil

import argparse


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






class Testor():
    def __init__(self):
        self.max_len = -1
        self.cycles_user = None
        self.directory = os.sys.argv[0][0:-len("ultimate_testor.py")]
        self.path_to_tests = self.directory + "unit_test"
        self.path_to_crypt = self.directory + "crypted/"
        self.path_to_uncrypt = self.directory + "uncrypted/"
        self.temp_file = self.directory + "tmp_diff"
        self.temp_file_2 = self.directory + "tmp_diff_2"
        self.fsanitize = False
        self.tests_done = 0
        self.parser()
        self.reset_folders()
        
    def parser(self):
        parser = argparse.ArgumentParser(
                    description='Process arguments for testor of cypher C library')
        parser.add_argument("-p", "--project", type=str, default="Feistel",
                    help="Choose which crypto to test")
        parser.add_argument("-v", "--verbosity", type=int, default=3,
                    help="increase output verbosity [0-3]")
        parser.add_argument("-r", "--random", type=int, default=None,
                    help="number of random test")
        parser.add_argument("-f", "--user_files", type=str, nargs=2,
                    help="user specified msg and key")
        parser.add_argument("-o", "--folder", type=str,
                    help="user specified unit_test folder")
        parser.add_argument("-c", "--cycles", type=int,
                    help="nb of feistel cycles (default random)")
        parser.add_argument("-s", "--stop", action='store_true',
                    help="stop after each test")
        parser.add_argument("-fs", "--fsanitize", action='store_true',
                    help="remake libft and crypto with fsanitize on")
        args = parser.parse_args()
        
        if args.folder:
            self.path_to_tests = args.folder
        
        if args.random:
            self.select = "RANDOM"
            self.tests_to_do = args.random
        elif args.user_files:
            self.select = "USER_FILES"
            self.file_msg = args.user_files[0]
            self.file_key = args.user_files[1]
            self.tests_to_do = 1
        else:
            self.select = "ALL_COMBINAISONS"
            self.get_list_of_files()
            self.tests_to_do = (len(self.list_of_files) * len(self.list_of_files)) - 1
        self.verbosity = args.verbosity
        if args.cycles:
            self.cycles_user = args.cycles
        if args.fsanitize:
            self.fsanitize = True
        if args.stop:
            self.stop = True
        else:
            self.stop = False
        #args.verbosity

    def make_file_path(self, add_folders=True):
        self.file_crypto = self.file_msg.split("/")[-1] + "_" + self.file_key.split("/")[-1]
        self.msg = self.file_msg
        self.key = self.file_key
        self.cypher = self.path_to_crypt + self.file_crypto
        self.uncrypted = self.path_to_uncrypt + self.file_crypto

    def new_test(self):
        self.select_msg_and_key()
        if self.cycles_user != None:
            self.cycles = self.cycles_user
        else:
            self.cycles = random.randint(0, 30)

    def next_file_combinaison(self):
        self.file_msg = self.list_of_files[self.tests_done // len(self.list_of_files)]
        self.file_key = self.list_of_files[self.tests_done % len(self.list_of_files)]
        
    def select_msg_and_key(self):
        if self.select == "ALL_COMBINAISONS":
            self.next_file_combinaison()
            self.make_file_path(add_folders=True)
        elif self.select == "RANDOM":
            len_rand = len(self.list_of_files) - 1
            choice = lambda x : random.randint(1, x)
            self.file_key = self.list_of_files[choice(len_rand)]
            self.file_msg = self.list_of_files[choice(len_rand)]
            self.make_file_path(add_folders=True)
        elif self.select == "USER_FILES":
            self.make_file_path(add_folders=False)

    def get_list_of_files(self):
        self.list_of_files = []
        for (dirpath, dirnames, filenames) in walk(self.path_to_tests):
            for file in filenames:
                if self.max_len < len(file):
                    self.max_len = len(file)
                new_entry = dirpath + "/" + file
                self.list_of_files.append(new_entry)
        self.max_len = (self.max_len * 2) + 1 + len(self.path_to_uncrypt)

    def similarity_test(self, file_1, file_2, crypt=True):
        grep_out = " | grep -av \"\\ No newline at end of file\""
        command_line = "diff -a --suppress-common-lines " + file_1 + " " + file_2 + " " + grep_out + " > " + self.temp_file
        os.system(command_line)
        len_diff = len(read_file(self.temp_file))
        len_1 = len(read_file(file_1))
        len_2 = len(read_file(file_2))
        if crypt:
            self.len_in_cry = len_1
            self.len_out_cry = len_2
            self.len_diff_cry = len_diff
        else:
            self.len_in_decry = len_1
            self.len_out_decry = len_2
            self.len_diff_decry = len_diff
        result = (len_diff / (len_1 + len_2))
        return (result)

    def test_crypt(self, crypt=True):
        self.cry_sim = self.similarity_test(self.msg, self.cypher, crypt)
        if self.cry_sim >= 1:
            self.correct_crypt = True
        else:
            self.correct_crypt = False
        #print("\nRESULT: ", "DIFF", self.diff_len, " -- ", "ORIG ", self.orig_len, " -------> ", correctness, "%")

    def test_decrypt(self, crypt=True):
        self.decry_sim = self.similarity_test(self.msg, self.uncrypted, crypt)
        if self.decry_sim == 0:
            self.correct_decrypt = True
        else:
            self.correct_decrypt = False

    def select_a_file(self, files):
        for i in range(len(files)):
            print(i, " -> ", files[i][1], RESET, files[i][0])
        while True:
            num = input()
            try:
                num = int(num)
                if num >= 0 and num < len(files):
                    return files[num][0]
                else:
                    print("Choice must be between 0 and ", len(files) - 1, "\nYours is ", num)
            except:
                print("Please choose a number")
                num = None

    def diff_hexdump(self, file_1, file_2):
        cmd = "hexdump -C " + file_1 + " > " + self.temp_file
        cmd_1 = "hexdump -C " + file_2 + " > " + self.temp_file_2
        print(cmd)
        print(cmd_1)
        os.system(cmd)
        os.system(cmd_1)
        diff(self.temp_file, self.temp_file_2, 0)

    def investigate(self):
        files = [[self.msg, RED +         "Plaintext "],
                 [self.key, YELLOW +      "Key       "],
                 [self.cypher, PURPLE +   "Crypted   "],
                 [self.uncrypted, BLUE +  "Uncrypted "]]
        while True:
            mode = "?"
            print("Would you like to :")
            print("\t" + BOLD + UNDERLINE + RED + "c" + RESET + "at a file") 
            print("\t" + BOLD + UNDERLINE + RED + "h" + RESET + "exdump a file ?")
            print("\t" + BOLD + UNDERLINE + RED + "d" + RESET + "iff 2 files ?")
            print("\t" + BOLD + UNDERLINE + RED + "s" + RESET + "how testor data ?")
            print("\t" + BOLD + UNDERLINE + RED + "l" + RESET + "uigi diff (obviously the best) ?")
            print("\tPress " + BOLD + UNDERLINE + RED + "Enter" + RESET + " to exit")
            mode = input()
            if mode == "":
                break
            elif mode == "h":
                file_1 = self.select_a_file(files)
                cmd = "hexdump -C " + file_1
                print(cmd)
                os.system(cmd)
            elif mode == "c":
                file_1 = self.select_a_file(files)
                cmd = "cat " + file_1
                print(cmd)
                os.system(cmd)
            elif mode == "l":
                print("Please choose first  file for diff")
                file_1 = self.select_a_file(files)
                print("Please choose second file for diff")
                file_2 = self.select_a_file(files)
                self.diff_hexdump(file_1, file_2)
            elif mode == "d":
                print("Please choose first  file for diff")
                file_1 = self.select_a_file(files)
                print("Please choose second file for diff")
                file_2 = self.select_a_file(files)
                diff(file_1, file_2, 0)
            elif mode == "s":
                self.display(crypt=True)
                self.display(crypt=False)
            else:
                print("I don't understand: ", mode)

    def one_round(self):
        self.new_test()
        columns = shutil.get_terminal_size().columns
        if self.verbosity > 0:
            print("\n\t")
        print(BOLD, UNDERLINE, "Test n*", self.tests_done, "/", self.tests_to_do, RESET)
        #Crypt
        self.time_took_cry, self.cmd_cry = execute(self.msg, self.key, self.cypher, self.cycles, crypt=True)
        self.test_crypt(crypt=True)

        #Uncrypt
        self.time_took_decry, self.cmd_decry = execute(self.cypher, self.key, self.uncrypted, self.cycles, crypt=False)
        self.test_decrypt(crypt=False)
        self.display(crypt=True)
        self.display(crypt=False)
        if self.correct_decrypt == False or self.correct_crypt == False or self.stop:
            self.investigate()
        self.tests_done += 1

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
            COLOR = PURPLE
        else:
            COLOR = BLUE
        tmp_verb = self.verbosity
        if self.correct_decrypt == False or self.correct_crypt == False:
            self.verbosity = 5
        if self.verbosity > 0:
            if crypt:
                print(COLOR, ("=" * n) + " " * 5 + "CRYPT" + " " * 5 + ("=" * n))
            else:
                print(COLOR, ("=" * n)  + " " * 4 + "UNCRYPT"  + " " * 4 + ("=" * n))
        if self.verbosity > 0:
            if crypt:
                print(COLOR, "Message    ", RED, self.msg) 
            else:
                print(COLOR, "Message    ", RED, self.cypher)
            print(COLOR, "Key        ", RED, self.key)
        if self.verbosity > 0:
            print(COLOR, "Cycles       ", YELLOW, self.cycles)
        if self.verbosity > 2:
            if crypt:
                print(COLOR, "to file    ", RESET, self.cypher, RESET)
            else:
                print(COLOR, "to file    ", RESET, self.uncrypted, RESET)
            if crypt:
                print(COLOR, "Command    ", RESET, self.cmd_cry)
            else:
                print(COLOR, "Command    ", RESET, self.cmd_decry)
            if crypt:
                print(COLOR, "Time         ", RESET, str(self.time_took_cry)[0:5])
                if self.cycles:
                    print(COLOR, "Time cycle   ", RESET, str((self.time_took_cry) / self.cycles)[0:7], RESET)
            else:
                print(COLOR, "Time         ", RESET, str(self.time_took_decry)[0:5])
                if self.cycles:
                    print(COLOR, "Time cycle   ", RESET, str((self.time_took_decry) / self.cycles)[0:7], RESET)
        if self.verbosity > 1:
            if crypt:
                print(COLOR, "               Len plaintext  ", self.len_in_cry)
                print(COLOR, "               Len output     ", self.len_out_cry)
                print(COLOR, "               Len diff       ", self.len_diff_cry)
            else:
                print(COLOR, "               Len plaintext  ", self.len_in_decry)
                print(COLOR, "               Len output     ", self.len_out_decry)
                print(COLOR, "               Len diff       ", self.len_diff_decry)
            if crypt:
                print(COLOR, "File difference       ", (self.cry_sim) // 0.01, "%")
            else:
                print(COLOR, "File difference       ", (self.decry_sim) // 0.01, "%")
        if crypt:
            if self.correct_crypt == False:
                print(RED,"FAILURE", RESET)
            else:
                print(GREEN, "SUCCESS", RESET)
        else:
            if self.correct_decrypt == False:
                print(RED,"FAILURE", RESET)
            else:
                print(GREEN, "SUCCESS", RESET)
        self.verbosity = tmp_verb

    def reset_folders(self):
        os.system("rm -rf " + self.path_to_crypt)
        os.system("mkdir -p " + self.path_to_crypt)
        print("Cypher    folder has been reset !")
        os.system("rm -rf " + self.path_to_uncrypt)
        os.system("mkdir -p " + self.path_to_uncrypt)
        print("Uncrypted folder has been reset !")
        if self.fsanitize == True:
            os.system("make re debug=1 -C libft -j8")
            os.system("make re f=f -j8")
        else:
            os.system("make")


if __name__ == "__main__":
    testor = Testor()
    while testor.tests_done < testor.tests_to_do:
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




