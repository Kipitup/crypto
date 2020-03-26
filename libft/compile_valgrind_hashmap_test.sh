make debug=0 -j8 && gcc -g3 main_test/main_hash.c libft.a -I./includes -o hash_valgrind && valgrind --track-origins=yes --leak-check=full --show-leak-kinds=definite,indirect ./hash_valgrind 
