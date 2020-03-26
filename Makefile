# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2020/03/08 21:04:39 by ezalos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include init.mk

CC 		= gcc
AR		= ar -rcs

##########################
##						##
##	   ARCHITECTURE		##
##						##
##########################

MAIN_FOLD 	=	$(shell find srcs -maxdepth 1 -type d | grep '/' | cut -d '/' -f 2)
MASTER		= 	srcs/

$(shell mkdir -p $(MASTER))

AUTO_HEAD	=	$(MAIN_FOLD:%=auto/auto_%.h)

HEAD		=	$(HEADERS:%=$(HEAD_DIR)%)

mk			=	./.makegenius/mk_dependencies
mk_p		= 	$(mk)/PAT/
include_pat	=	$(MAIN_FOLD:%=$(mk_p)pat_%.mk)
include_pat	+=	$(mk_p)pat_.mk
include_dep	=	$(include_pat)

PAT =

$(shell mkdir -p $(mk) $(mk_p))
$(shell touch $(include_dep))
FETCH_MODULES	=	$(shell grep "url" .gitmodules | cut -d '=' -f 2)
UNAME			:=	$(shell uname)
GIT_MODULES 	= $(FETCH_MODULES:%=git clone % ; )

include $(include_dep)

OBJ 	= $(PAT:%.c=%.o)
OBJS	= $(PAT:$(MASTER)%.c=$(DIR_OBJ)%.o)

ARG 	?= ldevelle
MSG		?= "Automated commit message!"

##########################
##						##
##	   SRCS/PROTOS		##
##						##
##########################

ifeq ($(UNAME),Linux)
update_head	=	$(MAIN_FOLD:%=sh .makegenius/scripts/get_protos_linux.sh % $(MASTER);)
update_head	+=	sh .makegenius/scripts/get_protos.sh '' $(MASTER) '' $(NAME);
update_dep	=	$(MAIN_FOLD:%=sh .makegenius/scripts/get_mk_srcs.sh % $(MASTER);)
update_dep	+=	sh .makegenius/scripts/get_mk_srcs.sh '' $(MASTER) '' '-depth 1';
else
update_head	=	$(MAIN_FOLD:%=sh .makegenius/scripts/get_protos.sh % $(MASTER);)
update_head	+=	sh .makegenius/scripts/get_protos.sh '' $(MASTER) '' $(NAME);
update_dep	=	$(MAIN_FOLD:%=sh .makegenius/scripts/get_mk_srcs.sh % $(MASTER);)
update_dep	+=	sh .makegenius/scripts/get_mk_srcs.sh '' $(MASTER) '' '-d 1';
endif

##########################
##						##
##		 FLAGS			##
##						##
##########################

ifeq ($(f), no)
CFLAGS 		+=
VALGRIND 	=
else ifeq ($(f), n)
CFLAGS 		=
VALGRIND 	=
else ifeq ($(f), f)
CFLAGS 		+=  -fsanitize=address,undefined -g3
VALGRIND 	=
else ifeq ($(f), v)
CFLAGS 		+= -g3
SHOW_LEAK 	= --show-leak-kinds=definite
VALGRIND 	= valgrind --track-origins=yes --leak-check=full $(SHOW_LEAK)
else ifeq ($(f), h)
CFLAGS 		= -fsanitize=address,undefined -g3 -pedantic\
-ansi -O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int\
-Werror-implicit-function-declaration -Wmain -Wparentheses -Wsequence-point\
-Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas\
-Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast\
-Wwrite-strings -Wconversion -Wsign-compare -Waggregate-return\
-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations\
-Wmissing-noreturn -Wformat -Wmissing-format-attribute\
-Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs\
-Winline -Wlong-long -Wunreachable-code
VALGRIND 	=
endif

##########################
##						##
##		 COLORS			##
##						##
##########################
ifeq ($(UNAME),Linux)
RED     	= \e[31m
GREEN   	= \e[32m
YELLOW  	= \e[33m
BLUE		= \e[34m
MAGENTA		= \e[35m
CYAN		= \e[36m
END     	= \e[0m
else
RED     	= \x1b[31m
GREEN   	= \x1b[32m
YELLOW  	= \x1b[33m
BLUE		= \x1b[34m
MAGENTA		= \x1b[35m
CYAN		= \x1b[36m
END     	= \x1b[0m
endif

COM_COLOR   = $(BLUE)
OBJ_COLOR   = $(CYAN)
OK_COLOR    = $(GREEN)
ERROR_COLOR = $(RED)
WARN_COLOR  = $(YELLOW)
NO_COLOR    = $(END)

OK_STRING    	= [OK]
ERROR_STRING 	= [ERROR]
WARN_STRING  	= [WARNING]
COM_STRING   	= Compiling

##########################
##						##
##		 OUTPUT			##
##						##
##########################

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

##############################################################################
##############################################################################
##																			##
##									-----									##
##									RULES									##
##									-----									##
##																			##
##############################################################################
##############################################################################

##########################
##						##
##		  BASIC			##
##						##
##########################

all :	$(modules) $(NAME) auteur $(DIR_OBJ)

ifeq ($(LIB_PRJCT), y)
$(NAME):	$(OBJS) $(HEAD_DIR)
	$(call run_and_test, $(AR) $(NAME) $(OBJS))
else
$(NAME):	$(LIB) $(OBJS) $(HEAD_DIR)
	$(call run_and_test, $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB) $(HEADERS_DIRECTORIES))
endif

$(DIR_OBJ)%.o:$(MASTER)%.c $(HEAD) Makefile
	mkdir -p $(DIR_OBJ)
	$(call run_and_test, $(CC) $(CFLAGS) $(HEADERS_DIRECTORIES) -o $@ -c $<)

$(LIB): FORCE
		$(MAKE) -C $(LIB_DIR)

clean :
	rm -f $(OBJS)
	echo "\$(YELLOW)$(NAME) objs \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"

fclean : clean
	rm -rf $(NAME) $(DIR_OBJ)
	echo "\$(YELLOW)$(NAME) \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"

re : fclean
	$(MAKE) all

rere :
	$(MAKE) re -C $(LIB_DIR)
	$(MAKE) re


auteur : Makefile
		echo $(login) > auteur

$(DIR_OBJ) :
		mkdir -p $(DIR_OBJ)

##########################
##						##
##		 RUN IT			##
##						##
##########################

t	:	all
		$(CC) $(CFLAGS) -I$(HEAD_DIR) $(NAME) main.c -o $(TESTEUR)
		$(VALGRIND) ./$(TESTEUR) "$(ARG)"

run	:	all
		$(VALGRIND) ./$(NAME) "$(ARG)"

unit_test :

big :
n_times ?= 100
n_times=$(n_times); \
while [ $${n_times} -gt 0 ] ; do \
    $(MAKE) unit_test \
done; \
true

##########################
##						##
##		  GIT			##
##						##
##########################

init:
		sh ./.makegenius/scripts/init_makegenius.sh
		echo -n "Do you wish to puh your project on github ?" && read ans && [ $${ans:-N} = y ]
		$(MAKE) init_git

init_git:
		rm -rf .git
		echo "# $(NAME)" > README.md
		git init
		git add -A
		git commit -m "first commit"
		git remote add origin $(GIT_REPO)
		git push -u origin master


REQUEST 		= 'read -p "Enter a commit message:	" pwd && echo $$pwd'
COMMIT_MESSAGE ?= $(shell bash -c $(REQUEST))
# $(GIT_VALID) || (echo -n "Are you sure? [y/N] " && read ans && [ $${ans:-N} = y ])
git :
		git add -A
		git status
		$(GIT_VALID) || (echo -n "Are you sure? [y/N] " && read ans && [ $${ans:-N} = y ])
		git commit -m "$(COMMIT_MESSAGE)"
		git push

modules :
		$(GIT_MODULES)

##########################
##						##
##	    AUTOMATE		##
##						##
##########################

file : 	sources prototypes
		$(MAKE)

sources :	object_ready
		rm -rf $(mk_p)
		mkdir -p $(mk_p)
		echo $(update_dep)
		$(update_dep)
		echo "\$(YELLOW)automatic sources\$(END)\\thas been \$(GREEN)\\t\\t  created\$(END)"

DIR_PREP = $(shell find $(MASTER) -type d -exec echo {} \; | sed 's~$(MASTER)~$(DIR_OBJ)~g')
object_ready :	$(DIR_OBJ)
		rm -rf $(DIR_OBJ)/*
		mkdir -p $(DIR_PREP)
		find $(DIR_OBJ) -type d -exec touch {}/.gitkeep \;
		echo "\$(YELLOW)objects paths\$(END)\\t\\thas been \$(GREEN)\\t\\t  created\$(END)"

prototypes :	auto_dir
		$(update_head)
		sh .makegenius/scripts/get_master_head.sh $(HEAD_DIR) $(NAME)
		echo "\$(YELLOW)automatic headers\$(END)\\thas been \$(GREEN)\\t\\t  created\$(END)"

auto_dir :
		mkdir -p $(HEAD_DIR)auto

##########################
##						##
##		  SELF			##
##						##
##########################

makegenius_repository=https://github.com/ezalos/Makegenius.git
temp_folder=.tmp_makegenius_update/

update :
		rm -rf $(temp_folder)
		git clone $(makegenius_repository) $(temp_folder)
		bash "$(temp_folder).makegenius/scripts/update_makegenius.sh" $(temp_folder) &

rm_update_tmp_dir:
		rm -rf $(temp_folder)

##########################
##						##
##		 PARAMS			##
##						##
##########################

FORCE:
.PHONY	:	all clean fclean re git file object_ready check update\
			rm_update_tmp_dir auto_dir prototypes sources modules\
			rere auteur run unit_test big init init_git FORCE
.SILENT	:
