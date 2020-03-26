make debug=1 -j8 && gcc -g3 -fsanitize=address,undefined main_test/main_hash.c libft.a -I./includes && ./a.out
