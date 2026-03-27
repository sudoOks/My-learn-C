CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

TEST_DIR = test

NAME_STRLEN = $(TEST_DIR)/Task_1
NAME_STRCMP = $(TEST_DIR)/Task_2
NAME_STRCPY = $(TEST_DIR)/Task_3
NAME_STRCAT = $(TEST_DIR)/Task_4

.PHONY: strlen_tests strcmp_tests strcpy_tests strcat_tests clean rebuild

$(TEST_DIR):
	mkdir -p $(TEST_DIR)

strlen_tests: $(TEST_DIR)
	$(CC) $(CFLAGS) -DSTRCMP_TEST -DSTRCPY_TEST -DSTRCAT_TEST my_string.c my_string_test.c -o $(NAME_STRLEN)

strcmp_tests: $(TEST_DIR)
	$(CC) $(CFLAGS) -DSTRLEN_TEST -DSTRCPY_TEST -DSTRCAT_TEST my_string.c my_string_test.c -o $(NAME_STRCMP)

strcpy_tests: $(TEST_DIR)
	$(CC) $(CFLAGS) -DSTRLEN_TEST -DSTRCMP_TEST -DSTRCAT_TEST my_string.c my_string_test.c -o $(NAME_STRCPY)

strcat_tests: $(TEST_DIR)
	$(CC) $(CFLAGS) -DSTRLEN_TEST -DSTRCMP_TEST -DSTRCPY_TEST my_string.c my_string_test.c -o $(NAME_STRCAT)

clean:
	rm -rf $(TEST_DIR)

rebuild: clean strlen_tests strcmp_tests strcpy_tests strcat_tests

